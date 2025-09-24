//
// Created by onihilist on 23/09/2025.
//

#include "../includes/TaskRunner.hpp"
#include "../includes/TaskInfo.hpp"
#include <iostream>
#include <thread>
#include <mutex>

TaskRunner::TaskRunner() {
    std::cout << "TaskRunner constructed" << std::endl;
}

TaskRunner::~TaskRunner() {
    std::cout << "TaskRunner destroyed" << std::endl;
}

std::thread TaskRunner::run(TaskInfo &task) {

    std::mutex mtx;
    std::string name = task.getName();;

    mtx.unlock();

    std::thread t([name, &t, &task] {
        task.setThreadId(t.get_id());
        std::cout << "Thread (tID: " << t.get_id() << ") is running task " << name << "..." << std::endl;
    });
    t.join();

    return t;
};