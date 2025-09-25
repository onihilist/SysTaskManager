//
// Created by onihilist on 22/09/2025.
//

#include "../includes/TaskInfo.hpp"
#include <iostream>
#include <thread>

#include "../includes/QueueManager.hpp"

bool TaskInfo::createTask(
    const std::string &type,
    const std::string &name,
    const std::string &command,
    const int days,
    const int hours,
    const int minutes,
    const int seconds,
    QueueManager &queueManager)
{
    const std::time_t currentTime = time(nullptr);
    const std::time_t timeToExec = currentTime +
                                   days*24*3600 +
                                   hours*3600 +
                                   minutes*60 +
                                   seconds;

    try {
        TaskInfo task(
            0,
            std::thread::id(),
            name,
            "",
            Recurrency{ type, timeToExec, {""}, {""} },
            "high",
            "null",
            "null",
            command
        );

        return queueManager.addTaskToQueue(std::move(task));
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return false;
    }
}

