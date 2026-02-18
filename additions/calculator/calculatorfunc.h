//
// Created by Artemy on 12.02.2026.
//

#ifndef CALCULATORFUNC_H 
#define CALCULATORFUNC_H
#include <stdio.h>
#include  "../../sharedlibraries/platform.h"


void actions(void);
void exit_f(void) {
    while (true) {
        short v;
        scanf("%hd", &v);
        while (getchar() != '\n');
        if (v == 0) {
            CLEAR;
            actions();
        }
    }
}
//calculator
static void power(void);
static void sqtr(void);
static void match_actions(void);
static void math_actions(void);
int starts(void);
#endif //EZY_OS_EXITFUNC_H