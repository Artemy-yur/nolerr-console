Kinetic Open Structure Minimal Operation System — динамичная, открытая, структурированная, минималистичная операционная система, написанная на C + ASM
🚀 Как запустить ОС
Установка зависимостей: make nasm xorriso qemu-system grub-pc-bin mtools

Скачивание компилятора: i386-elf-7.5.0-Linux-x86_64.tar.xz

Распаковка скачанного архива: tar -xf toolchain/dists/i386-elf*.tar.xz

Добавить путь до распакованного компилятора в PATH: export PATH=$PATH:<ПУТЬ_ДО_КОМПИЛЯТОРА>/i386-elf*/bin/

Перезайти в сессию

Компиляция ядра и запуск: make (в корне проекта)


Я не являюсь ее перво начальным создателем её создатель https://github.com/igmunv
