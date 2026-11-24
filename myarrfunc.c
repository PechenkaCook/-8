#include <stdio.h>
#include <limits.h>
#include "myarrfunc.h"

int finish_line(void)
{
    int ch;
    int valid = 1;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch != ' ' && ch != '\t' && ch != '\r') {
            valid = 0;
        }
    }
    return valid;
}

int read_number(int *value)
{
    double number;
    int status = scanf("%lf", &number);

    if (status == EOF) {
        return -1;
    }
    int valid = finish_line();
    if (status != 1 || !valid) {
        return 0;
    }
    if (!(number >= INT_MIN && number <= INT_MAX)) {
        return 0;
    }
    if (number != (int)number) {
        return 0;
    }
    *value = (int)number;
    return 1;
}

int read_choice(char *choice)
{
    if (scanf(" %c", choice) != 1) {
        return -1;
    }
    return finish_line();
}
void set_size(size_t *n, int *ready)
{
    int size;
    printf("Введите размер от 1 до %d: ", MAX_SIZE);
    if (read_number(&size) != 1 || size < 1 || size > MAX_SIZE) {
        puts("Неверный размер.");
        return;
    }
    *n = (size_t)size;
    *ready = 0;
}

void fill_array(int *arrptr, size_t n, int *ready)
{
    if (n == 0) {
        puts("Сначала задайте размер.");
        return;
    }

    *ready = 0;
    for (size_t i = 0; i < n; i++) {
        printf("Элемент %zu: ", i);
        if (read_number(arrptr + i) != 1) {
            puts("Ошибка ввода. Заполните массив заново.");
            return;
        }
    }
    *ready = 1;
}

void print_array(const int *arrptr, size_t n, int ready)
{
    if (!ready) {
        puts("Сначала заполните массив.");
        return;
    }
    for (size_t i = 0; i < n; i++) {
        printf("Индекс %zu, значение %d, адрес %p\n",
               i, *(arrptr + i), (const void *)(arrptr + i));
    }
}

long long sum_range(const int *arrptr, size_t n, size_t k, size_t m)
{
    long long sum = 0;
    for (size_t i = k; i < n && i <= m; i++) {
        sum += *(arrptr + i);
    }
    return sum;
}

int indices_in_range(const int *arrptr, size_t n, int k, int m, size_t *indices)
{
    int count = 0;
    for (size_t i = 0; i < n; i++) {
        if (*(arrptr + i) >= k && *(arrptr + i) <= m) {
            *(indices + count) = i;
            count++;
        }
    }
    if (count == 0) {
        return -1;
    }
    return count;
}

int indices_above_average(const int *arrptr, size_t n, size_t *indices)
{
    if (n == 0) {
        return -1;
    }
    long long sum = 0;
    for (size_t i = 0; i < n; i++) {
        sum += *(arrptr + i);
    }
    double average = (double)sum / n;
    int count = 0;
    for (size_t i = 0; i < n; i++) {
        if (*(arrptr + i) > average) {
            *(indices + count) = i;
            count++;
        }
    }
    if (count == 0) {
        return -1;
    }
    return count;
}

void show_sum(const int *arrptr, size_t n, int ready)
{
    if (!ready) {
        puts("Сначала заполните массив.");
        return;
    }
    int k, m;
    printf("Введите начальный индекс: ");
    if (read_number(&k) != 1) {
        puts("Неверный индекс.");
        return;
    }
    printf("Введите конечный индекс: ");
    if (read_number(&m) != 1 || k < 0 || m < k || (size_t)m >= n) {
        puts("Нужно 0 <= k <= m < размера массива.");
        return;
    }
    printf("Сумма: %lld\n", sum_range(arrptr, n, (size_t)k, (size_t)m));
}

void show_range_indices(const int *arrptr, size_t n, int ready)
{
    if (!ready) {
        puts("Сначала заполните массив.");
        return;
    }
    int k, m;
    printf("Введите нижнюю границу значения: ");
    if (read_number(&k) != 1) {
        puts("Неверная граница.");
        return;
    }
    printf("Введите верхнюю границу значения: ");
    if (read_number(&m) != 1 || k > m) {
        puts("Нужно k <= m.");
        return;
    }

    size_t indices[MAX_SIZE];
    int count = indices_in_range(arrptr, n, k, m, indices);
    if (count == -1) {
        puts("Подходящих элементов нет.");
        return;
    }
    printf("Индексы:");
    for (int i = 0; i < count; i++) {
        printf(" %zu", *(indices + i));
    }
    putchar('\n');
}

void show_average_indices(const int *arrptr, size_t n, int ready)
{
    if (!ready) {
        puts("Сначала заполните массив.");
        return;
    }

    size_t indices[MAX_SIZE];
    int count = indices_above_average(arrptr, n, indices);
    if (count == -1) {
        puts("Элементов выше среднего нет.");
        return;
    }
    printf("Индексы:");
    for (int i = 0; i < count; i++) {
        printf(" %zu", *(indices + i));
    }
    putchar('\n');
}

