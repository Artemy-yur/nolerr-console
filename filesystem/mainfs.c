//
// Created by Artemy on 20.02.2026.
//
#include <dirent.h>

#include "../sharedlibraries/global.h"
#include "../sharedlibraries/platform.h"

static const char *folders_name[]  = {
    "../Home",
    "../Moduls",
    "../File_work",
    "../notich",
    "operating_system",
    NULL
};
static void checking_folders(void);

static void checking_folders(void) {
    char *floader = malloc(sizeof(char) * 256);

    for (int i = 0; folders_name[i] != NULL; i++) {
        snprintf(floader, sizeof(char) * 256, "%s", folders_name[i]);
        if (ACCESS(floader) == 0) {
            if (MKDIR(floader) != 0) {
                perror("Failed to create directory");
            }
        }
    }
    free(floader);
}

void initialization_fs(void) {
    checking_folders();
}


