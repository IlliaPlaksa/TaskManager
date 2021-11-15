//
// Created by Illia Plaksa on 10.11.2021.
//

#ifndef TASKMANAGER_SRC_MODEL_TASKID_H_
#define TASKMANAGER_SRC_MODEL_TASKID_H_

class TaskId
{
public: // static interface
    static TaskId Create(unsigned int value);

public:
    bool operator<(const TaskId &other) const;
    bool operator==(const TaskId &other) const;
    bool operator!=(const TaskId &other) const;

public:
    unsigned int value() const;

private: // private methods
    explicit TaskId(unsigned int);

private: // data
    const unsigned int value_;
};

#endif //TASKMANAGER_SRC_MODEL_TASKID_H_
