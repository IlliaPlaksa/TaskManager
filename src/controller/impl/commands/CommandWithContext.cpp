//
// Created by Illia Plaksa on 24.12.2021.
//

#include "../../include/ConcreteCommands.h"

CommandWithContext::CommandWithContext(const std::shared_ptr<ContextDTO>& context)
:
    context_(context)
{

}
std::shared_ptr<ContextDTO> CommandWithContext::GetContext()
{
    return context_;
}
void CommandWithContext::SetContext(const ContextDTO& context)
{
    *context_ = context;
}

