//
// Created by Illia Plaksa on 08.11.2021.
//

#ifndef TASKMANAGER_SRC_MODEL_TASK_H_
#define TASKMANAGER_SRC_MODEL_TASK_H_

#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>

class Task
{
public: // internals
    enum class Priority
    {
        kNone,
        kHigh,
        kMedium,
        kLow
    };

    enum class Status
    {
        kNone,
        kCompleted,
        kInProgress,
    };

public:
    static Task Create(const std::string &title,
                       const std::time_t &due_to_date,
                       const Priority &priority,
                       const std::string &label = "",
                       const Status &status = Status::kInProgress);

    static Task Complete(const Task &task);
public: // Getters
    std::string GetTitle() const;
    std::time_t GetDate() const;
    Task::Priority GetPriority() const;
    std::string GetLabel() const;
    Status GetStatus() const;

public: // ToString methods
    std::string ToString() const;
    static std::string PriorityToString(const Task::Priority &priority);
     static std::string StatusToString(const Task::Status &status);

private:
    Task(const std::string &title,
         const std::time_t &due_to_date,
         const Priority &priority,
         const std::string &label,
         const Status &status);

private:
    std::string title_;
    Priority priority_;
    std::time_t due_to_date_;
    std::string label_;
    Status status_;
};

#endif //TASKMANAGER_SRC_MODEL_TASK_H_
