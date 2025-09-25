
#include "../includes/TaskRunner.hpp"
#include <chrono>
#include <iostream>
#include <vector>

TaskRunner::TaskRunner() : running(false) {
    std::cout << "TaskRunner constructed" << std::endl;
}

TaskRunner::~TaskRunner() {
    stop();
    std::cout << "TaskRunner destroyed" << std::endl;
}

void TaskRunner::start(QueueManager &queueManager) {
    running = true;

    schedulerThread = std::thread([&queueManager, this]() {
        std::vector<std::thread> activeThreads;

        while (running) {
            auto &queue = queueManager.getTaskQueue();

            size_t queueSize = queue.size();
            for (size_t i = 0; i < queueSize; ++i) {
                auto taskPtr = queue.front();
                queue.pop();

                std::time_t now = std::time(nullptr);

                if (taskPtr->getRecurrency().getDatetimeForAction() <= now) {
                    activeThreads.emplace_back([taskPtr]() {
                        taskPtr->setThreadId(std::this_thread::get_id());
                        std::cout << "Thread (tID: " << std::this_thread::get_id()
                                  << ") is running task " << taskPtr->getName() << "..." << std::endl;
                    });
                } else {
                    queue.push(taskPtr);
                }
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        for (auto &t : activeThreads) {
            if (t.joinable())
                t.join();
        }
    });
}

void TaskRunner::stop() {
    running = false;
    if (schedulerThread.joinable())
        schedulerThread.join();
}
