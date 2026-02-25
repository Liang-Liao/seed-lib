// commands/help_command.cpp
#include "help_command.h"
#include "command_registry.h"
#include "command_parser.h"
#include <iostream>

int HelpCommand::parse(CommandContext&, const std::vector<std::string>&, int) {
    return ArgConsumption::OPTION_ONLY;
}

ReturnCode HelpCommand::execute(const CommandContext& ctx) {
    std::cout << "Usage: " << ctx.getProgramName() << " [OPTIONS]\n\nOptions:\n";
    extern CommandLineParser gParser;
    gParser.printHelp();
    return ReturnCode::SUCCESS;
}

std::string HelpCommand::shortOpt() const { return "-h"; }
std::string HelpCommand::longOpt() const { return "--help"; }
std::string HelpCommand::description() const { return "Show this help message"; }
bool HelpCommand::isImmediate() const { return true; }

// === ×Ô¶¯×¢²á ===
namespace {
    struct HelpCommandRegistrar {
        HelpCommandRegistrar() {
            CommandRegistry::getInstance().registerCommand(std::make_unique<HelpCommand>());
        }
    } s_registrar;
}