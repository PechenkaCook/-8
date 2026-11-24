#ifndef MYARRFUNC_H
#define MYARRFUNC_H

#include <stddef.h>

#define MAX_SIZE 100

int finish_line(void);
int read_number(int *value);
int read_choice(char *choice);
void set_size(size_t *n, int *ready);
void fill_array(int *arrptr, size_t n, int *ready);
void print_array(const int *arrptr, size_t n, int ready);
long long sum_range(const int *arrptr, size_t n, size_t k, size_t m);
int indices_in_range(const int *arrptr, size_t n, int k, int m, size_t *indices);
int indices_above_average(const int *arrptr, size_t n, size_t *indices);
void show_sum(const int *arrptr, size_t n, int ready);
void show_range_indices(const int *arrptr, size_t n, int ready);
void show_average_indices(const int *arrptr, size_t n, int ready);

#endif

