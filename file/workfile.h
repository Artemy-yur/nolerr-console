//
// Created by Artemy on 12.02.2026.
//

#ifndef EZY_OS_WORKFILE_H
#define EZY_OS_WORKFILE_H
static void creatfile(const char *name);
static void readfile(const char *name);
static void writefile(const char *name);
static void deletefile(const char *name);
static void copyfile(const char *from, const char *to);
static void listfile_local(void);
static int right_get(void);
int starts(void);
#endif //EZY_OS_WORKFILE_H