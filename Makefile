# Компилятор
CC = gcc

# Флаги компиляции
CFLAGS = -std=c2x -Wall -I.

# Имя программы
PROGRAM = starts_nolerros

# Все исходники
SRCS = main.c \
       file/workfiles.c \
       additions/calculator/calculator.c \
       additions/timenow.c \
       additions/wearth/wearth_get.c \
       interface/interface.c \
       additions/help/external_help.c \
       additions/notich/notich.c \
       language/locale_managere.c 

# Собираем все .o файлы из .c
OBJS = $(SRCS:.c=.o)

# По умолчанию собираем и запускаем
all: $(PROGRAM)
	./$(PROGRAM)

# Сборка программы
$(PROGRAM): $(OBJS)
	$(CC) $(OBJS) -o $(PROGRAM) -lm

# Правило для сборки .o файлов
%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка
clean:
	rm -rf $(OBJS) $(PROGRAM)

# Пересборка
rebuild: clean all

.PHONY: all clean rebuild