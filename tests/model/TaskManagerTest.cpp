//
// Created by Illia Plaksa on 14.11.2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "model/include/TaskManager.h"
#include "util/Task/TaskCreators.h"
#include "util/TaskId/TaskIdCreators.h"
#include "util/TaskId/TaskIdComparators.h"
#include "util/TaskDTO/TaskDTOCreators.h"

class IdGeneratorMock : public IdGenerator
{
public:
    MOCK_METHOD(TaskId, GetNextId, (), (override));
};

class TaskManagerTest : public ::testing::Test {};

TEST(TaskManagerTest, shouldAddTask)
{
    auto manager = TaskManager{std::make_unique<IdGenerator>()};

    auto task_title = "Task name";
    auto task_date = time(nullptr);
    auto task_priority = Task::Priority::Task_Priority_kLow;

    auto task = CreateTask(task_title,
                           task_date,
                           task_priority);

    auto task_id = *CreateTaskId(0);

    manager.Add(*task);

    ASSERT_EQ(manager.Show().size(), 1);

    auto added_task = manager.Show().begin()->task();

    EXPECT_EQ(task_id, manager.Show().begin()->id());

    EXPECT_EQ(task_title, added_task.title());
    EXPECT_EQ(task_date, added_task.due_date().seconds());
    EXPECT_EQ(task_priority, added_task.priority());
}

TEST(TaskManagerTest, shouldAddSubTask)
{
    auto manager = TaskManager{std::make_unique<IdGenerator>()};

    auto task_title = "Task name";
    auto task_date = time(nullptr);
    auto task_priority = Task::Priority::Task_Priority_kLow;

    auto task = CreateTask(task_title,
                           task_date,
                           task_priority);

    auto task_id = *CreateTaskId(0);

    manager.Add(*task);
    manager.AddSubTask(*task, *CreateTaskId(0));

    auto added_task = manager.Show()[1].task();
    auto parent_id = manager.Show()[1].parent_id();

    EXPECT_EQ(task_id, manager.Show().begin()->id());

    EXPECT_EQ(task_title, added_task.title());
    EXPECT_EQ(task_date, added_task.due_date().seconds());
    EXPECT_EQ(task_priority, added_task.priority());
    EXPECT_EQ(task_id, parent_id);
}

TEST(TaskManagerTest, shouldReturnWrongParentIdErrorInAdd)
{
    auto manager = TaskManager{std::make_unique<IdGenerator>()};

    auto task_title = "Task name";
    auto task_date = time(nullptr);
    auto task_priority = Task::Priority::Task_Priority_kLow;

    auto task = *CreateTask(task_title,
                            task_date,
                            task_priority);

    auto task_id = *CreateTaskId(0);
    manager.Add(task);

    EXPECT_TRUE(
        manager.AddSubTask(task, *CreateTaskId(1234)).error() == ModelResponse::ErrorType::NON_EXISTING_PARENT_ID);
}

TEST(TaskManagerTest, shouldAddMultiplyTasks)
{
    auto manager = TaskManager{std::make_unique<IdGenerator>()};

    auto task_title = "Task name";
    auto task_date = time(nullptr);
    auto task_priority = Task::Priority::Task_Priority_kLow;

    auto task = CreateTask(task_title,
                           task_date,
                           task_priority);

    manager.Add(*task);
    manager.Add(*task);
    manager.Add(*task);
    manager.Add(*task);

    EXPECT_EQ(manager.Show().size(), 4);
}

TEST(TaskManagerTest, shouldReturnWrongIdErrorInEdit)
{
    auto manager = TaskManager{std::make_unique<IdGenerator>()};

    auto task = CreateTask("Task name",
                           time(nullptr),
                           Task::Priority::Task_Priority_kHigh);

    ASSERT_TRUE(
        manager.Edit(*CreateTaskId(123), *task).error() == ModelResponse::ErrorType::INVALID_ID
    );

    ASSERT_TRUE(
        manager.EditSubTask(*CreateTaskId(123), *task, *CreateTaskId(0)).error()
            == ModelResponse::ErrorType::INVALID_ID
    );
}

TEST(TaskManagerTest, shouldEditTask)
{
    auto manager = TaskManager{std::make_unique<IdGenerator>()};
    auto task = CreateTask("Task name",
                           time(nullptr),
                           Task::Priority::Task_Priority_kHigh);
    manager.Add(*task);

    auto new_title = "New task name";
    auto new_date = time(nullptr);
    auto new_priority = Task::Priority::Task_Priority_kLow;
    auto new_task = CreateTask(new_title,
                               new_date,
                               new_priority);

    manager.Edit(*CreateTaskId(0), *new_task);

    auto edited_task = manager.Show().begin()->task();

    EXPECT_EQ(new_title, edited_task.title());
    EXPECT_EQ(new_date, edited_task.due_date().seconds());
    EXPECT_EQ(new_priority, edited_task.priority());
}

TEST(TaskManagerTest, shouldEditSubTask)
{
    auto manager = TaskManager{std::make_unique<IdGenerator>()};
    auto task = *CreateTask("Task name",
                           time(nullptr),
                           Task::Priority::Task_Priority_kHigh);
    manager.Add(task);
    manager.AddSubTask(task, *CreateTaskId(0));


    auto new_title = "New task name";
    auto new_date = time(nullptr);
    auto new_priority = Task::Priority::Task_Priority_kLow;
    auto new_task = CreateTask(new_title,
                               new_date,
                               new_priority);

    manager.EditSubTask(*CreateTaskId(1), *new_task, *CreateTaskId(0));

    auto edited_task = manager.Show()[1].task();

    EXPECT_EQ(new_title, edited_task.title());
    EXPECT_EQ(new_date, edited_task.due_date().seconds());
    EXPECT_EQ(new_priority, edited_task.priority());
}

TEST(TaskManagerTest, shouldReturnWrongParentIdErrorInEdit)
{
    auto manager = TaskManager{std::make_unique<IdGenerator>()};

    auto task = *CreateTask("Task name",
                            time(nullptr),
                            Task::Priority::Task_Priority_kHigh);
    auto parent_id = CreateTaskId(0);

    manager.Add(task);
    manager.AddSubTask(task, *CreateTaskId(0));

    ASSERT_TRUE(
        manager.EditSubTask(*CreateTaskId(1), task, *CreateTaskId(123)).error()
            == ModelResponse::ErrorType::NON_EXISTING_PARENT_ID
    );
}

TEST(TaskManagerTest, shouldDeleteTask)
{
    auto manager = TaskManager{std::make_unique<IdGenerator>()};
    auto task = *CreateTask("Task name",
                            time(nullptr),
                            Task::Priority::Task_Priority_kHigh);
    auto task_id = *CreateTaskId(0);

    manager.Add(task);
    manager.AddSubTask(task, *CreateTaskId(0));
    manager.Add(task);
    manager.Delete(task_id);

    ASSERT_EQ(manager.Show().size(), 1);

    EXPECT_TRUE(manager.Edit(task_id, task).IsError());
}

TEST(TaskManagerTest, shouldReturnWrongIdErrorInDelete)
{
    auto manager = TaskManager{std::make_unique<IdGenerator>()};

    auto task_id = *CreateTaskId(0);

    EXPECT_TRUE(manager.Delete(task_id).error() == ModelResponse::ErrorType::INVALID_ID);
}

TEST(TaskManagerTest, shouldCompleteTask)
{
    auto manager = TaskManager{std::make_unique<IdGenerator>()};
    auto task = *CreateTask("Task name",
                           time(nullptr),
                           Task::Priority::Task_Priority_kHigh);

    auto parent_id = *CreateTaskId(0);

    manager.Add(task);
    manager.AddSubTask(task, parent_id);

    manager.Complete(*CreateTaskId(1));
    EXPECT_EQ(manager.Show()[1].task().status(), Task::Status::Task_Status_kCompleted);

    manager.Complete(parent_id);
    EXPECT_EQ(manager.Show()[0].task().status(), Task::Status::Task_Status_kCompleted);


}

TEST(TaskManagerTest, shouldReturnWrongIdErrorInComplete)
{
    auto manager = TaskManager{std::make_unique<IdGenerator>()};

    auto task_id = *CreateTaskId(123);
    EXPECT_TRUE(manager.Complete(task_id).error() == ModelResponse::ErrorType::INVALID_ID);
}

TEST(TaskManagerTest, shouldReturnNotcompletedSubtasksErrorInComplete)
{
    auto manager = TaskManager{std::make_unique<IdGenerator>()};
    auto task = *CreateTask("Task name",
                           time(nullptr),
                           Task::Priority::Task_Priority_kHigh);

    auto task_id = *CreateTaskId(0);

    manager.Add(task);
    manager.AddSubTask(task, task_id);
    EXPECT_TRUE(manager.Complete(task_id).error() == ModelResponse::ErrorType::NOT_COMPLETED_SUBTASKS);
}

TEST(TaskManagerTest, shouldShowParentTasks)
{
    auto manager = TaskManager{std::make_unique<IdGenerator>()};
    size_t size = 5;
    for (int i = 0 ; i < size ; ++i)
    {
        auto task = CreateTask("Title", time(nullptr), Task::Priority::Task_Priority_kMedium);
        manager.Add(*task);
    }
    auto tasks = manager.ShowParents();
    EXPECT_EQ(tasks.size(), size);
}

TEST(TaskManagerTest, shouldReturnChildTasks)
{
    auto manager = TaskManager{std::make_unique<IdGenerator>()};

    auto parent_task = TaskNode::Create(
        *CreateTask("Parent",
                    time(nullptr),
                    Task::Priority::Task_Priority_kHigh)
    );

    manager.Add(parent_task.GetTask());

    auto parent_id = *CreateTaskId(0);
    size_t size = 5;
    for (int i = 0 ; i < size ; ++i)
    {
        auto task = CreateTask("Title",
                               time(nullptr),
                               Task::Priority::Task_Priority_kMedium);
        manager.AddSubTask(*task, parent_id);
    }
    auto tasks = manager.ShowChild(parent_id);
    EXPECT_EQ(tasks.size(), size);
}

TEST(TaskManagerTest, shouldLoadTasks)
{
    auto manager = TaskManager{std::make_unique<IdGenerator>()};

    auto tasks = std::vector<TaskDTO>{};

    auto task = *CreateTask("Title", time(nullptr), Task::Priority::Task_Priority_kMedium);

    tasks.emplace_back(*CreateTaskDTO(*CreateTaskId(0), task));
    tasks.emplace_back(*CreateTaskDTO(*CreateTaskId(1), task));
    tasks.emplace_back(*CreateTaskDTO(*CreateTaskId(2), task));

    manager.Load(tasks);

    EXPECT_EQ(manager.Show().size(), 3);
}

TEST(TaskManagerTest, shouldRejectLoadingWrongTasks)
{
    auto manager = TaskManager{std::make_unique<IdGenerator>()};

    auto tasks = std::vector<TaskDTO>{};

    auto task = *CreateTask("Title", time(nullptr), Task::Priority::Task_Priority_kMedium);

    tasks.emplace_back(*CreateTaskDTO(*CreateTaskId(0), task));
    tasks.emplace_back(*CreateSubTaskDTO(*CreateTaskId(1), task, *CreateTaskId(123)));
    tasks.emplace_back(*CreateTaskDTO(*CreateTaskId(2), task));

    EXPECT_TRUE(manager.Load(tasks).error() == ModelResponse::ErrorType::FAIL);

    tasks.clear();

    tasks.emplace_back(*CreateTaskDTO(*CreateTaskId(0), task));
    tasks.emplace_back(*CreateSubTaskDTO(*CreateTaskId(1), task, *CreateTaskId(1)));
    tasks.emplace_back(*CreateTaskDTO(*CreateTaskId(2), task));

    EXPECT_TRUE(manager.Load(tasks).error() == ModelResponse::ErrorType::FAIL);
}

TEST(TaskManagerTest, shouldShowTasksWithReqiredLabel)
{
    auto manager = TaskManager{std::make_unique<IdGenerator>()};

    auto expect_label = "label2";

    auto task = *CreateTask("Parent",
                            time(nullptr),
                            Task::Priority::Task_Priority_kHigh);
    manager.Add(task);

    size_t size = 5;
    for (int i = 0 ; i < size ; ++i)
    {
        task = *CreateTask("Child",
                           time(nullptr),
                           Task::Priority::Task_Priority_kLow,
                           {expect_label});

        manager.AddSubTask(task, *CreateTaskId(0));
    }

    manager.Add(
        *CreateTask("Second Parent",
                    time(nullptr),
                    Task::Priority::Task_Priority_kHigh,
                    {expect_label})
    );

    auto result = manager.ShowTasksWithLabel(expect_label);
    EXPECT_EQ(result.size(), (size + 1));

    for (const auto& task_dto: result)
    {
        auto labels = task_dto.task().labels();
        auto has_label = std::any_of(labels.cbegin(), labels.cend(),
                                      [&expect_label](const auto& label)
                                      {
                                          return label == expect_label;
                                      });

        EXPECT_TRUE(has_label);
    }
}