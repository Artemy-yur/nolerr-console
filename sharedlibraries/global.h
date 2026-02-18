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


#ifdef __WIN32__
#include <io.h>
#include <windows.h>
#endif
#define LEN_ARR(arr) sizeof(arr) / sizeof(*arr)
