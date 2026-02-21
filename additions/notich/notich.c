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

    printf("Нажмите 1 чтобы вывести текст, 2 чтобы написать новую, 3 чтобы выйти: ");

    while (true)
    {
        if (scanf("%hd", &v) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Введите число 1 до 3: ");
            continue;
        }
        if (v <= 3)
        {
            break;
        }
        printf("От 1 до 3: ");
    }

    switch (v)
    {
    case 1:
        read_notich();
        break;
    case 2:
        write_notich();
        break;
    case 3:
            starts();
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
    while (getchar() != '\n');
    return;
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
    notich();
}