#include <stdio.h>
#include <string.h>

int main(int, char**) {
    char input_str[1024] = {0};
    scanf("%s", input_str);
    char chars[128] = {0};
    int chars_num = 0;
    for (int i = 0; i < strlen(input_str); ++i) {
        char c = input_str[i];
        if (c >= 0 && c <= 127) {
            if (chars[c] == 0) {
                chars[c] = 1;
                ++chars_num;
            }
        }
    }
    printf("%d", chars_num);
    return 0;
}
