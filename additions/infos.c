//
// Created by Artemy on 04.02.2026.
//
#include "../sharedlibraries/platform.h"
#include "../sharedlibraries/global.h"
#include "../functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- POSIX / UNIX includes ---
#if defined(__linux__) || defined(__APPLE__)
#include <sys/utsname.h>
#include <sys/resource.h>
#include <unistd.h>
#ifdef __linux__
#include <sys/sysinfo.h>
#endif
#ifdef __APPLE__
#include <mach/mach.h>
#include <sys/sysctl.h>
#endif
#endif

// --- Windows includes ---
#ifdef _WIN32
#include <windows.h>
#include <psapi.h>
#endif

typedef struct {
    char last_update[11];
    char version[15];
} date;

// --- CPU Info ---
static void cpu_info(void) {
#if defined(__linux__) || defined(__APPLE__)
    struct utsname buffer;
    if (uname(&buffer) == 0) {
        printf("Система: %s\n", buffer.sysname);
        printf("Узел: %s\n", buffer.nodename);
        printf("Релиз: %s\n", buffer.release);
        printf("Архитектура: %s\n", buffer.machine);
    }
    long nprocs = sysconf(_SC_NPROCESSORS_ONLN);
    printf("Процессоров (online): %ld\n", nprocs);
#elif _WIN32
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    printf("Процессоров: %u\n", si.dwNumberOfProcessors);
    printf("Тип процессора: %u\n", si.dwProcessorType);
    printf("Архитектура: %u\n", si.wProcessorArchitecture);
    switch (si.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_INTEL:   printf("x86\n"); break;
        case PROCESSOR_ARCHITECTURE_ARM:     printf("ARM\n"); break;
        case PROCESSOR_ARCHITECTURE_AMD64:   printf("AMD64\n"); break;
        default: printf("unknown\n"); break;
    }
#endif
}

// --- Memory Info (Hardware) ---
static void mem_info(void) {
#if defined(__linux__)
    struct sysinfo si;
    if (sysinfo(&si) == 0) {
        printf("Total RAM: %lu MB\n", (unsigned long)(si.totalram * si.mem_unit / (1024 * 1024)));
        printf("Free RAM: %lu MB\n", (unsigned long)(si.freeram * si.mem_unit / (1024 * 1024)));
    }
#elif defined(__APPLE__)
    int64_t memsize;
    size_t len = sizeof(memsize);
    if (sysctlbyname("hw.memsize", &memsize, &len, NULL, 0) == 0) {
        printf("Total RAM: %lld MB\n", memsize / (1024 * 1024));
    }
    
    // Получение свободной памяти на macOS
    mach_port_t host_port = mach_host_self();
    vm_size_t page_size;
    host_page_size(host_port, &page_size);
    
    vm_statistics64_data_t vm_stats;
    mach_msg_type_number_t count = HOST_VM_INFO64_COUNT;
    
    if (host_statistics64(host_port, HOST_VM_INFO64, (host_info64_t)&vm_stats, &count) == KERN_SUCCESS) {
        int64_t free_memory = (int64_t)vm_stats.free_count * page_size;
        printf("Free RAM: %lld MB\n", free_memory / (1024 * 1024));
    }
#elif _WIN32
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    if (GlobalMemoryStatusEx(&memInfo)) {
        printf("Total RAM: %llu MB\n", memInfo.ullTotalPhys / (1024 * 1024));
        printf("Free RAM: %llu MB\n", memInfo.ullAvailPhys / (1024 * 1024));
    }
#endif
}

// --- Process Memory Info ---
static void print_memory_info(void) {
#if defined(__linux__) || defined(__APPLE__)
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == 0) {
#ifdef __APPLE__
        long rss = usage.ru_maxrss / 1024;
#else
        long rss = usage.ru_maxrss;
#endif
        printf("Пиковый размер (RSS): %ld КБ\n", rss);
        printf("Мягких сбоев страниц: %ld\n", usage.ru_minflt);
        printf("Жестких сбоев страниц: %ld\n", usage.ru_majflt);
    }
#elif _WIN32
    PROCESS_MEMORY_COUNTERS pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
        const size_t KB = 1024;
        printf("Количество страничных сбоев: %lu\n", pmc.PageFaultCount);
        printf("Пиковый размер рабочего набора: %llu КБ\n", (unsigned long long)pmc.PeakWorkingSetSize / KB);
        printf("Размер рабочего набора: %llu КБ\n", (unsigned long long)pmc.WorkingSetSize / KB);
        printf("Использование файла подкачки: %llu КБ\n", (unsigned long long)pmc.PagefileUsage / KB);
    }
#endif
}

// --- Main System Info Entry Point ---
void info_system(void) {
    CLEAR;

    date now = {"22.02.2026", "Version 0.5"};

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