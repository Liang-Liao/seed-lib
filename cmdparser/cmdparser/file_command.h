// commands/file_command.h
#pragma once
#include "command_interface.h"

class FileCommand : public ICommand {
public:
    int parse(CommandContext& ctx, const std::vector<std::string>& args, int idx) override;
    ReturnCode execute(const CommandContext& ctx) override;
    std::string shortOpt() const override;
    std::string longOpt() const override;
    std::string description() const override;
};