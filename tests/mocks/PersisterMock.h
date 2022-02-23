//
// Created by Illia Plaksa on 17.01.2022.
//

#ifndef TASKMANAGER_TESTS_MOCKS_PERSISTERMOCK_H_
#define TASKMANAGER_TESTS_MOCKS_PERSISTERMOCK_H_

#include "gmock/gmock.h"
#include "common/Persister.h"

class TaskPersisterMock : public TaskPersister
{
public:
    MOCK_METHOD(std::optional<std::vector<TaskDTO>>, Load, (), (override));
    MOCK_METHOD(bool, Save, (const std::vector<TaskDTO>& tasks), (override));
};

#endif //TASKMANAGER_TESTS_MOCKS_PERSISTERMOCK_H_
