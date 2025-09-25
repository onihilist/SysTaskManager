#include "../includes/QueueManager.hpp"
#include "../includes/TaskInfo.hpp"
#include <iostream>

QueueManager::QueueManager() {}
QueueManager::~QueueManager() {}

bool QueueManager::addTaskToQueue(TaskInfo&& task) {
    try {
        taskQueue.push(std::move(task));
        return true;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return false;
    }
}

bool QueueManager::removeTaskFromQueue() {
    try {
        if (!taskQueue.empty()) {
            taskQueue.pop();
            return true;
        }
        return false;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return false;
    }
}
