// commands/help_command.h
#pragma once
#include "command_interface.h"
#include <string>

class HelpCommand : public ICommand {
public:
    int parse(CommandContext& ctx, const std::vector<std::string>& args, int idx) override;
    ReturnCode execute(const CommandContext& ctx) override;
    std::string shortOpt() const override;
    std::string longOpt() const override;
    std::string description() const override;
    bool isImmediate() const override;
};