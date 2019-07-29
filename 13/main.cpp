#include <iostream>
//#include <stdio.h>
#include <string.h>

void swap(char* const c1, char* const c2) {
    *c1 = *c1 + *c2;
    *c2 = *c1 - *c2;
    *c1 = *c1 - *c2;
}

void partial_reverse(char* const input_str, int begin, int end) {
    int len = begin + end + 1;
    int center = len / 2;
    for (int i = begin; i < center; ++i)
        swap(&input_str[i], &input_str[len - i - 1]);
}

int main(int, char**) {
    char input_str[1024] = {0};
    std::cin.get(input_str, sizeof(input_str));;
//    scanf("%[^\n]", input_str);
    int str_len = strlen(input_str);
    int space_i = 0;
    for (int i = 0; i < str_len; ++i) {
        if (input_str[i] == ' ') {
            partial_reverse(input_str, space_i, i - 1);
            space_i = i + 1;
        }
    }
    partial_reverse(input_str, space_i, str_len - 1);
    partial_reverse(input_str, 0, str_len - 1);
    std::cout << input_str << std::endl;
    return 0;
}
