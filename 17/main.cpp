#include <stdio.h>
#include <iostream>

static const int max_str_len = 4096;

int get_digit(const char* const str, const int sign_index) {
    int semi_index = sign_index;
    char tmp_c = str[semi_index++];
    while (true) {
        if (tmp_c == ';' || tmp_c == '\0') {
            break;
        }
        tmp_c = str[semi_index++];
    }
    int ret_i = 0;

    for (int i = sign_index; i < semi_index - 1; ++i) {
        if (str[i] < '0' || str[i] > '9')
            return -1;
        ret_i *= 10;
        ret_i += (str[i] - '0');
    }
    return ret_i;
}

int main(int, char**) {
    int pos_x = 0;
    int pos_y = 0;
    int delta_x = 0;
    int delta_y = 0;
    char input_str[max_str_len] = {0};
    while (std::cin >> input_str) {
    int c_index = 0;
    char c = input_str[c_index++];
    char prev_c = '\0';
    while (c != '\0') {
        bool modified = false;
        if (prev_c != ';' && prev_c != '\0') {
            prev_c = c;
            c = input_str[c_index++];
            continue;
        }
        if (c_index == max_str_len)
            break;
        if (c == 'A') {
            int digit = get_digit(input_str, c_index);
            if (digit != -1) {
                delta_x = -digit;
                delta_y = 0;
                modified = true;
            }
        }
        else if (c == 'D') {
            int digit = get_digit(input_str, c_index);
            if (digit != -1) {
                delta_x = digit;
                delta_y = 0;
                modified = true;
            }
        }
        else if (c == 'W') {
            int digit = get_digit(input_str, c_index);
            if (digit != -1) {
                delta_x = 0;
                delta_y = digit;
                modified = true;
            }
        }
        else if (c == 'S') {
            int digit = get_digit(input_str, c_index);
            if (digit != -1) {
                delta_x = 0;
                delta_y = -digit;
                modified = true;
            }
        }
        prev_c = c;
        c = input_str[c_index++];

        if (modified) {
            pos_x += delta_x;
            pos_y += delta_y;
        }
    }
    printf("%d,%d\n", pos_x, pos_y);
    }
    return 0;
}
