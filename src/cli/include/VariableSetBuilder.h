//
// Created by Illia Plaksa on 20.12.2021.
//

#ifndef TASKMANAGER_SRC_CLI_INCLUDE_VARIABLESETBUILDER_H_
#define TASKMANAGER_SRC_CLI_INCLUDE_VARIABLESETBUILDER_H_

#include "VariableSet.h"

class VariableSetBuilder
{
public:
    VariableSetBuilder() = default;

public: // Setters
    VariableSetBuilder& SetTitle(const std::string& title);
    VariableSetBuilder& SetDate(const time_t& date);
    VariableSetBuilder& SetPriority(const Task::Priority& priority);
    VariableSetBuilder& SetLabel(const std::vector<std::string>& labels);
    VariableSetBuilder& SetStatus(const Task::Status& status);
    VariableSetBuilder& SetParent(const TaskId& parent_id);
    VariableSetBuilder& SetId(const TaskId& id);
    VariableSetBuilder& SetFileName(const std::string& file_name);

public:
    void Reset();
    VariableSet GetResult();

private:
    VariableSet variable_set_;
};

#endif //TASKMANAGER_SRC_CLI_INCLUDE_VARIABLESETBUILDER_H_
