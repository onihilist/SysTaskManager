//
// Created by onihilist on 22/09/2025.
//

#ifndef TASKINFO_H
#define TASKINFO_H

#include <string>
#include <thread>

using namespace std;

class TaskInfo {

    private:
        int id;
        thread runningThread;
        string name;
        string description;
        string recurrency;
        string command;
        string priority;
        string parent;
        string type;
        string parentType;

    public:
        TaskInfo(
            int id,
            string name,
            string description,
            string recurrence,
            string priority,
            string parent,
            string type,
            string parentType,
            string command)


}

#endif //TASKINFO_H
