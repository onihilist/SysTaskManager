//
// Created by onihilist on 23/09/2025.
//

#include "../includes/QueueManager.hpp"
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

std::thread TaskRunner::run(QueueManager &qm) {
    TaskInfo task = qm.getTaskQueue().front();
    std::string name = qm.getTaskQueue().front().getName();
    std::time_t scheduled = qm.getTaskQueue().front().getRecurrency().getDatetimeForAction();

    std::thread t([&task, scheduled] {
        if (const std::time_t now = std::time(nullptr); scheduled > now) {
            std::this_thread::sleep_for(std::chrono::seconds(scheduled - now));
        }

        task.setThreadId(std::this_thread::get_id());
        std::cout << "Thread (tID: " << std::this_thread::get_id()
                  << ") is running task " << task.getName() << "..." << std::endl;
    });

    return t;
}

bool TaskRunner::isTimeToRun(TaskInfo &task, QueueManager &qm) {
    const std::time_t now = std::time(nullptr);

    if (const std::time_t scheduled = task.getRecurrency().getDatetimeForAction(); now >= scheduled) {
        run(qm).detach();
        return true;
    } else {
        std::cout << "Thread (tID: " << task.getThreadId()
                  << ") will run task \"" << task.getName()
                  << "\" in " << scheduled - now << " seconds\n";
        return false;
    }
}
