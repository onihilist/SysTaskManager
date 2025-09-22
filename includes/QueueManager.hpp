//
// Created by onihilist on 22/09/2025.
//

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <any>
#include <string>
#include <vector>
#include <queue>
#include <thread>

using namespace std;

class QueueManager {

    private:
        vector<TaskInfo> taskQueueInfos;
        vector<thread> taskThreads;
        std::queue<any> taskQueue;

    public:
        explicit QueueManager(int queueSize = 0, vector<string> queueName = vector<string>());
        ~QueueManager();

        void setTaskQueueInfos(const vector<vector<string>>& tqn) { taskQueueInfos = tqn; };
        vector<vector<string>>& getTaskQueueInfos() { return taskQueueInfos; };

        string detectTaskType(TaskInfo taskInfo);
        void enqueue(const any& task);
        void dequeue();

};

#endif //QUEUE_HPP
