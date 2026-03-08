CC = gcc
CXX = g++

CFLAGS = -std=c2x -Wall -I. -I./sharedlibraries
CXXFLAGS = -std=c++17 -Wall -I. -I./sharedlibraries

# Флаги линковки
LDFLAGS = -lm -lstdc++

# Определяем ОС и добавляем соответствующие библиотеки
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    # Linux
    CFLAGS += -D__linux__
    CXXFLAGS += -D__linux__
    LDFLAGS +=
else ifeq ($(UNAME_S),Darwin)
    # macOS
    CFLAGS += -D__APPLE__
    CXXFLAGS += -D__APPLE__
    LDFLAGS +=
else
    # Windows (через MinGW)
    CFLAGS += -D_WIN32
    CXXFLAGS += -D_WIN32
    LDFLAGS += -lws2_32 -lurlmon -lwinmm
    # Отключаем предупреждения о pragma comment
    CFLAGS += -Wno-unknown-pragmas
    CXXFLAGS += -Wno-unknown-pragmas
endif

# Имя программы
PROGRAM = starts_nolerros

# Все исходники
SRCS = main.c \
       file/workfiles.c \
       additions/calculator/calculator.c \
       additions/timenow.c \
       interface/interface.c \
       additions/weather_module/wearth_get.c \
       additions/help/external_help.c \
       additions/notich/notich.c \
       language/locale_managere.c \
       dependencies/dependencies_py.c \
       user_settings/user_rights.c \
       filesystem/filesystem.cpp \
       additions/website_accessibility/accessibility.cpp

# Явно разделяем C и C++ файлы
C_SRCS = $(filter %.c,$(SRCS))
CPP_SRCS = $(filter %.cpp,$(SRCS))

# Генерируем объектные файлы
C_OBJS = $(C_SRCS:.c=.o)
CPP_OBJS = $(CPP_SRCS:.cpp=.o)
OBJS = $(C_OBJS) $(CPP_OBJS)

# По умолчанию собираем
all: $(PROGRAM)
	@echo "Сборка завершена!"
	./$(PROGRAM)

# Сборка программы
$(PROGRAM): $(OBJS)
	$(CXX) $(OBJS) -o $(PROGRAM) $(LDFLAGS)
	@echo "Исполняемый файл создан: $(PROGRAM)"

# Правило для сборки .o файлов из C
%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Правило для сборки .o файлов из C++
%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	rm -rf $(OBJS) $(PROGRAM)

.PHONY: all clean