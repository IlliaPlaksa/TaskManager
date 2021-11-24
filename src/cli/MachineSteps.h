//
// Created by Illia Plaksa on 22.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_MACHINESTATES_H_
#define TASKMANAGER_SRC_CLI_MACHINESTATES_H_

#include "Step.h"
#include "StepFabric.h"
#include "Context.h"

class RootStep : public Step
{
public:
    Status Execute(Context &context) override;
private:
};

class HelpStep : public Step
{
public:
    Status Execute(Context &context) override;
};

class ExitStep : public Step
{
public:
    Status Execute(Context &context) override;
};

class AddStep : public Step
{
    Status Execute(Context &context) override;
};

class EditStep : public Step
{
    Status Execute(Context &context) override;
};

class CompleteStep : public Step
{
    Status Execute(Context &context) override;
};

class DeleteStep : public Step
{
    Status Execute(Context &context) override;
};

class ShowStep : public Step
{
    Status Execute(Context &context) override;
};
#endif //TASKMANAGER_SRC_CLI_MACHINESTATES_H_
