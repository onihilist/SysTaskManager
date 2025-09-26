
#ifndef TASKINFO_HPP
#define TASKINFO_HPP

#include <string>
#include <thread>
#include <ctime>
#include <functional>
#include <vector>
#include <iostream>

struct Recurrency {
    std::string type;
    std::time_t datetimeForAction;
    std::vector<std::string> includedDays;
    std::vector<std::string> excludedDays;

    std::time_t getDatetimeForAction() const { return datetimeForAction; }
};

class QueueManager;

class TaskInfo {
public:
    TaskInfo(int id,
             std::thread::id tid,
             std::string name,
             std::string description,
             Recurrency rec,
             std::string priority,
             std::string status,
             std::string result,
             std::function<void(void)> command)
        : id(id), threadId(tid), name(std::move(name)), description(std::move(description)),
          recurrency(std::move(rec)), priority(std::move(priority)),
          status(std::move(status)), result(std::move(result)), command(std::move(command))
    {
        std::cout << "TaskInfo \"" << this->name << "\" created" << std::endl;
    }

    TaskInfo(TaskInfo&&) noexcept = default;
    TaskInfo& operator=(TaskInfo&&) noexcept = default;
    TaskInfo(const TaskInfo&) = delete;
    TaskInfo& operator=(const TaskInfo&) = delete;

    ~TaskInfo() {
        std::cout << "TaskInfo \"" << name << "\"";
        if (threadId != std::thread::id()) {
            std::cout << " (tID: " << threadId << ")";
        }
        std::cout << " has been destroyed" << std::endl;
    }

    static bool createTask(const std::string &type,
                           const std::string &name,
                           std::function<void()> command,
                           int days, int hours, int minutes, int seconds,
                           QueueManager &queueManager);

    void setThreadId(const std::thread::id tid) { threadId = tid; }
    const std::string& getName() const { return name; }
    const Recurrency& getRecurrency() const { return recurrency; }
    const std::function<void(void)>& getCommand() const { return command; }

private:
    int id;
    std::thread::id threadId;
    std::string name;
    std::string description;
    Recurrency recurrency;
    std::string priority;
    std::string status;
    std::string result;
    std::remove_reference_t<std::function<void()> &> command;
};

#endif // TASKINFO_HPP
