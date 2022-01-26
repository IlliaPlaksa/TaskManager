//
// Created by Illia Plaksa on 26.01.2022.
//

#ifndef TASKMANAGER_SRC_UTIL_MODELRESPONSE_REPONSECONVERTERS_H_
#define TASKMANAGER_SRC_UTIL_MODELRESPONSE_REPONSECONVERTERS_H_

#include "Service.pb.h"
#include "common/include/ModelResponse.h"

service::Response ModelResponseToServiceResponse(const ModelResponse& response);
ModelResponse ServiceResponseToModelResponse(const service::Response& response);

#endif //TASKMANAGER_SRC_UTIL_MODELRESPONSE_REPONSECONVERTERS_H_
