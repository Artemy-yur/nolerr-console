/*
* Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */
#include "../../libraru/initlibery.h"
#include "../../clearwin.h"

void getWearth(void) {
    // Используем system(), чтобы запустить скрипт и дождаться его завершения
    char *path = malloc(sizeof(char) * 20); 

    sprintf(path,"python3 additions/wearth/show_current_weather.py");
    int status = system(path);

   



    if (status == -1) {
        perror("Ошибка запуска show_current_weather.py");
    } else {

        printf("Возврат в основную программу.\n");

    }

    free(path);
}
