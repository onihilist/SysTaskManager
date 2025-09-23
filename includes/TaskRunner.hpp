//
// Created by onihilist on 23/09/2025.
//

#ifndef TASKRUNNER_HPP
#define TASKRUNNER_HPP
#include <thread>

class TaskRunner {
    public:
        TaskRunner();
        ~TaskRunner();
        void run(std::thread t);
};

#endif //TASKRUNNER_HPP
