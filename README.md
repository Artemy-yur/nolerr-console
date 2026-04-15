# Nolerr OS — Мини-операционная система

![Статус сборки](https://img.shields.io/badge/build-passing-green)
![Лицензия](https://img.shields.io/badge/license-MIT-yellow)
![Платформа](https://img.shields.io/badge/platform-Windows%20|%20Linux-lightgrey)
![Версия](https://img.shields.io/badge/version-0.4-blue)

**Nolerr OS** — собственная операционная система, созданная на C, Python. Простая, надежная и легкая в использовании.

---

## Быстрый старт

### Для Windows

```batch
git clone https://github.com/Artemy-yur/nolerr-OS.git
cd nolerr-OS
build.bat
Затем запустите Ezy_OS.exe.
Или же
build_os.py
Все автоматические соберет и запустит.

Для Linux
bash

git clone https://github.com/Artemy-yur/nolerr-OS.git
cd nolerr-OS
mkdir build && cd build
cmake ..
make
./Ezy_OS
Структура проекта
Основные папки и файлы:

file/ — Файловый менеджер
(workfiles.c — создание, чтение, удаление файлов)

additions/ — Дополнительные модули и программы

help/ — справочная система
wearth/ — погода, время, калькулятор
workfiles.c — Управление файлами

additions/calculator/calculator.c — Математика

additions/time.now.c — Текущее время и дата

additions/weather_module/getWearth.c, server.go — Погода через API

additions/help/help.c, help.py — Справка

interface/interface.c — Консольный интерфейс

Основные модули
Модуль	Файл(ы)	Описание
Файловый менеджер	file/workfiles.c	Работа с файлами: создание, чтение, удаление
Калькулятор	additions/wearth/calculator.c	Математические вычисления
Время и дата	additions/wearth/time.now.c	Отображение текущего времени и даты
Погода	additions/wearth/getWearth.c	Получение информации о погоде через API
Справочная система	additions/help/help.c, help.py	Интерактивная справка
Скачивания зависимотей dependencies/dependencies_py. Автоскачивания python 13.0, если он не скачан

Технологии
Ядро: C (сборка через CMake)
Скрипты: Python 3
Интерфейс: Консольный интерфейс (поддержка Windows и Linux)
Сборка: CMake + GCC / MinGW
Установка и подготовка
Требования
Windows 10/11 или Linux
CMake 3.10+
GCC или MinGW (для Windows)
Python 3.8+
Сборка проекта
Для Windows
batch

git clone https://github.com/ArtemyDev/nolerr-OS.git
cd nolerr-OS
build.bat

Для Linux
bash

git clone https://github.com/ArtemyDev/nolerr-OS.git
cd nolerr-OS
mkdir build && cd build
cmake ..
make
./nolerr-console
Разработка новых модулей

Система спроектирована так, чтобы быть максимально расширяемой. Чтобы добавить свой модуль, следуйте инструкции:

1. Создайте новую папку в директории additions/ (например, additions/my_tool/).

2. Добавьте туда файлы .c и (при необходимости) .h.

3. В главном файле интерфейса (interface/interface.c или main.c) подключите заголовочный файл вашего модуля.

4. Добавьте новый пункт в меню и вызовите функцию в switch-case.

Документация по функциям
Файловый менеджер: создание, чтение, удаление файлов, просмотр папок
Погода: требует API-ключ OpenWeatherMap
Справка: реализована на C и Python, обеспечивает удобный доступ к документации
Вклад в проект
Призываем к сотрудничеству!
Для внесения своего вклада:

Форкните репозиторий
Создайте ветку своей функции
Внесите изменения
Откройте Pull Request
Лицензия
Этот проект распространяется под лицензией MIT. Подробнее — в файле LICENSE.

Контакты
Автор: Артемий Юров
GitHub: Artemy-yur
Проект: Nolerr OS
Поблагодарим за интерес!
⭐ Если вам нравится проект — поставьте звездочку на GitHub! ⭐
Nolerr OS — "No Errors, Just Solutions."
Простота, надежность и эффективность!
