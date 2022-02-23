//
// Created by Illia Plaksa on 17.02.2022.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <future>

#include "controller/RemoteController.h"
#include "DefaultModelController.h"
#include "RandomCommandGenerator.h"
#include "model/TaskManager.h"

class MultipleClientsTest : public ::testing::Test
{
protected:
    std::shared_ptr<ModelController> controller_;

    void SetUp() override
    {
        Test::SetUp();

        auto generator = std::make_unique<IdGenerator>();
        auto model = std::make_unique<TaskManager>(std::move(generator));

        controller_ = std::make_shared<DefaultModelController>(std::move(model));
    }
};

std::vector<std::shared_ptr<Command>> CreateRandomTasks(size_t tasks_num)
{
    auto result = std::vector<std::shared_ptr<Command>>{};

    auto generator = RandomCommandGenerator{};

    for (int i = 0 ; i < tasks_num ; ++i)
    {
        result.emplace_back(generator.GenerateCommand());
    }

    return result;
}

void WorkerRoutine(std::shared_ptr<ModelController> controller, std::vector<std::shared_ptr<Command>> tasks)
{
    for (auto& task : tasks)
        task->Execute(controller);
}

TEST_F(MultipleClientsTest, shouldNotCorrupt)
{
    auto thread_num = std::thread::hardware_concurrency();
    auto tasks_num = 1000;

    std::vector<std::future<void>> workers{};

    for (int i = 0 ; i < thread_num ; ++i)
    {
        auto random_tasks = CreateRandomTasks(tasks_num);
        workers.emplace_back(std::async(std::launch::async, &WorkerRoutine, controller_, random_tasks));
    }

    for (auto& worker : workers)
        worker.wait();
}