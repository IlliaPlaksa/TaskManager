//
// Created by Illia Plaksa on 17.01.2022.
//

#ifndef TASKMANAGER_TESTS_MOCKS_STEPFACTORYMOCK_H_
#define TASKMANAGER_TESTS_MOCKS_STEPFACTORYMOCK_H_

#include "gmock/gmock.h"
#include "cli/include/StepFactory.h"

class StepFactoryMock : public StepFactory
{
public:
    using StepFactory::StepFactory;
public:
    MOCK_METHOD(std::shared_ptr<Step>, CreateStep, (StepId step_id), (override));
    MOCK_METHOD(std::shared_ptr<StepFactory>, shared, (), (override));
};

#endif //TASKMANAGER_TESTS_MOCKS_STEPFACTORYMOCK_H_
