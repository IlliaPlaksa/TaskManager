//
// Created by Illia Plaksa on 03.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_
#define TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_

#include "Task.pb.h"
#include "TaskId.pb.h"
#include "Model.h"

/**
 * @brief \b Wraps and extends interface of \b Model
 * @details Provides API of \b Model extended with LoadFromFile and SaveToFile methods
 * @author Plaksa Illia
 */
class ModelController : public Model
{
public:
    /**
     * @param file_name \b std::string specifies name of file to load model from
     * @return \b ModelResponse
     * @note In case of wrong name of file or corrupted data returns \b ModelResponse with error message
     * and saves the same state that was before method's call
     */
    virtual ModelResponse LoadFromFile(const std::string& file_name) = 0;

    /**
     * @param file_name \b std::string specifies name of file to save model state to
     * @return \b ModelResponse
     */
    virtual ModelResponse SaveToFile(const std::string& file_name) = 0;
};
#endif //TASKMANAGER_SRC_CONTROLLER_CONTROLLER_H_
