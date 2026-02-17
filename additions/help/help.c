/*
 * Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */
#include "../../libraru/initlibery.h"
#include "../../clearwin.h"
#define PATH_SIZE 64

void python_help(void) {
    char *path = malloc(PATH_SIZE); 
    sprintf(path,"python3 additions/help/help.py");

    int status = system(path);

    if (status == -1) {
        perror("Ошибка запуска help.py");
    } else {

        printf("Возврат в основную программу.\n");

    }
    free(path);
}
