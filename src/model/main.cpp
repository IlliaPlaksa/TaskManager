#include <iostream>
#include "Task.h"
#include "TaskManager.h"

int main()
{
    // Simple test
    TaskManager task_manager;

    auto task = Task::Create("Task name",
                             std::time(nullptr),
                             Task::Priority::High);
    task_manager.Create(task);

    task = Task::Create("Second task",
                        std::time(nullptr),
                        Task::Priority::Medium);
    task_manager.Create(task);

    task = Task::Create("Third task",
                        std::time(nullptr),
                        Task::Priority::Low);
    task_manager.Create(task);

    task = Task::Create("New name for task",
                        std::time(nullptr),
                        Task::Priority::Medium);

    task_manager.Edit(TaskId::Create(1), task);

    auto tasks = task_manager.Show();

    task_manager.Complete(TaskId::Create(2));
    task_manager.Delete(TaskId::Create(2));

    return 0;
}
