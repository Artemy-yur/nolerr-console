/*
 * Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */

#include  "../sharedlibraries/platform.h"
#include "../sharedlibraries/global.h"
#include "../functions.h"
#include "workfile.h"
#include <dirent.h>
#include <errno.h>

#define MAX_CHOICE 7
#define MIN_CHOICE 1

#define NAME_LEN 20


int right_get(void) {
    int n;
    FILE *cfg_file = fopen("settings/rights.csv", "r");
    if (cfg_file == NULL) {
        fprintf(stderr, "Ошибка открытия: %s (код: %d)\n", strerror(errno), errno);
    }
    fscanf(cfg_file, "%d", &n);
    fclose(cfg_file);
    return n;
}


void menu_file(void) {

    const short right = right_get();

    printf("1. Создать файл\n2. Прочитать содержимое\n3. Внести текст в файл\n4. Удалить файл\n5. Копировать файл\n6. Все файлы\n7. Выход в меню\n");

    short v;
    while(1) {
        printf(F_BOLD "  user@nolerr" RESET ":" F_BLUE "~" RESET "$ ");

        if(scanf("%hd", &v) != 1) {
            while(getchar() != '\n');
            printf(F_CYAN "  [!] Ошибка: введите число" RESET "\n");
            continue;
        }

        if(v > MAX_CHOICE || v < MIN_CHOICE) {
            printf(F_CYAN "  [!] Число должно быть от 1 до 7" RESET "\n");
        }
        else {
            break;
        }
    }

    switch (v) {
        case 1: {
            if (right <= 7) {
                printf("У вас недостаточно прав");
                SLEEP(2);
                break;
            }
            char name[NAME_LEN];
            char path_file[NAME_LEN + 20];

            printf("Enter your namefile: ");
            scanf("%s", name);
            sprintf(path_file, "../File_work/%s", name);

            creatfile(path_file);
            break;
        }
        case 2: {
            if (right < 1) {
                printf("У вас недостаточно прав");
                SLEEP(2);
                break;
            }
            char name[NAME_LEN];
            char path_file[NAME_LEN + 20];

            printf("Enter your namefile: ");
            scanf("%s", name);
            sprintf(path_file, "../File_work/%s", name);

            readfile(path_file);
            break;
        }
        case 3: {
            if (right <= 7) {
                printf("У вас недостаточно прав");
                SLEEP(2);
                break;
            }
            char name[NAME_LEN];
            char path_file[NAME_LEN + 20];

            printf("Enter your namefile: ");
            scanf("%s", name);
            sprintf(path_file, "../File_work/%s", name);

            writefile(path_file);
        }
        case 4: {
            if (right < 8) {
                printf("У вас недостаточно прав");
                SLEEP(2);
                break;
            }
            char name[NAME_LEN];
            char path_file[NAME_LEN + 20];

            printf("Enter your namefile: ");
            scanf("%s", name);
            sprintf(path_file, "../File_work/%s", name);

            deletefile(path_file);
        }
        case 5: {
            char name1[NAME_LEN], name2[NAME_LEN];
            char path_file1[NAME_LEN + 20],path_file2[NAME_LEN + 20];

            printf("Enter your namefile 1 and file 2: ");
            scanf("%s %s", name1,name2);
            sprintf(path_file1, "../File_work/%s", name1);
            sprintf(path_file2, "../File_work/%s", name2);

            copyfile(name1, name2);
        }
        case 6: {
            listfile_local();
        }
        case 7: {
            CLEAR;
            starts();
            return;
        }
        default: {
            printf("Error");
        }
    }

}

void creatfile(const char *name) {
    FILE *file = fopen(name, "w");
    if (file != NULL) {
        printf("File %s created successfully\n", name);
        fclose(file);
        CLEAR;
        menu_file();
    } else {
        perror("Error creating file");
    }
}

void readfile(const char *name) {
    FILE *file = fopen(name, "r");
    if (file != NULL) {
        perror("error read file");
    }
    int c;
    while ((c = fgetc(file)) != EOF) { // Чтение до конца
        printf("%c", c);
    }

    fclose(file);
    short v;

    printf("Press 0 to exit: ");

    while (true) {
        scanf("%hd", &v);
        while (getchar() != '\n');
        if (v == 0) {
            CLEAR;
            menu_file();
        }
    }

}
void writefile(const char *name) {
    FILE *file = fopen(name, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Write text (press Enter twice to finish):\n");

    char buffer[1000];
    while (getchar() != '\n');


    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Убираем символ новой строки в конце
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }

        // Записываем в файл
        fprintf(file, "%s\n", buffer);
        printf("Text written to file %s\n", name);
    }

    fclose(file);
    SLEEP(1);
    CLEAR;
    menu_file();
}

void deletefile(const char *name) {
    if (remove(name) == 0) {
        puts("File deleted");
    }
    else {
        perror("error delete");
    }
    SLEEP(3);
    CLEAR;
    menu_file();
}

void copyfile(const char *from, const char *to) {
    FILE *file = fopen(from, "rb"); 
    if (file == NULL) {  
        perror("Error opening source file");
        return;
    }
    
    FILE *file2 = fopen(to, "wb");  
    if (file2 == NULL) {
        perror("Error opening destination file");
        fclose(file);
        return;
    }
    printf("Copying file to %s\n", to);

    // Get file size
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    
 
    if (length == 0) {
        fclose(file);
        fclose(file2);
        return;
    }

    char *buffer = malloc(length);
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        fclose(file2);
        return;
    }

    size_t bytes_read = fread(buffer, 1, length, file);
    if (bytes_read != length) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        fclose(file2);
        return;
    }
    fclose(file);

    size_t bytes_written = fwrite(buffer, 1, length, file2);
    if (bytes_written != length) {
        perror("Error writing file");
    }

    free(buffer);
    fclose(file2);
    short v;

    printf("Press 0 to exit: ");

    while (true) {
        scanf("%hd", &v);
        while (getchar() != '\n');
        if (v == 0) {
            CLEAR;
            menu_file();
        }
    }
}

void listfile(void) {
    DIR *listdir = opendir("../");
    if (listdir == NULL) {
        perror("Error in opendir()");
        return;
    }

    short i = 0;
    struct dirent *filelist;

    while ((filelist = readdir(listdir)) != NULL) {
            printf("%d - [FILE] %s\n", i, filelist->d_name);
        i++;
    }
    printf("\n");

    short v;

    printf("Press 0 to exit: ");

    while (true) {
        scanf("%hd", &v);
        while (getchar() != '\n');
        if (v == 0) {
            closedir(listdir);
            starts();
        }
    }
}
void listfile_local(void) {
    DIR *listdir = opendir("../File_work");
    if (listdir == NULL) {
        perror("Error");
        SLEEP(3);
        return;
    }
    short i = 0;
    struct dirent *filelist;
    while ((filelist = readdir(listdir)) != NULL) {
        printf("%d - [FILE] %s\n", i, filelist->d_name);
        i++;
    }


    short v;

    printf("Press 0 to exit: ");

    while (true) {
        scanf("%hd", &v);
        while (getchar() != '\n');
        if (v == 0) {
            closedir(listdir);
            CLEAR;
            menu_file();
        }
    }

}