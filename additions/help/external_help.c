/*
 * Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */
#include "../../sharedlibraries/global.h" 
#define PATH_SIZE 64

void python_help(void) {
    char *path = (char*) malloc(PATH_SIZE); 
    sprintf(path,"python3 additions/help/show_function_help.py");

    int status = system(path);

    if (status == -1) {
        perror("Ошибка запуска help.py");
    } else {

        printf("Возврат в основную программу.\n");

    }
    free(path);
}
