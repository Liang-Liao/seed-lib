// main.cpp
#include "command_parser.h"
#include "command_interface.h"

int main(int argc, char* argv[]) {
    CommandContext ctx;
    ctx.setVersion("1.0.0");

    ReturnCode ret = gParser.parse(argc, argv, ctx);
    return static_cast<int>(ret);
}