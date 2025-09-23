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

    std::thread t([name]() {
        std::cout << name << " task is running" << std::endl;
    });

    TaskInfo testTask(
        0,
        t.get_id(),
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
        "null"
    );

    t.join();

    return testTask;
}
