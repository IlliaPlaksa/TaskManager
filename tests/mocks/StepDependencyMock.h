//
// Created by Illia Plaksa on 18.01.2022.
//

#ifndef TASKMANAGER_TESTS_MOCKS_STEPDEPENDENCYMOCK_H_
#define TASKMANAGER_TESTS_MOCKS_STEPDEPENDENCYMOCK_H_

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "cli/include/StepDependency.h"

#include "mocks/ConsoleManipulatorMock.h"
#include "mocks/StepFactoryMock.h"

class StepDependencyMock : public StepDependency
{
public:
    using StepDependency::StepDependency;
    MOCK_METHOD(std::shared_ptr<ConsoleManipulator>, console_manipulator, (), (override));
    MOCK_METHOD(std::shared_ptr<StepFactory>, step_factory, (), (override));
};

#endif //TASKMANAGER_TESTS_MOCKS_STEPDEPENDENCYMOCK_H_
