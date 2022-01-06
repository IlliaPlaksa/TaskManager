//
// Created by Illia Plaksa on 20.12.2021.
//

#ifndef TASKMANAGER_SRC_CLI_INCLUDE_VARIABLESETBUILDER_H_
#define TASKMANAGER_SRC_CLI_INCLUDE_VARIABLESETBUILDER_H_

#include "Task.pb.h"
#include "TaskId.pb.h"
#include "TaskDTO.pb.h"

class VariableSetBuilder
{
public:
    VariableSetBuilder() = default;

public: // Setters
    VariableSetBuilder& SetTitle(const std::string& title);
    VariableSetBuilder& SetDate(const time_t& date);
    VariableSetBuilder& SetPriority(const Task::Priority& priority);
    VariableSetBuilder& SetLabel(const std::string& label);
    VariableSetBuilder& SetStatus(const Task::Status& status);
    VariableSetBuilder& SetParent(const TaskId& parent_id);
    VariableSetBuilder& SetId(const TaskId& id);

public:
    void Reset();
    bool IsReady();

public:
    std::optional<TaskId> id();
    std::optional<Task> task();
    std::optional<TaskId> parent_id();
    std::optional<TaskDTO> MakeTaskToSerialize();

private:
    TaskId id_;
    Task task_;
    std::optional<TaskId> parent_id_;
};

#endif //TASKMANAGER_SRC_CLI_INCLUDE_VARIABLESETBUILDER_H_
