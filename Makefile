# Компилятор
CC = gcc


CFLAGS = -std=c2x -Wall -I. -I./sharedlibraries

# Флаги линковки
LDFLAGS = -lm

# Определяем ОС и добавляем соответствующие библиотеки
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    # Linux
    CFLAGS += -D__linux__
    LDFLAGS +=
else ifeq ($(UNAME_S),Darwin)
    # macOS
    CFLAGS += -D__APPLE__
    LDFLAGS +=
else
    # Windows (через MinGW)
    CFLAGS += -D_WIN32
    LDFLAGS += -lws2_32 -lurlmon -lwinmm
    # Отключаем предупреждения о pragma comment
    CFLAGS += -Wno-unknown-pragmas
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
       filesystem/mainfs.c

# Собираем все .o файлы из .c
OBJS = $(SRCS:.c=.o)

# По умолчанию собираем
all: $(PROGRAM)
	@echo "Сборка завершена!"
	./$(PROGRAM)

# Сборка программы
$(PROGRAM): $(OBJS)
	$(CC) $(OBJS) -o $(PROGRAM) $(LDFLAGS)
	@echo "Исполняемый файл создан: $(PROGRAM)"

# Правило для сборки .o файлов
%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка
clean:
	rm -rf $(OBJS) $(PROGRAM)


.PHONY: all clean