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
                        days*24*3600
                      + hours*3600
                      + minutes*60
                      + seconds;

    TaskInfo testTask(
        0,
        std::thread::id(0),
        name,
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
        command
    );

    return testTask;
}
