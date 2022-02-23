//
// Created by Illia Plaksa on 18.01.2022.
//

#ifndef TASKMANAGER_TESTS_MOCKS_STEPMOCK_H_
#define TASKMANAGER_TESTS_MOCKS_STEPMOCK_H_

#include "gmock/gmock.h"
#include "cli/Step.h"

class StepMock : public Step
{
public:
    MOCK_METHOD(StepResult, Execute, (Context & context), (override));
};

#endif //TASKMANAGER_TESTS_MOCKS_STEPMOCK_H_
