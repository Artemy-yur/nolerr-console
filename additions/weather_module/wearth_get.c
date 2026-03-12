/*
 * Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */
#include "../../sharedlibraries/global.h"
#include "../../functions.h"

#define PATH_SIZE 128

static const char *lib = "requests";

static void install_lib(void)
{
    char command[PATH_SIZE];

    snprintf(command, PATH_SIZE, "python3 -m pip install %s", lib);
    if (system(command) != 0)
    {
        fprintf(stderr, "[ERROR] Failed to install %s\n", lib);
    }
}

void getWearth(void)
{
    install_lib();

    char *path = (char *)malloc(PATH_SIZE);

    sprintf(path, "python3 additions/weather_module/show_current_weather.py");
    int status = system(path);

    if (status == -1)
    {
        perror("Ошибка запуска show_current_weather.py");
    }
    else
    {

        printf("Возврат в основную программу.\n");
    }

    free(path);
}
