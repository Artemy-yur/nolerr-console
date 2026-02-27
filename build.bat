@echo off
echo Building Ezy_OS project with GCC...

set SRCS=main.c^
 file/workfiles.c^
 additions/calculator/calculator.c^
 additions/timenow.c^
 additions/weather_module/wearth_get.c^
 interface/interface.c^
 additions/help/external_help.c^
 additions/infos.c^
 additions/notich/notich.c^
 dependencies/dependencies_py.c^
 user_settings/user_rights.c^
 filesystem/filesystem.cpp

set INCLUDES=-I. -Ilibraru

echo Compiling with GCC...
gcc %SRCS% %INCLUDES% -o starts_nolerros.exe -lws2_32 -Wall -Wextra -g -lurlmon -lwinmm -lstdc++

if %ERRORLEVEL% equ 0 (
    echo.
    echo --- Build successful! ---
    echo Executable created: starts_nolerros.exe
    echo.
    echo Python files are in their original locations:
    echo   - additions/help/external_help.py
    echo   - additions/wearth/show_current_weather.py
) else (
    echo.
    echo --- Build FAILED! ---
)
pause