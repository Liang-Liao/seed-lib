// framework/command_parser.cpp
#include "command_parser.h"
#include "command_registry.h"
#include <iostream>
#include <vector>

ReturnCode CommandLineParser::parse(int argc, char* argv[], CommandContext& ctx) {
    if (argc < 1) return ReturnCode::INVALID_ARGUMENT;

    std::vector<std::string> args(argv, argv + argc);
    ctx.setProgramName(args[0]);

    auto& registry = CommandRegistry::getInstance();
    auto& commands = registry.getCommands();

    int i = 1;
    while (i < static_cast<int>(args.size())) {
        std::string arg = args[i];

        // 支持 --opt=value
        if (arg.size() > 2 && arg.substr(0, 2) == "--") {
            size_t eq = arg.find('=');
            if (eq != std::string::npos && eq > 2) {
                args[i] = arg.substr(0, eq);
                args.insert(args.begin() + i + 1, arg.substr(eq + 1));
            }
        }

        bool matched = false;
        for (auto& cmd : commands) {
            if (arg == cmd->shortOpt() || arg == cmd->longOpt()) {
                int consumed = cmd->parse(ctx, args, i);
                if (consumed <= 0) {
                    if (consumed == ArgConsumption::ERROR)
                        return ReturnCode::MISSING_ARGUMENT;
                    return ReturnCode::INVALID_ARGUMENT;
                }

                ctx.addActivatedCommand(cmd.get());

                if (cmd->isImmediate()) {
                    cmd->execute(ctx);
                    return ReturnCode::SUCCESS;
                }

                i += consumed;
                matched = true;
                break;
            }
        }

        if (!matched) {
            std::cerr << "Unknown option: " << arg << "\n";
            return ReturnCode::UNKNOWN_OPTION;
        }
    }

    // 只执行被激活的非即时命令
    for (ICommand* cmd : ctx.getActivatedCommands()) {
        if (!cmd->isImmediate()) {
            auto ret = cmd->execute(ctx);
            if (ret != ReturnCode::SUCCESS) {
                return ret;
            }
        }
    }

    return ReturnCode::SUCCESS;
}

void CommandLineParser::printHelp() const {
    auto& commands = CommandRegistry::getInstance().getCommands();
    for (const auto& cmd : commands) {
        std::cout << "  " << cmd->shortOpt();
        if (!cmd->longOpt().empty()) {
            std::cout << ", " << cmd->longOpt();
        }
        std::cout << "\n    " << cmd->description() << "\n\n";
    }
}

CommandLineParser gParser;