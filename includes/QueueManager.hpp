//
// Created by onihilist on 22/09/2025.
//

#ifndef QUEUEMANAGER_HPP
#define QUEUEMANAGER_HPP
#include <any>
#include <string>
#include <vector>
#include <queue>
#include <thread>

#include "TaskInfo.hpp"

using namespace std;

class QueueManager {

    private:
        vector<TaskInfo> taskQueueInfos;
        std::queue<any> taskQueue;

    public:
        explicit QueueManager(int queueSize = 0, vector<string> queueName = vector<string>());
        ~QueueManager();

        void setTaskQueueInfos(const vector<vector<string>>& tqn) { taskQueueInfos = tqn; };

        vector<vector<string>>& getTaskQueueInfos() { return taskQueueInfos; };
        string

        string detectTaskType(TaskInfo taskInfo);
        void enqueue(const any& task);
        void dequeue();

};

#endif //QUEUEMANAGER_HPP
