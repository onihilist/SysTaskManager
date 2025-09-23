//
// Created by onihilist on 22/09/2025.
//

#ifndef RECURRENCEPARSER_HPP
#define RECURRENCEPARSER_HPP
#include <ctime>
#include <string>

#include "TaskInfo.hpp"

class RecurrenceParser {
    public:
        static time_t triggerDateTime;
        static time_t parseDateTime(Recurrency& recurrency);
};

#endif //RECURRENCEPARSER_HPP
