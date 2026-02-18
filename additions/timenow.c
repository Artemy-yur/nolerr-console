/*
 * Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */

#include "../sharedlibraries/global.h"
#include "../functions.h"
#include  "../sharedlibraries/platform.h"

#ifdef _WIN32
#include  "../sharedlibraries/platform.h"

#else
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

int _kbhit(void)
{
    struct timeval tv = {0L, 0L};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}


int _getch(void)
{
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}
#endif


void times(void)
{

    printf("Нажмите любую клавишу, чтобы выйти в меню...\n");

    while (1)
    {
        // Проверка: если нажата клавиша — выходим из цикла
        if (_kbhit())
        {
            _getch(); // Очищаем буфер нажатия
            break;    // Выход из цикла while
        }

        time_t mytime = time(NULL);
        struct tm *now = localtime(&mytime);

        CLEAR;
        printf("Date: %02d.%02d.%d\n", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
        printf("Time: %02d:%02d:%02d\n", now->tm_hour, now->tm_min, now->tm_sec);

        SLEEP(1);
    }

    // Вместо завершения программы просто возвращаемся в начало
    CLEAR;
    starts();
}