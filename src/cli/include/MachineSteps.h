//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_MACHINESTATES_H_
#define TASKMANAGER_SRC_CLI_MACHINESTATES_H_

#include "Step.h"
#include "Context.h"

enum class StepId;

class RootStep : public Step
{
public:
    using Step::Step;
    Status Execute(Context &context) override;
private:
    static StepId GetIdFromName(const std::string &name);
};

class HelpStep : public Step
{
public:
    using Step::Step;
    Status Execute(Context &context) override;
};

class ExitStep : public Step
{
public:
    using Step::Step;
    Status Execute(Context &context) override;
};

class AddStep : public Step
{
public:
    using Step::Step;
    Status Execute(Context &context) override;
};

class EditStep : public Step
{
public:
    using Step::Step;
    Status Execute(Context &context) override;
};

class CompleteStep : public Step
{
public:
    using Step::Step;
    Status Execute(Context &context) override;
};

class DeleteStep : public Step
{
public:
    using Step::Step;
    Status Execute(Context &context) override;
};

class ShowStep : public Step
{
public:
    using Step::Step;
    Status Execute(Context &context) override;
};

#endif //TASKMANAGER_SRC_CLI_MACHINESTATES_H_
