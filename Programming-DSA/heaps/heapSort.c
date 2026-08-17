#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

Generic heap sort in C
Implement heap sort in C. It has to be implemented such that it can sort any type of data.

Key highlights:

use of function pointer
use of void pointer
memcpy function

*/

void swap(void *a, void *b, size_t size)
{

    void *temp = malloc(size);

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

int cmp_int(const void *a, const void *b)
{
    int ia = *(const int *)a;
    int ib = *(const int *)b;

    return (ia > ib) - (ia < ib);
};

int cmp_str(const void *a, const void *b)
{
    const char *sa = *(const char *const *)a;
    const char *sb = *(const char *const *)b;
    return strcmp(sa, sb);
};

void print_int_arr(const int *arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void print_str_arr(const char **arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%s ", arr[i]);
    printf("\n");
}

void heapify(void *base, size_t num, size_t size, size_t i,
             int (*compar)(const void *, const void *))
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    char *arr = (char *)base;

    if (left < num && compar(arr + left * size, arr + largest * size) > 0)
    {
        largest = left;
    }

    if (right < num && compar(arr + right * size, arr + largest * size) > 0)
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr + i * size, arr + largest * size, size);
        heapify(base, num, size, largest, compar);
    }
};

void heapSort(void *base, size_t num, size_t size,
              int (*compar)(const void *, const void *))
{

    if (num <= 1)
        return;

    char *arr = (char *)base;

    for (int i = (int)num / 2 - 1; i >= 0; --i)
    {
        heapify(base, num, size, (size_t)i, compar);
    }

    for (int i = (int)num - 1; i > 0; i--)
    {
        swap(arr, arr + (size_t)i * size, size);
        heapify(base, (size_t)i, size, 0, compar);
    }
}

int main()
{

    int int_arr[] = {5, 2, 9, 1, 5, 6};
    size_t int_n = sizeof(int_arr) / sizeof(int_arr[0]);
    printf("Before sorting integers: ");
    print_int_arr(int_arr, int_n);

    heapSort(int_arr, int_n, sizeof(int), cmp_int);

    printf("After sorting integers:  ");
    print_int_arr(int_arr, int_n);

    // Example 2: sorting an array of strings (by pointer)
    const char *str_arr[] = {"apple", "pear", "banana", "kiwi", "orange"};
    size_t str_n = sizeof(str_arr) / sizeof(str_arr[0]);
    printf("Before sorting strings:  ");
    print_str_arr(str_arr, str_n);

    heapSort(str_arr, str_n, sizeof(const char *), cmp_str);

    printf("After sorting strings:   ");
    print_str_arr(str_arr, str_n);

    return 0;
}
