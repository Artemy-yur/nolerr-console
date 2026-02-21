/*
* Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */

#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdio.h>
#include <stdlib.h>

// Определение платформы
#if defined(_WIN32) || defined(_WIN64)
    #define PLATFORM_WINDOWS 1
#elif defined(__APPLE__) || defined(__MACH__)
    #define PLATFORM_MAC 1
#elif defined(__linux__) || defined(__unix__) || defined(__unix)
    #define PLATFORM_UNIX 1
#endif

// Windows
#ifdef PLATFORM_WINDOWS
    #include <windows.h>
    #include <io.h>
    #include <direct.h>
    #include <conio.h>
    #include <psapi.h>
    #include <urlmon.h>

    #pragma comment(lib, "urlmon.lib")
    #pragma comment(lib, "winmm.lib")

    #define SLEEP(x) Sleep((x) * 1000)
    #define CLEAR system("cls")
    #define ACCESS(path) (_access(path, 0) == 0)
    #define F_OK 0
    #define MKDIR(x) _mkdir(x)
    #define PYTHON_CMD "python --version"
    #define CHECK 1

// macOS
#elif defined(PLATFORM_MAC)
    #include <unistd.h>
    #include <sys/stat.h>

    #define SLEEP(x) sleep(x)
    #define CLEAR system("clear")
    #define ACCESS(x) (access(x, F_OK) == 0)
    #define MKDIR(path) mkdir(path, 0775)
    #define PYTHON_CMD "python3 --version"
    #define CHECK 0

// Linux
#elif defined(PLATFORM_UNIX)
    #include <unistd.h>
    #include <sys/stat.h>

    #define SLEEP(x) sleep(x)
    #define CLEAR system("clear")
    #define ACCESS(x) (access(x, F_OK) == 0)
    #define MKDIR(path) mkdir(path, 0775)
    #define PYTHON_CMD "python3 --version"
    #ifndef _MSC_VER
        #define _mkdir(path) mkdir(path, 0775)
    #endif
    #define CHECK 1
#endif

// Общие определения
#ifndef F_OK
    #define F_OK 0
#endif

#ifndef PYTHON_CMD
    #define PYTHON_CMD "python3 --version"
#endif

#endif