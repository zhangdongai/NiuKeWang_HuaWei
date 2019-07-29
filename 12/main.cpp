#include <stdio.h>
#include <string.h>

void swap(char* const c1, char* const c2) {
    *c1 = *c1 + *c2;
    *c2 = *c1 - *c2;
    *c1 = *c1 - *c2;
/*
    *c1 = *c1 ^ *c2;
    *c2 = *c1 ^ *c2;
    *c1 = *c1 ^ *c2;
*/
}

int main(int, char**) {
    char input_str[1024] = {0};
    scanf("%s", input_str);
    int str_len = strlen(input_str);
    int center = str_len / 2;
    for (int i = 0; i < center; ++i)
        swap(&input_str[i], &input_str[str_len - i - 1]);
    printf("%s\n", input_str);
}
