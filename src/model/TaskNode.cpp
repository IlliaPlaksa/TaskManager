//
// Created by Illia Plaksa on 19.11.2021.
//

#include "TaskNode.h"

TaskNode TaskNode::Create(const Task& task)
{
    return TaskNode{task};
}

TaskNode TaskNode::Create(const Task& task, const TaskId& parent_id)
{
    return TaskNode{task, parent_id};
}

std::optional<TaskId> TaskNode::GetParentId() const
{
    return this->parent_id_;
}
Task TaskNode::GetTask() const
{
    return this->task_;
}
TaskNode::TaskNode(const Task& task, const TaskId& parent_id)
    :
    task_(task),
    parent_id_(parent_id)
{

}

TaskNode::TaskNode(const Task& task)
    :
    task_(task),
    parent_id_(std::nullopt)
{

}

