//
// Created by onihilist on 23/09/2025.
//

#ifndef TASKRUNNER_HPP
#define TASKRUNNER_HPP

#include "../includes/TaskInfo.hpp"

class TaskRunner {
    public:
        TaskRunner();
        ~TaskRunner();

        static std::thread run(TaskInfo &task);
        static bool isTimeToRun(TaskInfo &task);
};

#endif //TASKRUNNER_HPP
