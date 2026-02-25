// commands/file_command.cpp
#include "file_command.h"
#include "command_registry.h"
#include <iostream>

int FileCommand::parse(CommandContext& ctx, const std::vector<std::string>& args, int idx) {
    if (idx + 1 >= static_cast<int>(args.size())) {
        std::cerr << "Error: " << args[idx] << " requires a filename\n";
        return ArgConsumption::ERROR;
    }
    ctx.addParam("input_file", args[idx + 1]);
    return ArgConsumption::OPTION_WITH_VALUE;
}

ReturnCode FileCommand::execute(const CommandContext& ctx) {
    auto it = ctx.getParams().find("input_file");
    if (it != ctx.getParams().end()) {
        std::cout << "Processing file: " << it->second << "\n";
        // TODO: 调用实际业务逻辑
        return ReturnCode::SUCCESS;
    }
    return ReturnCode::MISSING_ARGUMENT;
}

std::string FileCommand::shortOpt() const { return "-f"; }
std::string FileCommand::longOpt() const { return "--file"; }
std::string FileCommand::description() const { return "Specify input file to process"; }

// === 自动注册 ===
namespace {
    struct FileCommandRegistrar {
        FileCommandRegistrar() {
            CommandRegistry::getInstance().registerCommand(std::make_unique<FileCommand>());
        }
    } s_registrar;
}