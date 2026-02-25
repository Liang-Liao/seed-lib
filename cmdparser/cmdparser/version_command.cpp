// commands/version_command.cpp
#include "version_command.h"
#include "command_registry.h"
#include <iostream>

int VersionCommand::parse(CommandContext&, const std::vector<std::string>&, int) {
    return ArgConsumption::OPTION_ONLY;
}

ReturnCode VersionCommand::execute(const CommandContext& ctx) {
    std::cout << ctx.getProgramName() << " version " << ctx.getVersion() << "\n";
    return ReturnCode::SUCCESS;
}

std::string VersionCommand::shortOpt() const { return "-v"; }
std::string VersionCommand::longOpt() const { return "--version"; }
std::string VersionCommand::description() const { return "Show version information"; }
bool VersionCommand::isImmediate() const { return true; }

// === ×Ô¶¯×¢²á ===
namespace {
    struct VersionCommandRegistrar {
        VersionCommandRegistrar() {
            CommandRegistry::getInstance().registerCommand(std::make_unique<VersionCommand>());
        }
    } s_registrar;
}