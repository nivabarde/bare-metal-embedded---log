# Bare-Metal Embedded C — Learning Log

Documenting my progress through bare-metal ARM Cortex-M development on an
STM32 Nucleo board — no HAL, no CubeMX-generated code, just the datasheet,
reference manual, and direct register access.

Each week pairs a write-up on my Substack with the actual working code and
commit history here. This is meant to be followed start to finish — concepts
build on each other week over week.

📝 Substack: [Bare Metal Embedded Log](https://nivabarde.substack.com)

## Tools
- Board: [your exact Nucleo board, e.g. Nucleo-F401RE]
- IDE/Toolchain: STM32CubeIDE
- No HAL — all peripheral access via manually defined registers/structs

## Progress

| Week | Topic | Post | Code |
|------|-------|------|------|
| 1 | Registers, Not Magic — toolchain setup, documentation, memory-mapped I/O, first GPIO blink via direct registers | [Post](https://nivabarde.substack.com/p/bare-metal-embedded-led-toggle) | [week1-led-toggle](./week1-led-toggle) |
