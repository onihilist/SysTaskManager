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
        0, 2, 0, 0);
    RecurrenceParser::parseDateTime(
        task.getRecurrency());
    thread t = taskRunner.run(task);

    return 0;
}
