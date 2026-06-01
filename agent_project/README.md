# Project Name

> [一句话描述项目是什么]

## 快速开始

```bash
# 安装依赖（示例）
npm install

# 运行
npm run dev
```

## 项目结构

```
.
├── .reasonix/          # Reasonix Agent 配置
│   ├── skills/         # 可复用 playbook
│   └── memories/       # 持久化记忆
├── AGENTS.md           # Agent 行为规范
├── REASONIX.md         # 项目描述文件
├── MEMORY.md           # 记忆索引（自动维护）
├── README.md           # 本文件
└── ...
```

## 与 Agent 协作

该项目配置了 **Reasonix Code** 作为编码助手。关键工作流：

| 命令 | 用途 |
|------|------|
| `/skill <name>` | 调用注册的 playbook |
| `/plan` | 进入计划模式（多步修改前审批） |
| `remember`/`forget` | 管理持久化记忆 |

详见 [AGENTS.md](./AGENTS.md) 了解 Agent 行为规则。

## 技术栈

_在此填写_

## 许可证

_在此填写_