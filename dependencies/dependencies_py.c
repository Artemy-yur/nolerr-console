//
// Created by Artemy on 20.02.2026.
//
#include "../sharedlibraries/platform.h"
#include <stdio.h>

static int check(void){
    return system(PYTHON_CMD " > /dev/null 2>&1");
}
static void install_py(void);

void check_dependencies()
{

    if (check() == CHECK)
    {
        printf("Python Установлен");
        return;
    }
    else
    {
        install_py();
    }
}

static void install_py(void)
{
#ifdef __WIN32__

    const char *python_url = "https://www.python.org/ftp/python/3.13.0/python-3.13.0-amd64.exe";
    const char *installer = "python_installer.exe";
    printf("Установка python...\n");

    HRESULT hr = URLDownloadToFileA(NULL, python_url, installer, 0, NULL);

    if (SUCCEEDED(hr))
    {

        FILE *pFile = fopen(installer, "rb");
        if (pFile) {
            fseek(pFile, 0, SEEK_END);
            long size = ftell(pFile);
            fclose(pFile);
            printf("Размер файла %.2f\n", size/(1024.0 * 1024.0));
        }


        SHELLEXECUTEINFOA shExecInfo = {0};
        shExecInfo.cbSize = sizeof(SHELLEXECUTEINFOA);
        shExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
        shExecInfo.hwnd = NULL;
        shExecInfo.lpVerb = "runas";
        shExecInfo.lpFile = installer;
        shExecInfo.lpParameters = "/quiet InstallAllUsers=1 PrependPath=1";
        shExecInfo.lpDirectory = NULL;
        shExecInfo.nShow = SW_HIDE;
        shExecInfo.hInstApp = NULL;

        if (ShellExecuteEx(&shExecInfo)) {
            printf("Установка запущена.\n");
            WaitForSingleObject(shExecInfo.hProcess, INFINITE);
            CloseHandle(shExecInfo.hProcess);
            printf("Установка завершена\n");
        }else {
            printf("Ошибка");
        }
    }
    else {
        printf("Ошибка при скачивании файла. Код ошибки: %lu\n", hr);
        printf("Пожалуйста, скачайте Python вручную с python.org\n");
    }
    remove(installer);

#elif __linux__
    printf("Установка Python...\n");

    // Проверяем какой пакетный менеджер используется
    if (system("which apt-get > /dev/null 2>&1") == 0)
    {
        // Debian/Ubuntu
        system("sudo apt-get update");
        system("sudo apt-get install -y python3 python3-pip");
    }
    else if (system("which yum > /dev/null 2>&1") == 0)
    {
        // RHEL/CentOS
        system("sudo yum install -y python3 python3-pip");
    }
    else if (system("which dnf > /dev/null 2>&1") == 0)
    {
        // Fedora
        system("sudo dnf install -y python3 python3-pip");
    }
    else if (system("which pacman > /dev/null 2>&1") == 0)
    {
        // Arch Linux
        system("sudo pacman -Sy --noconfirm python python-pip");
    }
    else
    {
        printf("Не удалось определить пакетный менеджер\n");
        printf("Пожалуйста установите Python вручную\n");
    }

#elif __APPLE__
    printf("Установка Python для macOS...\n");

    // Проверяем наличие Homebrew
    if (system("which brew > /dev/null 2>&1") == 0) {
        printf("Установка через Homebrew...\n");
        system("brew install python3");
    } else {
        printf("Homebrew не найден. Установка через официальный установщик...\n");
        printf("Скачивание Python для macOS...\n");
        system("curl -O https://www.python.org/ftp/python/3.13.0/python-3.13.0-macos11.pkg");
        printf("Запуск установщика...\n");
        system("sudo installer -pkg python-3.13.0-macos11.pkg -target /");
        system("rm python-3.13.0-macos11.pkg");
    }

#endif
}
