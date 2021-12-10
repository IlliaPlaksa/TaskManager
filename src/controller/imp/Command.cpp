//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../include/Command.h"

struct Command::Impl
{
    explicit Impl(const std::shared_ptr<IView> &view)
        :
        view_(view) {}

    std::shared_ptr<IView> view_;
};

Command::Command(const std::shared_ptr<IView> &view)
    :
    pimpl_(std::make_unique<Impl>(view)) {}

std::shared_ptr<IView> Command::GetView()
{
    return pimpl_->view_;
}



