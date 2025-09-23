//
// Created by onihilist on 22/09/2025.
//

#include "../includes/RecurrenceParser.hpp"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>

#include "../includes/TaskInfo.hpp"

time_t RecurrenceParser::parseDateTime(Recurrency& recurrency) {

    if (recurrency.getType() == "immediate") {
        std::cout << "Schedule type: " << recurrency.getType() << std::endl;
    } else if (recurrency.getType() == "delayed") {
        std::cout << "Schedule type: " << recurrency.getType() << std::endl;
        std::cout << "Time: " << recurrency.getTimeForAction()[0] << std::endl;
    } else if (recurrency.getType() == "recurring") {
        std::cout << "Schedule type: " << recurrency.getType() << std::endl;
        std::cout << "Time: " << recurrency.getTimeForAction()[0] << std::endl;
    } else {
        std::cout << "Recurrency is not valid !" << std::endl;
    }

    return time(nullptr);
}
