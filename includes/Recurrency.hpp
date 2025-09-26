
#ifndef RECURRENCY_HPP
#define RECURRENCY_HPP
#include <string>
#include <vector>

class Recurrency {
    private:
        std::string type;
        time_t datetimeForAction;
        std::vector<std::string> daysOfTheWeek;
        std::vector<std::string> timeForAction;

    public:

        Recurrency(
        const std::string& type,
        const time_t datetimeForAction,
        const std::vector<std::string>& daysOfTheWeek,
        const std::vector<std::string>& timeForAction
        ) :
        type(type),
        datetimeForAction(datetimeForAction),
        daysOfTheWeek(daysOfTheWeek),
        timeForAction(timeForAction) {}

        std::time_t getDatetimeForAction() const {
            return datetimeForAction;
        }

        std::vector<std::string> getDaysOfTheWeek() {
            return daysOfTheWeek;
        };

        std::vector<std::string> getTimeForAction() {
                return timeForAction;
        };

        std::string getType() {
            return type;
        }
};

#endif //RECURRENCY_HPP
