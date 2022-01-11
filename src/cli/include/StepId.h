//
// Created by Illia Plaksa on 29.11.2021.
//

#ifndef TASKMANAGER_SRC_CLI_INCLUDE_STEPID_H_
#define TASKMANAGER_SRC_CLI_INCLUDE_STEPID_H_

enum class StepId
{
    kNone,
    kError,
    kRoot,
    kHelp,
    kExit,
    kAdd,
    kEdit,
    kComplete,
    kDelete,
    kShow,
    kUpdate,
    kSave,
    kLoad,
};

#endif //TASKMANAGER_SRC_CLI_INCLUDE_STEPID_H_
