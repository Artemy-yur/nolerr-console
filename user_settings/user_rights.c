//
// Created by Artemy on 25.02.2026.
//

#include "../sharedlibraries/platform.h"
#include "../sharedlibraries/global.h"

#define OWEN_READ   0b000001  // 1
#define OWEN_WRITE  0b000010  // 2
#define OWEN_CREAT  0b000100 //  4
#define OWEN_DELETE 0b001000 //  8


int starts(void);


void rightsSetup(void) {
    const char *rights[] = {
        "Выход\n",
        "full rights - доступны все функции.\n",
        "partially limited - доступно все кроме удаления\n",
        "limited - ограниченные запрещено все кроме чтения\n",
    };

    printf("Вы можете выбрать права пользователя.\n");
    while (1) {
        short v;
        CLEAR;

        for (short i = 0; i < LEN_ARR(rights); i++) {
            printf(F_BLUE "[" F_WHITE "%d" F_BLUE "]" RESET " %s", i, rights[i]);
        }
        printf(F_WHITE "Ваш выбор: " RESET);
        short res = scanf("%hd", &v);


        while (getchar() != '\n');

        if (res != 1) {
            printf("Ошибка! Введите число.\n");
            SLEEP(1); // Даем пользователю секунду прочитать ошибку
            continue;
        }

        switch (v) {
            case 1: {
                int right_user = OWEN_READ | OWEN_WRITE | OWEN_CREAT | OWEN_DELETE;
                FILE *fp = fopen("settings/rights.csv", "w");
                if (fp == NULL) {
                    perror("Ошибка открытия");
                }
                fprintf(fp, "%d", right_user);
                fclose(fp);

                printf("\nПрава установлены (код: %d)", right_user);
                SLEEP(2);
                break;
            }

            case 2: {
                int right_user = OWEN_READ | OWEN_WRITE | OWEN_CREAT;
                FILE *fp = fopen("settings/rights.csv", "w");
                if (fp == NULL) {
                    perror("Ошибка открытия");
                }
                fprintf(fp, "%d", right_user);
                fclose(fp);

                printf("\nПрава установлены (код: %d)", right_user);
                SLEEP(2);
                break;
            }
            case 3:
            {
                int right_user = OWEN_READ;
                FILE *fp = fopen("settings/rights.csv", "w");
                if (fp == NULL) {
                    perror("Ошибка открытия");
                }
                fprintf(fp, "%d", right_user);
                fclose(fp);

                printf("\nПрава установлены (код: %d)", right_user);
                SLEEP(2);
                break;
            }
            case 0:
                CLEAR;
                starts();
                break;
            default:
                printf("Неизвестное действие");
                continue;
        }
    }
}