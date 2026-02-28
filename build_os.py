import os
from colorama import *

SRCS = " ".join([
    "main.c",
    "file/workfiles.c",
    "additions/calculator/calculator.c",
    "additions/timenow.c",
    "additions/weather_module/wearth_get.c",
    "interface/interface.c",
    "additions/help/external_help.c",
    "additions/infos.c",
    "additions/notich/notich.c",
    "dependencies/dependencies_py.c",
    "user_settings/user_rights.c",
    "filesystem/filesystem.cpp"
])
INCLUDES =  "-I. -Ilibraru"
start = "starts_nolerros.exe"
Compiling  = f"gcc {SRCS} {INCLUDES} -o starts_nolerros.exe -lws2_32 -Wall -Wextra -g -lurlmon -lwinmm -lstdc++"



if os.system(Compiling) != 0:
    print(Fore.RED,"---------------------------------",Fore.RESET)
    print(Fore.RED,"    Compilation failed",Fore.RESET)
    print(Fore.RED, "---------------------------------", Fore.RESET)
    input("press enter to continue")
else:
    print(Fore.GREEN, "---------------------------------", Fore.RESET)
    print(Fore.GREEN,"  Compilation succeeded",Fore.RESET)
    print(Fore.GREEN, "---------------------------------", Fore.RESET)
    os.system(start)
    exit(0)