#include "../includes/TaskInfo.hpp"
#include <iostream>
#include <thread>

TaskInfo TaskInfo::createTestTask() {
    std::thread t([]() {
        std::cout << "printMessage is running" << std::endl;
    });

    TaskInfo testTask(
        0,
        t.get_id(),
        "nameTest",
        "",
        "daily[2:35PM]",
        "high",
        "null",
        "null",
        "null",
        "null"
    );

    t.join();

    return testTask;
}
