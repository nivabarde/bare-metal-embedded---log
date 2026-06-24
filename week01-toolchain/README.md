 Week 1 — Toolchain Setup + First GPIO Blink


 What this does

Sets up the bare-metal STM32 toolchain (STM32CubeIDE, no HAL, no CubeMX-generated

code) and blinks the onboard LED using direct register access — manually defined

addresses for RCC and GPIOA registers.



What I learned / what broke

\- \[Replace this line with what actually happened — e.g. "LED didn't turn on at

&#x20; first because I forgot to enable the GPIOA clock in RCC\_AHB1ENR before

&#x20; touching MODER."]

\- \[Add a second line if there's another thing worth mentioning]



 Concepts covered

\- Toolchain setup (compiler, debugger, IDE vs. HAL distinction)

\- Datasheet vs. Reference Manual — what each is for

\- Memory-mapped I/O — peripherals as fixed memory addresses

\- Manually computing register addresses (base address + offset)

\- Direct register access using #define + volatile pointers


 Reference

\- \[Your exact MCU, e.g. STM32F401RE] Reference Manual — GPIO chapter

&#x20; (RCC\_AHB1ENR, GPIOx\_MODER, GPIOx\_ODR)



\## Full write-up

\[Post 1: Registers, Not Magic](your-substack-link-here)

