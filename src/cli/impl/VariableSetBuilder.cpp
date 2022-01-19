//
// Created by Illia Plaksa on 20.12.2021.
//

#include "cli/include/VariableSetBuilder.h"
#include <google/protobuf/util/time_util.h>
#include "util/TaskDTO/TaskDTOCreators.h"

VariableSetBuilder& VariableSetBuilder::SetTitle(const std::string& title)
{
    variable_set_.title = title;
    return *this;
}
VariableSetBuilder& VariableSetBuilder::SetDate(const time_t& date)
{
    variable_set_.date = date;
    return *this;
}
VariableSetBuilder& VariableSetBuilder::SetPriority(const Task::Priority& priority)
{
    variable_set_.priority = priority;
    return *this;
}
VariableSetBuilder& VariableSetBuilder::SetLabel(const std::vector<std::string>& labels)
{
    variable_set_.labels = labels;
    return *this;
}
VariableSetBuilder& VariableSetBuilder::SetStatus(const Task::Status& status)
{
    variable_set_.status = status;
    return *this;
}
VariableSetBuilder& VariableSetBuilder::SetParent(const TaskId& parent_id)
{
    variable_set_.parent_id = parent_id;
    return *this;
}
VariableSetBuilder& VariableSetBuilder::SetId(const TaskId& id)
{
    variable_set_.id = id;
    return *this;
}
VariableSetBuilder& VariableSetBuilder::SetFileName(const std::string& file_name)
{
    variable_set_.file_name = file_name;
    return *this;
}
void VariableSetBuilder::Reset()
{
    variable_set_ = VariableSet{};
}
VariableSet VariableSetBuilder::GetResult()
{
    return variable_set_;
}







