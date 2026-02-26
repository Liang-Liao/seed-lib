#pragma once
#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <vector>

class StringUtils {
public:
    // 字符串分割函数
    static std::vector<std::string> split(const std::string& str, char delimiter);
    static std::vector<std::string> split(const char* str, char delimiter);

    // 字符串拼接函数
    static std::string join(const std::vector<std::string>& parts, const std::string& delimiter);
    static std::string join(const std::vector<const char*>& parts, const std::string& delimiter);

    // 字符串去除首尾空白字符
    static std::string trim(const std::string& str);
    static std::string trim(const char* str);

    // 字符串大小写转换
    static std::string toUpperCase(const std::string& str);
    static std::string toUpperCase(const char* str);
    static std::string toLowerCase(const std::string& str);
    static std::string toLowerCase(const char* str);

    // 字符串替换函数
    static std::string replace(const std::string& str, const std::string& from, const std::string& to);
    static std::string replace(const char* str, const char* from, const char* to);

    // 判断字符串是否为空或仅包含空白字符
    static bool isEmptyOrWhitespace(const std::string& str);
    static bool isEmptyOrWhitespace(const char* str);
};

#endif // STRING_UTILS_H