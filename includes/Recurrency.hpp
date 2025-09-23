//
// Created by onihilist on 23/09/2025.
//

#ifndef RECURRENCY_HPP
#define RECURRENCY_HPP
#include <string>
#include <vector>

class Recurrency {
    private:
        time_t datetimeForAction;
        std::vector<std::string> daysOfTheWeek;
        std::vector<std::string> timeForAction;

    public:
        std::vector<std::string> getDaysOfTheWeek() {
            return daysOfTheWeek;
        };

        std::vector<std::string> getTimeForActions() {
                return timeForActions;
        };
};

#endif //RECURRENCY_HPP
