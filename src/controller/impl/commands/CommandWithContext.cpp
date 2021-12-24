//
// Created by Illia Plaksa on 24.12.2021.
//

#include "../../include/ConcreteCommands.h"

CommandWithContext::CommandWithContext(const ContextDTO& context)
:
    context_(context)
{

}
ContextDTO CommandWithContext::GetContext()
{
    return context_;
}

