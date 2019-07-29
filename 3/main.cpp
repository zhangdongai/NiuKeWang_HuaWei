#include <stdio.h>
#include <malloc.h>
#include <iostream>

void insert_sort(int* const array, const int len) {
    for (int i = 1; i <= len - 1; ++i) {
        int tmp_i = array[i];
        int j = i;
        for (; j > 0 && array[j - 1] > tmp_i; --j)
            array[j] = array[j - 1];
        array[j] = tmp_i;
    }
}

void print_out(const int* const array, const int len) {
    int prev_int = -1;
    for (int i = 0; i < len; ++i) {
        if (array[i] != prev_int) {
            prev_int = array[i];
            printf("%d\n", prev_int);
        }
    }
}

int main(int argc, char** argv) {
    int int_num = 0;
    while (std::cin >> int_num) {
        int* int_array = (int*)malloc(int_num * sizeof(int));
        for (int i = 0; i < int_num; ++i)
            scanf("%d", &int_array[i]);
        insert_sort(int_array, int_num);
        print_out(int_array, int_num);
        free(int_array);
    }
    return 0;
}
