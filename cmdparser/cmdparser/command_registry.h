// framework/command_registry.h
#pragma once
#include "command_interface.h"
#include <vector>
#include <memory>

class CommandRegistry {
public:
    static CommandRegistry& getInstance() {
        static CommandRegistry instance;
        return instance;
    }

    void registerCommand(std::unique_ptr<ICommand> cmd);
    const std::vector<std::unique_ptr<ICommand>>& getCommands() const;

private:
    CommandRegistry() = default;
    std::vector<std::unique_ptr<ICommand>> commands_;
};