//
// Created by Illia Plaksa on 10.12.2021.
//

#include "../../include/ConcreteCommands.h"

Model::Response ShowCommand::Execute(const std::shared_ptr<Model>& model)
{
    auto context = this->GetContext();
    auto var_set = context->variable_set();

    auto new_context = ContextDTO::Create(VariableSet{}, model->Show());
    this->SetContext(new_context);

    return Model::Response::CreateSuccess();
}
bool ShowCommand::IsReady() const
{
    auto variable_set = GetContext()->variable_set();
    return true; // TODO add some conditions
}
