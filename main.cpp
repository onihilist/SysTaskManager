#include <iostream>

#include "includes/RecurrenceParser.hpp"
#include "includes/TaskInfo.hpp"

int main() {

    TaskInfo task = TaskInfo::createTestTask();
    RecurrenceParser::parseDateTime(task.getRecurrency().c_str());

    return 0;
}
