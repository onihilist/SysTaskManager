//
// Created by onihilist on 22/09/2025.
//

#include "../includes/QueueManager.hpp"
#include "../includes/TaskInfo.hpp"

bool addTaskToQueue(TaskInfo task) {
    try {
        QueueManager().getTaskQueue().push(task);
        return true;
    } catch (exception& e) {
        std::cout << e.what() << std::endl;
        return false;
    }
};

bool removeTaskFromQueue() {
    try {
        QueueManager().getTaskQueue().pop();
        return true;
    } catch (exception& e) {
        std::cout << e.what() << std::endl;
        return false;
    }
};
