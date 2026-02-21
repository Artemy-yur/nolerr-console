//
// Created by Artemy on 04.02.2026.
//
#include  "../sharedlibraries/platform.h"
#include "../sharedlibraries/global.h"
#include "../functions.h"


static void cpu_info(void) {
    SYSTEM_INFO si;
    GetSystemInfo(&si);

    printf("Процессоров: %u\n",si.dwNumberOfProcessors);
    printf("Тип процессора: %u\n",si.dwProcessorType);
    printf("Архетектура: %u\n",si.wProcessorArchitecture);

    switch (si.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_INTEL:
            printf("x86\n"); break;
        case PROCESSOR_ARCHITECTURE_ARM:
            printf("ARM\n"); break;
        case PROCESSOR_ARCHITECTURE_AMD64:
            printf("AMD64\n"); break;
        default: printf("unknown\n"); break;
    }

}

static void mem_info(void) {
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);

    DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
    DWORDLONG availPhysMem = memInfo.ullAvailPhys;

    printf("Total RAM: %llu MB\n", totalPhysMem / (1024 * 1024));
    printf("Free RAM: %llu MB\n", availPhysMem / (1024 * 1024));
}

static void print_memory_info() {
    PROCESS_MEMORY_COUNTERS pmc;

    if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
        const size_t KB = 1024;
        const size_t MB = 1024 * KB;

        printf("Количество страничных сбоев: %lu\n", pmc.PageFaultCount);
        printf("Пиковый размер рабочего набора: %llu КБ\n", (unsigned long long)pmc.PeakWorkingSetSize / KB);
        printf("Размер рабочего набора: %llu КБ\n", (unsigned long long)pmc.WorkingSetSize / KB);
        printf("Использование файла подкачки: %llu КБ\n", (unsigned long long)pmc.PagefileUsage / KB);
    }
}
typedef struct {
    char last_update[11];
    char version[15];
} date;

void info_system(void) {
    CLEAR;
    //russian_locale();

    date now = {"14.02.2026", "Version 0.4"};

    printf(F_BLUE "       \n");
    printf(F_BLUE "       " F_WHITE "Nolerr-OS " F_BLUE "\n");
    printf(F_BLUE "      \n" RESET);

    printf("\n" F_WHITE "--- СИСТЕМНАЯ ИНФОРМАЦИЯ ---\n" RESET);
    printf(F_BLUE "OS: " RESET "Nolerr-OS\n");
    printf(F_BLUE "Версия: " RESET "%s\n", now.version);
    printf(F_BLUE "Обновление: " RESET "%s\n", now.last_update);

    printf("\n" F_WHITE "--- ПАМЯТЬ ПРОЦЕССА ---\n" RESET);
    print_memory_info();

    printf("\n" F_WHITE "--- Информация о процессоре (CPU) ---\n" RESET);
    cpu_info();

    printf("\n" F_WHITE "--- ЖЕЛЕЗО (RAM) ---\n" RESET);
    mem_info();

    printf("\n" F_BLUE "------------------------------------------\n");
    printf(F_CYAN " [0]" RESET " Вернуться в главное меню\n");
    printf(F_BLUE "------------------------------------------\n" RESET);

    while (1) {
        short v;
        printf(F_WHITE " > " RESET);
        if (scanf("%hd", &v) != 1) {
            while(getchar() != '\n');
            continue;
        }
        if (v == 0) {
            SLEEP(1);
            CLEAR;
            starts();
            break;
        }
    }
}