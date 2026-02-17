def show_function_help():
    
    CYAN = "\033[36m"
    GOLD = "\033[33m"
    RESET = "\033[0m"
    BOLD = "\033[1m"

    help_text = f"""
{CYAN}╔══════════════════════════════════════════════════════════════╗
║{RESET} {BOLD}                    СПРАВКА ПО ФУНКЦИЯМ                    {RESET}{CYAN}  ║
╠══════════════════════════════════════════════════════════════╣
 {GOLD}1.{RESET} {BOLD}listfile(){RESET}     —  Просмотр файлов (список, размеры)      
 {GOLD}2.{RESET} {BOLD}workfile(){RESET}     —  Управление (создание, удаление, и др.) 
 {GOLD}3.{RESET} {BOLD}actions(){RESET}      —  Математика (+, -, *, /, ^, √, sin)     
 {GOLD}4.{RESET} {BOLD}times(){RESET}        —  Дата и время (ЧЧ:ММ:СС, ДД.ММ.ГГГГ)    
 {GOLD}5.{RESET} {BOLD}get_weather(){RESET}  —  Погода (температура в городе)        
 {GOLD}6.{RESET} {BOLD}davidgpt(){RESET}     —  Нейросеть на базе Яндекс api          
 ══════════════════════════════════════════════════════════════ 
 {CYAN}Введите имя функции или {RESET}{BOLD}'exit'{RESET}{CYAN} для выхода             
╚══════════════════════════════════════════════════════════════╝{RESET}
"""
    print(help_text)

def main():
    show_function_help()

    while True:
        try:
            command = input("\033[32m ❯\033[0m ").strip().lower()
            
            if command == 'exit':
                print("\033[31mВыход из справки...\033[0m")
                break
                print(f"\033[31mОшибка:\033[0m Команда '{command}' не существует.")    
        except (EOFError, KeyboardInterrupt):
            print("\nПрограмма завершена.")
            break

if __name__ == "__main__":
    main()
