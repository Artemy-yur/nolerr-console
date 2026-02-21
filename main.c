/*
 * Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */

#include "functions.h"
#include "sharedlibraries/global.h"
#include "sharedlibraries/platform.h"

static void wait_for_enter(void) {
    printf("\nНажмите Enter для продолжения...");
    getchar();
}

void execute_choice(int choice)
{
    switch (choice)
    {
    case 1:
        menu_file();
        break;
    case 2:
        actions();
        break;
    case 3:
        times();
        break;
    case 4:
         getWearth();
         wait_for_enter();
         break;
    case 5:
        python_help();
        break;
    case 6:
        notich();
        getchar();
        break;
    case 7:
        listfile();
        break;
    case 8:
#ifdef _WIN32
        info_system();
#else
        printf("В linux системе пока не работает!");
        getchar();
        break;
#endif
        break;
    default:
        printf("Неизвестное действие!\n");
        printf("\nНажмите Enter для продолжения...");
        getchar();
        break;
    }
}


int main(void)
{
    //initialization_fs();
    //CLEAR;
    //check_dependencies();
    int first_choice = starts();
    execute_choice(first_choice);
    starts();
    return 0;
}
