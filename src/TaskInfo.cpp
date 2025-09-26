
#include "../includes/TaskInfo.hpp"
#include "../includes/QueueManager.hpp"
#include <thread>
#include <exception>

bool TaskInfo::createTask(const std::string &type,
                          const std::string &name,
                          const std::string &command,
                          const int days,
                          const int hours,
                          const int minutes,
                          const int seconds,
                          QueueManager &queueManager) {
    const std::time_t now = std::time(nullptr);
    std::time_t scheduled = now
                            + days*24*3600
                            + hours*3600
                            + minutes*60
                            + seconds;

    try {
        const auto taskPtr = std::make_shared<TaskInfo>(
            0,
            std::thread::id(),
            name,
            "",
            Recurrency{type, scheduled, {""}, {""}},
            "high",
            "null",
            "null",
            command
        );

        return queueManager.addTaskToQueue(taskPtr);

    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return false;
    }
}
