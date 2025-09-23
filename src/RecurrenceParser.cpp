//
// Created by onihilist on 22/09/2025.
//

#include "../includes/RecurrenceParser.hpp"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>

time_t RecurrenceParser::parseDateTime(const std::string& datetime) {
    const std::string delimiter = "[";

    std::string type = datetime.substr(0, datetime.find(delimiter));
    std::ranges::transform(type, type.begin(), ::tolower);

    std::string timeStr = datetime.substr(datetime.find('[') + 1);
    timeStr = timeStr.substr(0, timeStr.find(']'));

    if (type == "immediate") {
        std::cout << "Schedule type: " << type << std::endl;
    } else if (type == "delayed") {
        std::cout << "Schedule type: " << type << std::endl;
        std::cout << "Time: " << timeStr << std::endl;
    } else if (type == "recurring") {
        std::cout << "Schedule type: " << type << std::endl;
        std::cout << "Time: " << timeStr << std::endl;
    } else {

    }

    return time(nullptr);
}
