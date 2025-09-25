
#ifndef QUEUEMANAGER_HPP
#define QUEUEMANAGER_HPP

#include <queue>
#include <memory>
#include "TaskInfo.hpp"

class QueueManager {
private:
    std::queue<std::shared_ptr<TaskInfo>> taskQueue;

public:
    QueueManager() = default;
    ~QueueManager() = default;

    bool addTaskToQueue(std::shared_ptr<TaskInfo> task);
    bool removeTaskFromQueue();

    std::queue<std::shared_ptr<TaskInfo>>& getTaskQueue() { return taskQueue; }
};

#endif // QUEUEMANAGER_HPP
