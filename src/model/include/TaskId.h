//
// Created by Illia Plaksa on 10.11.2021.
//

#ifndef TASKMANAGER_SRC_MODEL_TASKID_H_
#define TASKMANAGER_SRC_MODEL_TASKID_H_

#include <stdexcept>

class TaskId
{
public: // static interface
    static TaskId Create(int value);
    static TaskId CreateDefault();

public:
    bool operator<(const TaskId &other) const;
    bool operator==(const TaskId &other) const;
    bool operator!=(const TaskId &other) const;

public:
    int value() const;

private: // private methods
    explicit TaskId(int);

private: // data
    int value_;
};

#endif //TASKMANAGER_SRC_MODEL_TASKID_H_
