//
// Created by Артемий Юров  on 07.03.2026.
//
#include <iostream>
#include <string>
#include <cstdio>
#include "../../functions_cpp.h"

using namespace std;

static int test(const string& site) {
    char command[256];

#ifdef _WIN32
    snprintf(command, sizeof(command), "ping -n 4 %s", site.c_str());
#else
    snprintf(command, sizeof(command), "ping -c 4 %s", site.c_str());
#endif

    int res = system(command);

    return (res == 0) ? 0 : 1;
}

void accessibility() {
    short v;

    cout << "1. Проверка url на доступность.\n0. Выход" << endl;
    cin >> v;
    if (v == 1) {
        string site_url;

        cout << "Введите url сайта: ";
        cin >> site_url;
        int res = test(site_url);
        cout <<"Доступность сайта: "<< res << endl;
        return;
    }
    else if (v == 0) {
        return;
    }
    else{
        cout << "Неизвестное действие" << endl;
    }
}

