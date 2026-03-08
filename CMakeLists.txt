cmake_minimum_required(VERSION 3.20)
project(Ezy_OS C)

set(CMAKE_C_STANDARD 23)

add_executable(Ezy_OS
        main.c
        file/workfiles.c
        additions/calculator/calculator.c
        additions/timenow.c
        interface/interface.c
        additions/infos.c
        language/locale_managere.c
        file/workfile.h
        additions/weather_module/wearth_get.c
        additions/help/external_help.c
        dependencies/dependencies_py.c
        user_settings/user_rights.c
        filesystem/filesystem.cpp
        additions/website_accessibility/accessibility.cpp
)

target_link_libraries(Ezy_OS ws2_32 urlmon winmm)
target_link_libraries(Ezy_OS ws2_32)

configure_file(additions/help/show_function_help.py ${CMAKE_CURRENT_BINARY_DIR}/show_function_help.py COPYONLY)
configure_file(additions/weather_module/show_current_weather.py ${CMAKE_CURRENT_BINARY_DIR}/show_current_weather.py COPYONLY)