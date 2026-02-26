#include "StringUtils.h"
#include <algorithm>
#include <cctype>
#include <sstream>

// 分割字符串
std::vector<std::string> StringUtils::split(const std::string& str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}

std::vector<std::string> StringUtils::split(const char* str, char delimiter) {
    return split(std::string(str), delimiter);
}

// 拼接字符串
std::string StringUtils::join(const std::vector<std::string>& parts, const std::string& delimiter) {
    std::string result;
    for (size_t i = 0; i < parts.size(); ++i) {
        result += parts[i];
        if (i != parts.size() - 1) {
            result += delimiter;
        }
    }
    return result;
}

std::string StringUtils::join(const std::vector<const char*>& parts, const std::string& delimiter) {
    std::vector<std::string> converted(parts.begin(), parts.end());
    return join(converted, delimiter);
}

// 去除首尾空白字符
std::string StringUtils::trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

std::string StringUtils::trim(const char* str) {
    return trim(std::string(str));
}

// 转换为大写
std::string StringUtils::toUpperCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

std::string StringUtils::toUpperCase(const char* str) {
    return toUpperCase(std::string(str));
}

// 转换为小写
std::string StringUtils::toLowerCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::string StringUtils::toLowerCase(const char* str) {
    return toLowerCase(std::string(str));
}

// 替换子字符串
std::string StringUtils::replace(const std::string& str, const std::string& from, const std::string& to) {
    std::string result = str;
    size_t pos = 0;
    while ((pos = result.find(from, pos)) != std::string::npos) {
        result.replace(pos, from.length(), to);
        pos += to.length();
    }
    return result;
}

std::string StringUtils::replace(const char* str, const char* from, const char* to) {
    return replace(std::string(str), std::string(from), std::string(to));
}

// 判断是否为空或仅包含空白字符
bool StringUtils::isEmptyOrWhitespace(const std::string& str) {
    return str.empty() || str.find_first_not_of(" \t\n\r") == std::string::npos;
}

bool StringUtils::isEmptyOrWhitespace(const char* str) {
    return isEmptyOrWhitespace(std::string(str));
}