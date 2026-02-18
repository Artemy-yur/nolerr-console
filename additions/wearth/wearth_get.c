/*
* Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */
#include "../../sharedlibraries/global.h"
#include "../../functions.h"

#define PATH_SIZE 64

void getWearth(void) {
    // Используем system(), чтобы запустить скрипт и дождаться его завершения
    char *path = malloc(PATH_SIZE); 

    sprintf(path,"python3 additions/wearth/show_current_weather.py");
    int status = system(path);

    if (status == -1) {
        perror("Ошибка запуска show_current_weather.py");
    } else {

        printf("Возврат в основную программу.\n");

    }

    free(path);
}
