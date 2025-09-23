#include <iostream>

#include "includes/RecurrenceParser.hpp"
#include "includes/TaskInfo.hpp"

int main() {

    TaskInfo task = TaskInfo::createTestTask(
       "immediate", 0, 2, 0, 0);
    RecurrenceParser::parseDateTime(
        task.getRecurrency());

    return 0;
}
