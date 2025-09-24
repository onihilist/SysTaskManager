#include "../includes/TaskInfo.hpp"
#include <iostream>
#include <thread>

TaskInfo TaskInfo::createTask(
    const std::string &type,
    const std::string &name,
    const std::string &command,
    const int days,
    const int hours,
    const int minutes,
    const int seconds) {

    const std::time_t currentTime = time(nullptr);
    const std::time_t timeToExec = currentTime +
        (days * hours * minutes * seconds);

    TaskInfo testTask(
        0,
        std::thread::id(0),
        "nameTest",
        "",
        Recurrency{
            type,
            timeToExec,
            {""},
            {""}
        },
        "high",
        "null",
        "null",
        "ls"
    );

    return testTask;
}
