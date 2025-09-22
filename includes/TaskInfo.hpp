//
// Created by onihilist on 22/09/2025.
//

#ifndef TASKINFO_H
#define TASKINFO_H

#include <iostream>
#include <string>
#include <thread>

using namespace std;

class TaskInfo {

    private:
        int id;
        thread::id thread_id;
        string name;
        string description;
        string recurrency;
        string command;
        string priority;
        string parent;
        string type;
        string parentType;

    public:
        static void createTestTask();
        static void printMessage(const std::string& message) {
            std::cout << message << std::endl;
        }

        TaskInfo(
            const int id,
            const std::thread::id thread_id,
            const std::string& name,
            const std::string& description,
            const std::string& recurrence,
            const std::string& priority,
            const std::string& parent,
            const std::string& type,
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
              type(type),
              parentType(parentType),
              command(command)
        {}


};

#endif //TASKINFO_H
