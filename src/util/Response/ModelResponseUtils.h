//
// Created by Illia Plaksa on 04.02.2022.
//

#ifndef TASKMANAGER_SRC_UTIL_RESPONSE_MODELRESPONSEUTILS_H_
#define TASKMANAGER_SRC_UTIL_RESPONSE_MODELRESPONSEUTILS_H_

#include "common/include/ModelResponse.h"

std::string to_string(const ModelResponse::Status& status);
std::string to_string(const ModelResponse::ErrorType& error_type);
std::string to_string(const ModelResponse& model_response);

#endif //TASKMANAGER_SRC_UTIL_RESPONSE_MODELRESPONSEUTILS_H_
