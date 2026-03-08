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
 additions/notich/notich.cpp^
 dependencies/dependencies_py.c^
 user_settings/user_rights.c^
 filesystem/filesystem.cpp^
 additions/website_accessibility/accessibility.cpp

set INCLUDES=-I. -Ilibraru

echo Compiling with GСС...

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