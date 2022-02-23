//
// Created by Illia Plaksa on 18.02.2022.
//

#ifndef TASKMANAGER_TESTS_INTEGRATION_DEFAULTMODELCONTROLLER_H_
#define TASKMANAGER_TESTS_INTEGRATION_DEFAULTMODELCONTROLLER_H_

#include "common/ModelController.h"
#include "persistence/FilePersister.h"

class DefaultModelController : public ModelController
{
public:
    DefaultModelController(std::unique_ptr<Model> model);

public:
    ModelResponse Add(const Task& task) override;
    ModelResponse AddSubTask(const Task& task, const TaskId& parent_id) override;
    ModelResponse Edit(const TaskId& task_id, const Task& task) override;
    ModelResponse EditSubTask(const TaskId& task_id, const Task& task, const TaskId& parent_id) override;
    ModelResponse Complete(const TaskId& task_id) override;
    ModelResponse Delete(const TaskId& task_id) override;

public:
    std::vector<TaskDTO> Show() override;
    std::vector<TaskDTO> ShowParents() override;
    std::vector<TaskDTO> ShowChild(const TaskId& parent_id) override;
    std::vector<TaskDTO> ShowTasksWithLabel(const std::string& label) override;

public:
    ModelResponse Load(const std::vector<TaskDTO>& tasks) override;
    ModelResponse LoadFromFile(const std::string& file_name) override;
    ModelResponse SaveToFile(const std::string& file_name) override;

private:
    std::unique_ptr<Model> model_;
};

#endif //TASKMANAGER_TESTS_INTEGRATION_DEFAULTMODELCONTROLLER_H_
