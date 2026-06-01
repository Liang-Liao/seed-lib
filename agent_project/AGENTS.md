# 🤖 Agent 规范

> 定义本项目中 AI Agent（Reasonix Code 等）的行为规则、边界和约定。

## 工作原则

- **只读先于修改**：分析问题前先读取相关文件，不凭空猜测。
- **引用或闭嘴**：所有关于代码库的事实声明必须附带 `file:line` 来源。
- **不主动重构**：除非用户要求，不修改与当前任务无关的代码。
- **小步提交**：优先使用 `edit_file`/`multi_edit` 而非 `write_file` 覆盖。

## 项目边界

- Agent 不得修改 `.reasonix/` 下的自动维护文件（`MEMORY.md`、记忆文件）。
- Agent 不得修改依赖目录（`node_modules/`、`dist/`、`build/` 等）。
- Agent 生成的文件路径相对项目根目录。

## 技能注册

可在 `.reasonix/skills/` 下注册可重用 playbook，供后续会话通过 `run_skill` 或 `/skill` 调用。

## 记忆管理

使用 `remember` 工具持久化项目决策、用户偏好和重要反馈，存储在 `.reasonix/memories/`。

---

*首次初始化时间：$(date +%Y-%m-%d)*