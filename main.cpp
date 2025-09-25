
#include "includes/TaskInfo.hpp"
#include "includes/TaskRunner.hpp"

int main() {
    QueueManager queueManager;
    TaskRunner taskRunner;

    TaskInfo::createTask(
        "immediate",
        "InitTask",
        "ls",
        0, 0, 0, 5,
        queueManager);
    TaskInfo::createTask(
        "immediate",
        "UnusedTask",
        "ls",
        0, 2, 0, 0,
        queueManager);

    std::thread t = taskRunner.run(queueManager);
    t.join();

    std::cout << "All tasks finished!" << std::endl;
    return 0;
}

