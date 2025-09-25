
#ifndef TASKRUNNER_HPP
#define TASKRUNNER_HPP

#include "QueueManager.hpp"
#include "TaskInfo.hpp"
#include <thread>
#include <atomic>

class TaskRunner {
public:
    TaskRunner();
    ~TaskRunner();

    void start(QueueManager &queueManager);
    void stop();

private:
    std::thread schedulerThread;
    std::atomic<bool> running;
};

#endif // TASKRUNNER_HPP
