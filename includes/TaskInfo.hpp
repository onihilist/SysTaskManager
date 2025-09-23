//
// Created by onihilist on 22/09/2025.
//

#ifndef TASKINFO_H
#define TASKINFO_H

#include <iostream>
#include <string>
#include <thread>

#include "Recurrency.hpp"

using namespace std;

class TaskInfo {

    private:
        int id;
        thread::id thread_id;
        string name;
        string description;
        Recurrency recurrency;
        string priority;
        string parent;
        string type;
        string parentType;
        string command;

    public:
        static TaskInfo createTestTask(
                                       const std::string &type,
                                       const int days,
                                       const int hours,
                                       const int minutes,
                                       const int seconds);
        static void printMessage(const std::string& message) {
            std::cout << message << std::endl;
        }

        TaskInfo(
            const int id,
            const std::thread::id thread_id,
            const std::string& name,
            const std::string& description,
            const Recurrency& recurrence,
            const std::string& priority,
            const std::string& parent,
            const std::string& parentType,
            const std::string& command
        )
            : id(id),
              thread_id(thread_id),
              name(name),
              description(description),
              recurrency(recurrence),
              priority(priority),
              parent(parent),
              parentType(parentType),
              command(command)
        {}

        ~TaskInfo() {
            cout << "TaskInfo (tID: " << thread_id << ") has been destroyed." <<endl;
        }

        Recurrency &getRecurrency() {
            return recurrency;
        }

};

#endif //TASKINFO_H
