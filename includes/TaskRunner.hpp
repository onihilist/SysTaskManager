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

        static std::thread run(QueueManager &qm);
        static bool isTimeToRun(TaskInfo &task, QueueManager &qm);
};

#endif //TASKRUNNER_HPP
