/*
 * Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */
#ifdef __APPLE__
#define SLEEP(x) sleep(x)
#define CLEAR system("clear");
#include <unistd.h>
#define ACCESS(x) (access(x, F_OK) == 0)
#define SLEEP(x) sleep(x)

#elif _WIN32

#include <windows.h>
#include <io.h>
#define SLEEP(x) Sleep((x) * 1000)
#define CLEAR system("cls");
#define ACCESS(x) (_access(x, 0) == 0)
#define F_OK 0
#include <conio.h>
#include <psapi.h>

#else
#include <unistd.h>
#define SLEEP(x) sleep(x)
#define CLEAR system("clear");
void actions(void);
#endif
