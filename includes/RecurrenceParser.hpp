//
// Created by onihilist on 22/09/2025.
//

#ifndef RECURRENCEPARSER_HPP
#define RECURRENCEPARSER_HPP
#include <ctime>
#include <string>

class RecurrenceParser {
    public:
        static time_t triggerDateTime;
        static time_t parseDateTime(const std::string& datetime);
};

#endif //RECURRENCEPARSER_HPP
