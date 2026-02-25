/*
 * Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */
#pragma once

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>

void execute_choice(int choice);

#ifdef __WIN32__
#include <io.h>
#include <windows.h>
#endif
#define LEN_ARR(arr) sizeof(arr) / sizeof(*arr)


#define F_BLUE    "\033[1;34m" // Основной синий
#define F_CYAN    "\033[1;36m" // Светло-голубой
#define F_WHITE   "\033[1;37m" // Жирный белый
#define F_BOLD    "\033[1m"    // Просто жирный
#define RESET     "\033[0m"
