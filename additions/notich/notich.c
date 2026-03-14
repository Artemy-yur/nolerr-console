
#include "../../functions.h"
#include "../../sharedlibraries/platform.h"

static const char *filename = "../notich/notich.txt";

static const char *work_notich[] = {
    "Работа с заметкой: ",
    "1. Прочитать заметку",
    "2. Записать новую заметку",
    "3. Дописать заметку",
    "0. Выход",
    "Выберите действие: ",

};

//static void read_notich(void);
static void write_notich(void);
static void append_notich(void);


void notich() {
    short choice;

    CLEAR;

    for (size_t i = 0; i < sizeof(work_notich) / sizeof(*work_notich); ++i) {
        printf("%s\n", work_notich[i]);
    }


    while (true) {
        scanf("%hd", &choice);

        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        if (0 <= choice && choice <= sizeof(work_notich) / sizeof(*work_notich)) {
            switch (choice) {
                case 1:
                    //read_notich();

                    break;
                case 2:
                    write_notich();
                    break;
                case 3:
                    append_notich();
                    break;
                case 0:
                    CLEAR;
                    starts();
                    return;
                default:
                    printf("Неверный выбор");
            }
            break;
        }
    }
}

void write_notich() {
    char *text = NULL;
    char buffer[256];
    size_t total_length = 0;

    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        perror("Error occurs during write");
        return;
    }
    printf("Введите текст заметки (для завершения введите пустую строку):\n");

    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }


        if (buffer[0] == '\n') {
            break;
        }


        size_t line_length = strlen(buffer);
        char *new_text = (char*)realloc(text, total_length + line_length + 1);

        if (new_text == NULL) {
            printf("Ошибка выделения памяти!\n");
            free(text);
            fclose(f);
            return;
        }

        text = new_text;

        strcpy(text + total_length, buffer);
        total_length += line_length;
    }
    fprintf(f, "%s", text);

    free(text);

    return;
}

void append_notich() {
    FILE *f = fopen(filename, "a");
    if (f == NULL) {
        perror("Error occurs during append");
        return;
    }
    char *text = NULL;
    char buffer[256];
    size_t total_length = 0;


    printf("Введите дополнение заметки (для завершения введите пустую строку):\n");

    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }


        if (buffer[0] == '\n') {
            break;
        }


        size_t line_length = strlen(buffer);
        char *new_text = (char*)realloc(text, total_length + line_length + 1);

        if (new_text == NULL) {
            printf("Ошибка выделения памяти!\n");
            free(text);
            return;
        }

        text = new_text;

        strcpy(text + total_length, buffer);
        total_length += line_length;
    }
    fprintf(f, "\n%s", text);

    free(text);

    return;
}
