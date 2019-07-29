#include <stdio.h>
#include <malloc.h>
#include <string.h>

static const int default_len = 8;
static const int max_len = 100;

void split_string(const char* const raw_str) {
    int str_len = strlen(raw_str);
    if (str_len == 0)
        return;
    int array_num = (str_len - 1) / default_len + 1;
    int c_position = 0;
    char** sub_str_array = (char**)malloc(array_num * sizeof(char*));
    for (int i = 0; i < array_num; ++i) {
        sub_str_array[i] = (char*)malloc(default_len + 1);
        memset(sub_str_array[i], '0', default_len);
        sub_str_array[i][default_len] = '\0';
        int cpy_num = default_len;
        int remained_num = str_len - c_position;
        if (remained_num < default_len) {
            cpy_num = remained_num;
        }
        strncpy(sub_str_array[i], raw_str + c_position, cpy_num);
        c_position += cpy_num;
        
        printf("%s\n", sub_str_array[i]);
    }
    
    for (int i = 0; i < array_num; ++i)
        free(sub_str_array[i]);
    free(sub_str_array);
}

int main(int argc, char** argv) {
    char input_str1[max_len + 1] = {0};
    char input_str2[max_len + 1] = {0};
//    gets(input_str1);
//    fgets(input_str2, max_len, stdin);
    scanf("%s", input_str1);
    scanf("%s", input_str2);
    
    split_string(input_str1);
    split_string(input_str2);

    return 0;
} 
