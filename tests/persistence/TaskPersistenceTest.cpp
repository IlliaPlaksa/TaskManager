//
// Created by Illia Plaksa on 15.12.2021.
//

#include "gtest/gtest.h"
#include "persistence/include/FilePersister.h"
#include "TaskDTO.pb.h"
#include "util/TaskDTO/TaskDTOComparators.h"

class FilePersisterTest : public ::testing::Test {};

TEST(TaskPersisterTest, shouldSerializeAndDeserialize)
{
    auto tasks = std::vector<TaskDTO>{};

    for (size_t i = 0 ; i < 5 ; i++)
    {
        auto tmp = TaskDTO{};
        auto task = tmp.mutable_task();
        task->set_title(std::to_string(i));
        task->set_priority(Task_Priority_kHigh);
        task->set_status(Task_Status_kInProgress);

        tasks.emplace_back(tmp);
    }

    std::string file_name = "test_file.txt";

    auto persister = FilePersister{file_name};
    persister.Save(tasks);
    auto deserialized = persister.Load();

    ASSERT_TRUE(deserialized);
    ASSERT_EQ(tasks.size(), deserialized->size());

    for (const auto& elem : deserialized.value())
        EXPECT_TRUE(tasks.end() != std::find(tasks.cbegin(), tasks.cend(), elem));
}