// framework/command_parser.h
#pragma once
#include "command_interface.h"
#include <vector>

class CommandLineParser {
public:
    ReturnCode parse(int argc, char* argv[], CommandContext& ctx);
    void printHelp() const;
};

extern CommandLineParser gParser; // È«¾ÖÊµÀý