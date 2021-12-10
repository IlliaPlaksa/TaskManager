//
// Created by Illia Plaksa on 10.12.2021.
//

#ifndef TASKMANAGER_SRC_CONTROLLER_COMMAND_H_
#define TASKMANAGER_SRC_CONTROLLER_COMMAND_H_

#include <memory>
#include "IModel.h"
#include "IView.h"

class Command
{
public: // Internals
    struct Response
    {
        enum class Status
        {
            kSuccess,
            kError
        };
        // TODO add more information
        Status status;
    };

public:
    explicit Command(const std::shared_ptr<IView> &view);
public:
    virtual Response Execute(std::shared_ptr<IModel>) = 0;

public:
    std::shared_ptr<IView> GetView();

public:
    virtual ~Command() = default;

private:
    class Impl;
    std::unique_ptr<Impl> pimpl_;
};
#endif //TASKMANAGER_SRC_CONTROLLER_COMMAND_H_
