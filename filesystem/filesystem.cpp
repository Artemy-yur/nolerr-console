#include <iostream>
#include <string>
#include <filesystem>
#include "../functions_cpp.h"

using namespace std;
namespace fs = std::filesystem;

const string folders_name[] = {
     "../Home",
    "../Moduls",
    "../File_work",
    "../notich",
    "settings",
    "operating_system"
};

static void checking_folders(void){
    for(const string i : folders_name){
        if(fs::is_directory(i));
        else{
            if(fs::create_directories(i));
            else{
                cerr << "Ошибка создания папки";
            }
        }   
    }
}

void initialization_fs(void){
    checking_folders();
}