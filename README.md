# seed-lib — 工程种子库

> 一套积累的工程种子（boilerplate / starter / library），方便快速开启新项目或复用已验证的代码模块。

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

---

## 目录

- [概览](#概览)
- [子项目](#子项目)
  - [agent_project — AI Agent 项目模板](#agent_project--ai-agent-项目模板)
  - [cmdparser — C++ 命令行解析框架](#cmdparser--c-命令行解析框架)
  - [ffmpeg_read — FFmpeg 源码级开发环境搭建指南](#ffmpeg_read--ffmpeg-源码级开发环境搭建指南)
  - [stringutils — C++ 字符串工具库](#stringutils--c-字符串工具库)
  - [taskqueue — C++ 线程安全任务队列](#taskqueue--c-线程安全任务队列)
- [许可证](#许可证)

---

## 概览

每当我们开启一个新工程，总有一些基础设施需要重复搭建：项目结构、构建配置、CLI 参数解析、字符串处理、任务调度 ……

**seed-lib** 把这些经过验证的代码积累成"种子"，每个种子独立、可复用、开箱即用。

| 种子 | 语言 | 用途 |
|------|------|------|
| agent_project | 模板 (Reasonix) | AI 编码助手项目脚手架 |
| cmdparser | C++ | 命令行参数解析框架 |
| ffmpeg_read | 文档 | FFmpeg 源码开发环境搭建 |
| stringutils | C++ | 字符串处理函数集合 |
| taskqueue | C++ (模板) | 线程安全的任务队列 |

---

## 子项目

### agent_project — AI Agent 项目模板

基于 **Reasonix Code** 的 AI 编码助手项目骨架。

```
agent_project/
├── .reasonix/
│   ├── skills/          # 可复用的 playbook
│   └── memories/        # 持久化记忆
├── .vscode/             # 编辑器配置
├── scripts/
│   ├── dev.sh           # 开发启动脚本（占位）
│   ├── lint.sh          # 语法检查脚本（占位）
│   └── test.sh          # 测试运行脚本（占位）
├── src/                 # 源码目录（空）
├── tests/               # 测试目录（空）
├── AGENTS.md            # Agent 行为规范
├── REASONIX.md          # 项目描述与 Agent 规范
└── MEMORY.md            # 持久化记忆索引（自动维护）
```

**快速上手：**

```bash
cd agent_project
# 添加你的代码到 src/ 和 tests/
# 接入具体 dev/lint/test 命令（参考对应脚本中的注释）
```

---

### cmdparser — C++ 命令行解析框架

一个轻量的 C++ 命令行解析框架，支持子命令、短/长选项、即时命令等特性。

```
cmdparser/
└── cmdparser/
    ├── command_interface.h     # ICommand 接口 + CommandContext
    ├── command_parser.h/cpp    # CommandLineParser 主解析器
    ├── command_registry.h/cpp  # CommandRegistry 单例注册中心
    ├── file_command.h/cpp      # 文件操作命令示例
    ├── help_command.h/cpp      # 帮助命令
    ├── version_command.h/cpp   # 版本命令
    └── main.cpp                # 入口
```

**核心设计：**

- `ICommand` — 命令接口，定义 `parse()`、`execute()`、`shortOpt()`、`longOpt()`、`description()`
- `CommandRegistry` — 单例模式，统一管理命令注册
- `CommandLineParser` — 入口解析器，按注册顺序匹配参数
- `ReturnCode` — 枚举返回码（成功、参数错误、未知选项等）

**构建：**

使用 CMake 或 Visual Studio 均可：

```bash
cd cmdparser
mkdir build && cd build
cmake ..
cmake --build .
./cmdparser --help
```

---

### ffmpeg_read — FFmpeg 源码级开发环境搭建指南

一份详细的中文指南，教你如何在 **Windows 上的 VSCode** 中搭建 **FFmpeg 源码级开发学习环境**。

内容涵盖：
- 工具链准备
- VSCode 配置（`.vscode/c_cpp_properties.json`、`launch.json`、`tasks.json` 已预配）
- 代码跳转、编译、调试的完整流程

👉 详见 [ffmpeg_read/](ffmpeg_read/)

---

### stringutils — C++ 字符串工具库

一组静态字符串操作函数，仅依赖 C++ 标准库，无外部依赖。

**函数清单：**

| 函数 | 说明 |
|------|------|
| `split(str, delimiter)` | 按分隔符分割字符串 |
| `join(parts, delimiter)` | 用分隔符拼接字符串列表 |
| `trim(str)` | 去除首尾空白字符 |
| `toUpperCase / toLowerCase` | 大小写转换 |
| `replace(str, from, to)` | 子串替换 |
| `isEmptyOrWhitespace` | 判断空串或纯空白串 |

**用法：**

```cpp
#include "StringUtils.h"

auto parts = StringUtils::split("a,b,c", ',');
auto joined = StringUtils::join(parts, "|");
auto trimmed = StringUtils::trim("  hello  ");
auto upper = StringUtils::toUpperCase("hello");
```

---

### taskqueue — C++ 线程安全任务队列

基于 C++11 的泛型线程安全任务队列，使用 `std::mutex` + `std::condition_variable` 实现。

```
taskqueue/
└── TaskQueue.hpp          # 仅头文件，即拷即用
```

**API：**

| 方法 | 说明 |
|------|------|
| `enqueue(shared_ptr<T>)` | 入队，通知等待者 |
| `dequeueWithTimeout(ms)` | 带超时的出队，超时返回 nullptr |
| `isEmpty()` | 队列是否为空 |

**用法：**

```cpp
#include "TaskQueue.hpp"

TaskQueue<int> queue;
queue.enqueue(std::make_shared<int>(42));

auto task = queue.dequeueWithTimeout(1000);
if (task) {
    // 处理 *task
}
```

---

## 许可证

[MIT License](LICENSE) © 2026 Liang