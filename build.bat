@echo off
echo Building Ezy_OS project with GCC...

set SRCS=main.c^
 file/workfiles.c^
 additions/calculator/calculator.c^
 additions/timenow.c^
 additions/wearth/wearth_get.c^
 interface/interface.c^
 additions/help/help.c^
 additions/infos.c^
 additions/notich/notich.c^
 language/locale_managere.c

set INCLUDES=-I. -Ilibraru

echo Compiling with GCC...
gcc %SRCS% %INCLUDES% -o Ezy_OS.exe -lws2_32 -Wall -Wextra -g

if %ERRORLEVEL% equ 0 (
    echo.
    echo --- Build successful! ---
    echo Executable created: Ezy_OS.exe
    echo.
    echo Python files are in their original locations:
    echo   - additions/help/help.py
    echo   - additions/wearth/show_current_weather.py
) else (
    echo.
    echo --- Build FAILED! ---
)
pause