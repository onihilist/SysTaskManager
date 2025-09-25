
#include "../includes/QueueManager.hpp"
#include <iostream>

bool QueueManager::addTaskToQueue(std::shared_ptr<TaskInfo> task) {
    try {
        taskQueue.push(task);
        return true;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return false;
    }
}

bool QueueManager::removeTaskFromQueue() {
    if (!taskQueue.empty()) {
        taskQueue.pop();
        return true;
    }
    return false;
}
