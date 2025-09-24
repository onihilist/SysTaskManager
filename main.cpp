#include <iostream>

#include "includes/RecurrenceParser.hpp"
#include "includes/TaskInfo.hpp"
#include "includes/TaskRunner.hpp"

int main() {
    TaskRunner taskRunner;
    TaskInfo task = TaskInfo::createTask(
        "immediate",
        "InitTask",
        "ls",
        0, 0, 0, 5);
    TaskInfo task2 = TaskInfo::createTask(
        "immediate",
        "UnusedTask",
        "ls",
        0, 2, 0, 0);
    taskRunner.isTimeToRun(task);

    return 0;
}
