#ifndef QUEUEMANAGER_HPP
#define QUEUEMANAGER_HPP

#include <queue>


class TaskInfo;

class QueueManager {
private:
    std::queue<TaskInfo> taskQueue;

public:
    QueueManager();
    ~QueueManager();

    bool addTaskToQueue(TaskInfo&& task);
    bool removeTaskFromQueue();

    std::queue<TaskInfo>& getTaskQueue() {
        return taskQueue;
    }
};

#endif // QUEUEMANAGER_HPP
