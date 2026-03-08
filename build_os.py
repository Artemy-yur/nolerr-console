import os

CYAN = "\033[36m"
GOLD = "\033[33m"
RESET = "\033[0m"
BOLD = "\033[1m"
RED = "\033[31m"
GREEN = "\033[32m"

SRCS = " ".join([
    "main.c",
    "file/workfiles.c",
    "additions/calculator/calculator.c",
    "additions/timenow.c",
    "additions/weather_module/wearth_get.c",
    "interface/interface.c",
    "additions/help/external_help.c",
    "additions/infos.c",
    "additions/notich/notich.cpp",
    "dependencies/dependencies_py.c",
    "user_settings/user_rights.c",
    "filesystem/filesystem.cpp",
    "additions/website_accessibility/accessibility.cpp"
])

INCLUDES = "-I. -Ilibraru"
start = "starts_nolerros.exe"

compiling = f"g++ {SRCS} {INCLUDES} -o {start} -lws2_32 -Wall -Wextra -g -lurlmon -lwinmm -std=c++17"

if os.system(compiling) != 0:
    print(f"{RED}---------------------------------{RESET}")
    print(f"{RED}    Compilation failed{RESET}")
    print(f"{RED}---------------------------------{RESET}")
    input("Press enter to continue")
else:
    print(f"{GREEN}---------------------------------{RESET}")
    print(f"{GREEN}  Compilation succeeded{RESET}")
    print(f"{GREEN}---------------------------------{RESET}")
    os.system(start)
    exit(0)
