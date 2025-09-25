
#include "includes/TaskInfo.hpp"
#include "includes/TaskRunner.hpp"
#include "includes/QueueManager.hpp"

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
        0, 0, 0, 15,
        queueManager);

    taskRunner.start(queueManager);

    std::this_thread::sleep_for(std::chrono::months(1));

    taskRunner.stop();

    std::cout << "All tasks finished!" << std::endl;
    return 0;
}
