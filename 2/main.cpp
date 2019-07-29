#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool isequal(const char c_const, const char c_str) {
    static char sign_gap = 'a' - 'A';
    if (c_const == c_str || c_const == c_str + sign_gap)
        return true;
    return false;
}

int main(int argc, char** argv) {
    char input_str[1024] = {0};
    char input_c;
    fgets(input_str, sizeof(input_str), stdin);
    input_c = tolower(getchar());
    int str_len = strlen(input_str);
    int num_c = 0;
    for (int i = 0; i < str_len; ++i) {
        if (isequal(input_c, input_str[i]))
            ++num_c;
    }
    printf("%d", num_c);
}
