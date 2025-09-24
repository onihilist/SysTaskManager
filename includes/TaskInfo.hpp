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

        static TaskInfo createTask(
            const std::string &type,
            const std::string &name,
            const std::string &command,
            const int days,
            const int hours,
            const int minutes,
            const int seconds);

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
            if (thread_id != thread::id()) {
                cout << "TaskInfo " << name << " (tID: " << thread_id << ") has been destroyed." <<endl;
            } else {
                cout << "TaskInfo " << name << " has been destroyed and never used/ran." <<endl;
            }
        }

        Recurrency &getRecurrency() {
            return recurrency;
        }

        std::string getName() {
            return name;
        }

        thread::id &getThreadId() {
            return thread_id;
        }

        void setThreadId(const std::thread::id thread_id) {
            this->thread_id = thread_id;
        }

};

#endif //TASKINFO_H
