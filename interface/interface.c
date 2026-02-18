/*
 * Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */

#include "../sharedlibraries/global.h"
#include "../sharedlibraries/platform.h"
#include  "interface.h"

#define MAX_CHOICE 8
#define MIN_CHOICE 1

#define LEN_ARR(arr) sizeof(arr)/sizeof(*arr)

void execute_choice(int choice);


void wait_for_enter(void) {
    printf("\nНажмите Enter для продолжения...");
    getchar();
}

int starts(void) {
    int choice;

    while (1) {
        CLEAR;
        printf(F_WHITE "Главное меню" F_CYAN RESET "\n");
        printf(F_BLUE "------------------------------------------" RESET "\n");

        const char *vibor[] = {
            "Работа над файлом", "Математика", "Время сейчас", "Погода",
            "Справка (Help)", "Заметка", "Все файлы", "Инфо о системе"
        };

        for (int i = 0; i < LEN_ARR(vibor); i++) {
            printf(F_BLUE "[" F_WHITE "%d" F_BLUE "]" RESET " %s\n", i + 1, vibor[i]);
        }

        printf(F_BLUE "------------------------------------------" RESET "\n");
        printf(F_WHITE "0." RESET " Выход\n\n");
        printf(F_BOLD "nolerr@user" RESET ":" F_BLUE "~" RESET "$ ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        if (choice == 0) {
            CLEAR(2);
            printf("До свидания!\n");
            exit(0);
        }

        if (choice < MIN_CHOICE || choice > MAX_CHOICE) {
            printf(F_BLUE "[" F_WHITE "!" F_BLUE "]" RESET " Ошибка: Выберите 1-8\n");
            getchar();
            continue;
        }

        execute_choice(choice);
    }
}
