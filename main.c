#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include "myarrfunc.h"

int main(void)
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    int arr[MAX_SIZE];
    size_t n = 0;
    int ready = 0;
    char choice;

    while (1) {
        puts("\na Задать размер массива");
        puts("b Заполнить массив");
        puts("c Показать значения и адреса");
        puts("d Сумма в диапазоне индексов");
        puts("e Индексы элементов в диапазоне значений");
        puts("f Индексы элементов выше среднего");
        puts("g Выход");
        printf("Выберите пункт: ");

        int status = read_choice(&choice);
        if (status == -1) {
            break;
        }
        if (status == 0) {
            puts("Введите одну букву от a до g.");
            continue;
        }

        switch (choice) {
            case 'a':
                set_size(&n, &ready);
                break;
            case 'b':
                fill_array(arr, n, &ready);
                break;
            case 'c':
                print_array(arr, n, ready);
                break;
            case 'd':
                show_sum(arr, n, ready);
                break;
            case 'e':
                show_range_indices(arr, n, ready);
                break;
            case 'f':
                show_average_indices(arr, n, ready);
                break;
            case 'g':
                return 0;
            default:
                puts("Такого пункта нет.");
        }
    }
    return 0;
}

