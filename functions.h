/*
 * Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */
#pragma once


void listfile(void);


void actions(void);

//time
void times(void);

//wearth
void getWearth(void);

//interface
int start(void);
void python_help(void);
int starts(void);
void russian_locale(void);
void menu_file(void);

void notich(void);

void info_system(void);


#define F_BLUE    "\033[1;34m" // Основной синий
#define F_CYAN    "\033[1;36m" // Светло-голубой
#define F_WHITE   "\033[1;37m" // Жирный белый
#define F_BOLD    "\033[1m"    // Просто жирный
#define RESET     "\033[0m"
