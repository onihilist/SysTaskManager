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
    std::string name = task.getName();
    std::time_t scheduled = task.getRecurrency().getDatetimeForAction();

    std::thread t([name, &task, scheduled] {
        if (const std::time_t now = std::time(nullptr); scheduled > now) {
            std::this_thread::sleep_for(std::chrono::seconds(scheduled - now));
        }

        task.setThreadId(std::this_thread::get_id());
        std::cout << "Thread (tID: " << std::this_thread::get_id()
                  << ") is running task " << name << "..." << std::endl;
    });

    return t;
}

bool TaskRunner::isTimeToRun(TaskInfo &task) {
    const std::time_t now = std::time(nullptr);

    if (const std::time_t scheduled = task.getRecurrency().getDatetimeForAction(); now >= scheduled) {
        run(task).detach();
        return true;
    } else {
        std::cout << "Thread (tID: " << task.getThreadId()
                  << ") will run task \"" << task.getName()
                  << "\" in " << scheduled - now << " seconds\n";
        return false;
    }
}
