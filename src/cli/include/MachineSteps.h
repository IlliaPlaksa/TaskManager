//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_MACHINESTATES_H_
#define TASKMANAGER_SRC_CLI_MACHINESTATES_H_

#include "Step.h"
#include "StepDependency.h"
#include "Context.h"

enum class StepId;

class StepWithDependency : public Step
{
public:
    explicit StepWithDependency(const std::shared_ptr<StepDependency>& dependency);

public:
    std::shared_ptr<StepDependency> dependency();

private:
    std::shared_ptr<StepDependency> dependency_;
};

class RootStep : public StepWithDependency
{
public:
    using StepWithDependency::StepWithDependency;

    StepResult Execute(Context& context) override;
};

class HelpStep : public StepWithDependency
{
public:
    using StepWithDependency::StepWithDependency;
    StepResult Execute(Context& context) override;
};

class ExitStep : public StepWithDependency
{
public:
    using StepWithDependency::StepWithDependency;
    StepResult Execute(Context& context) override;
};

class AddStep : public StepWithDependency
{
public:
    using StepWithDependency::StepWithDependency;
    StepResult Execute(Context& context) override;
};

class EditStep : public StepWithDependency
{
public:
    using StepWithDependency::StepWithDependency;
    StepResult Execute(Context& context) override;
};

class CompleteStep : public StepWithDependency
{
public:
    using StepWithDependency::StepWithDependency;
    StepResult Execute(Context& context) override;
};

class DeleteStep : public StepWithDependency
{
public:
    using StepWithDependency::StepWithDependency;
    StepResult Execute(Context& context) override;
};

class ShowStep : public StepWithDependency
{
public:
    using StepWithDependency::StepWithDependency;
    StepResult Execute(Context& context) override;

private:
    static void OutputSubTasks(std::ostream& output,
                               const TaskId& task_id,
                               const TaskStorage& storage,
                               const std::string& offset
    );

    static std::string ToString(const TaskDTO& task);
    static std::string ToString(const Task::Priority& priority);
    static std::string ToString(const Task::Status& status);
};

class UpdateStep : public StepWithDependency
{
public:
    using StepWithDependency::StepWithDependency;
    StepResult Execute(Context& context) override;
};

class SaveStep : public StepWithDependency
{
public:
    using StepWithDependency::StepWithDependency;
    StepResult Execute(Context& context) override;
};

class LoadStep : public StepWithDependency
{
public:
    using StepWithDependency::StepWithDependency;
    StepResult Execute(Context& context) override;
};

#endif //TASKMANAGER_SRC_CLI_MACHINESTATES_H_
