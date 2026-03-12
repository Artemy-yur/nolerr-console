@echo off
echo Building Ezy_OS project with GCC...

set SRCS=
set SRCS=%SRCS% main.c
set SRCS=%SRCS% file/workfiles.c
set SRCS=%SRCS% additions/calculator/calculator.c
set SRCS=%SRCS% additions/timenow.c
set SRCS=%SRCS% additions/weather_module/wearth_get.c
set SRCS=%SRCS% interface/interface.c
set SRCS=%SRCS% additions/help/external_help.c
set SRCS=%SRCS% additions/infos.c
set SRCS=%SRCS% additions/notich/notich.cpp
set SRCS=%SRCS% dependencies/dependencies_py.c
set SRCS=%SRCS% user_settings/user_rights.c
set SRCS=%SRCS% filesystem/filesystem.cpp
set SRCS=%SRCS% additions/website_accessibility/accessibility.cpp

set INCLUDES=-I. -Ilibrary

echo Compiling with GCC...
gcc -x c++ %SRCS% %INCLUDES% -o starts_nolerros.exe -lws2_32 -Wall -Wextra -g -lurlmon -lwinmm -lstdc++ -std=c++17

if %ERRORLEVEL% equ 0 (
    echo.
    echo --- Build successful! ---
    echo Executable created: starts_nolerros.exe
    echo.
) else (
    echo.
    echo --- Build FAILED! ---
)
pause