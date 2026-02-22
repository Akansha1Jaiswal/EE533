set -x

"C:\Yashu\USC\Academics\EE 533\Labs\Lab 6\Codes\arm-gnu-toolchain-15.2.rel1-mingw-w64-i686-arm-none-eabi\bin\arm-none-eabi-gcc.exe" -S bubble_sort.c -mcpu=arm7tdmi -marm
"C:\Yashu\USC\Academics\EE 533\Labs\Lab 6\Codes\arm-gnu-toolchain-15.2.rel1-mingw-w64-i686-arm-none-eabi\bin\arm-none-eabi-gcc.exe" -c bubble_sort.c -mcpu=arm7tdmi -marm
"C:\Yashu\USC\Academics\EE 533\Labs\Lab 6\Codes\arm-gnu-toolchain-15.2.rel1-mingw-w64-i686-arm-none-eabi\bin\arm-none-eabi-ld.exe" bubble_sort.o -Ttext=0x0 -o bubble_sort.elf
"C:\Yashu\USC\Academics\EE 533\Labs\Lab 6\Codes\arm-gnu-toolchain-15.2.rel1-mingw-w64-i686-arm-none-eabi\bin\arm-none-eabi-objcopy.exe" -O binary bubble_sort.elf bubble_sort.bin
"C:\Yashu\USC\Academics\EE 533\Labs\Lab 6\Codes\arm-gnu-toolchain-15.2.rel1-mingw-w64-i686-arm-none-eabi\bin\arm-none-eabi-objdump.exe" -d bubble_sort.elf