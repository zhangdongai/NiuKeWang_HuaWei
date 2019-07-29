#include <stdio.h>
#include <malloc.h>
#include <string.h>

static const int max_str_len = 128;

bool greater(char* c1, char* c2) {
    for (int i = 0; i < max_str_len; ++i) {
        if (c1[i] == '\0')
            return false;
        else if (c2[i] == '\0')
            return true;
        else if (c1[i] > c2[i])
            return true;
        else if (c1[i] < c2[i])
            return false;
    }
    return false;
}

void insert_sort(char** const array, const int str_len) {
    char tmp[128] = {0};
    for (int i = 1; i <= str_len - 1; ++i) {
        strncpy(tmp, array[i], max_str_len);
        int j = i;
        for (; j > 0 && greater(array[j - 1], tmp); --j) {
            strncpy(array[j], array[j - 1], max_str_len);
        }
        strncpy(array[j], tmp, max_str_len);
    }
}

int main(int, char**) {
    int str_num = 0;
    scanf("%d", &str_num);
    char** str_array = (char**)malloc(sizeof(char*) * str_num);
    for (int i = 0; i < str_num; ++i) {
        str_array[i] = (char*)malloc(max_str_len);
        memset(str_array[i], 0, max_str_len);
        scanf("%s", str_array[i]);
    }

    insert_sort(str_array, str_num);

    for (int i = 0; i < str_num; ++i)
        printf("%s\n", str_array[i]);

    for (int i = 0; i < str_num; ++i)
        free(str_array[i]);
    free(str_array);
    return 0;
}
