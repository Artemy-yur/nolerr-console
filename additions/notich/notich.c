//
// Created by Artemy on 02.02.2026.
//
/*
 * Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */

#include <sys/stat.h>
#include "../../sharedlibraries/global.h"
#include "../../functions.h"
#include "../../sharedlibraries/platform.h"


int starts(void);
static void read_notich(void);
static void write_notich(void);

void notich(void)
{

    const char *filename = "../notich/notich.txt";

    // Проверка и создание файла
    if (access(filename, F_OK) != 0)
    {
        FILE *f = fopen(filename, "w");
        if (f)
            fclose(f);
    }

    short v = -1;

    printf("Нажмите 0 чтобы вывести текст, 1 чтобы написать новую: ");

    while (true)
    {
        if (scanf("%hd", &v) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Введите число 0 или 1: ");
            continue;
        }
        if (v == 0 || v == 1)
        {
            break;
        }
        printf("От 0 до 1: ");
    }

    switch (v)
    {
    case 0:
        read_notich();
        while (true)
        {
            short v;
            scanf("%hd", &v);
            if (v > 0)
            {
                break;
            }
        }
        CLEAR;
        starts();
        break;
    case 1:
        write_notich();
        CLEAR;
        starts();
        break;
    default:
        printf("Error");
    }
}

static void read_notich(void)
{
    FILE *f = fopen("notich.txt", "r");
    if (f == NULL)
    {
        perror("ERROR opening file");
        return;
    }

    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);

    if (fsize <= 0)
    {
        printf("Файл пуст\n");
        fclose(f);
        return;
    }

    rewind(f);
    char *buffer = (char *)malloc(fsize + 1);
    if (buffer == NULL)
    {
        perror("Memory allocation failed");
        fclose(f);
        return;
    }

    size_t read = fread(buffer, 1, fsize, f);
    buffer[read] = '\0';
    fclose(f);

    puts(buffer);
    free(buffer);
}

static void write_notich(void)
{
    FILE *f = fopen("notich.txt", "a");
    if (f == NULL)
    {
        perror("ERROR opening file");
        return;
    }

    printf("Введите текст (макс 511 символов): ");

    // Очистка stdin от предыдущего ввода (например, \n от scanf)
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    char buffer[512];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        fprintf(f, "%s", buffer);
    }

    fclose(f);
    printf("Текст сохранен\n");
}