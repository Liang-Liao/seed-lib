// framework/command_registry.cpp
#include "command_registry.h"

void CommandRegistry::registerCommand(std::unique_ptr<ICommand> cmd) {
    commands_.push_back(std::move(cmd));
}

const std::vector<std::unique_ptr<ICommand>>& CommandRegistry::getCommands() const {
    return commands_;
}