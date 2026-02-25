// framework/command_interface.h
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

enum class ReturnCode {
    SUCCESS = 0,
    INVALID_ARGUMENT = 1,
    MISSING_ARGUMENT = 2,
    UNKNOWN_OPTION = 3,
    BUSINESS_ERROR = 4
};

namespace ArgConsumption {
    constexpr int OPTION_ONLY = 1;
    constexpr int OPTION_WITH_VALUE = 2;
    constexpr int ERROR = -1;
}

class ICommand;
class CommandContext {
public:
    void setProgramName(const std::string& name) { program_name_ = name; }
    const std::string& getProgramName() const { return program_name_; }
    void setVersion(const std::string& v) { version_ = v; }
    const std::string& getVersion() const { return version_; }
    void addParam(const std::string& key, const std::string& value) { params_[key] = value; }
    const auto& getParams() const { return params_; }
    void addActivatedCommand(ICommand* cmd) {
        activated_commands_.push_back(cmd);
    }
    const auto& getActivatedCommands() const {
        return activated_commands_;
    }

private:
    std::string program_name_;
    std::string version_;
    std::unordered_map<std::string, std::string> params_;
    std::vector<ICommand*> activated_commands_;
};

class ICommand {
public:
    virtual ~ICommand() = default;
    virtual int parse(CommandContext& ctx, const std::vector<std::string>& args, int idx) = 0;
    virtual ReturnCode execute(const CommandContext& ctx) = 0;
    virtual std::string shortOpt() const = 0;
    virtual std::string longOpt() const = 0;
    virtual std::string description() const = 0;
    virtual bool isImmediate() const { return false; }
};