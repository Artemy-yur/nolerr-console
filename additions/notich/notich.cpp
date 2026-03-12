//
// Created by Артемий Юров  on 08.03.2026.
//
#include <filesystem>
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <string>

#include "functions.h"
#include "../../functions_cpp.h"
#include "../../sharedlibraries/platform.h"

using namespace std;
namespace fs = std::filesystem;

static const string filename = "../notich/notich.txt";

static void read_notich(void);
static void write_notich();
static void append_notich();


static void append_notich() {

    string text;

    cout << "Введите текст для добавления:" << endl;
    getline(cin, text);

    if (text.empty()) return;

    ofstream outfile(filename, ios::app);
    if (outfile.is_open()) {
        outfile << text << endl;
        cout << "Текст добавлен" << endl;
        cin.ignore();
        CLEAR;
    }
}

extern "C"
{
    void notich_cpp() {
        short choice;

        cout << "Работа с заметкой: " << filename << endl;
        cout << "1. Прочитать заметку" << endl;
        cout << "2. Записать новую заметку" << endl;
        cout << "3. Дописать заметку" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";

        while (true) {
            cin >> choice;
            cin.ignore();
            switch (choice) {
                case 1:
                    read_notich();
                    break;
                case 2:
                    write_notich();
                    break;
                case 3:
                    append_notich();
                    break;
                case 0:
                    return;
                default:
                    cout << "Неверный выбор" << endl;
            }
        }
    }
}


static void write_notich(void) {
    string text;

    ofstream outfile(filename);

    cout << "Введите текст заметки (для завершения введите пустую строку):" << endl;
    getline(cin, text);
    if (text.empty()) return;

    if (outfile.is_open()) {
        outfile << text << endl;
        CLEAR;
        notich_cpp();
    }
    else {
        cerr << "Ошибка";
        cin.ignore();
        return;
    }
}
static void read_notich() {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cout << "Заметка пока пуста или файл не создан." << endl;
        return;
    }

    cout << "--- Содержимое заметки ---" << endl;
    string line;
    while (getline(infile, line)) {
        cout << line << endl;
    }
    cout << "--------------------------" << endl;
    infile.close();
}


