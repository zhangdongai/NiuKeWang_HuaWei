#include <iostream>
#include <math.h>
#include <string.h>

int main(int argc, char** argv) {
    char input_str[1024] = {0};
    while (std::cin >> input_str) {
        int ret_i = 0;
        int valid_len = strlen(input_str);
        for (int i = 2; i < valid_len; ++i) {
            char single_c = input_str[i];
            char single_i = 0;
            if (single_c >= '0' && single_c <= '9')
                single_i = single_c - '0';
            else if (single_c >= 'a' && single_c <= 'f')
                single_i = single_c - 87;
            else if (single_c >= 'A' && single_c <= 'F')
                single_i = single_c - 55;
            else
                break;
            ret_i += (single_i * pow(16, valid_len - i - 1));
        }
        std::cout << ret_i << std::endl;
        memset(input_str, 0, 1024);
    }
    return 0;
}
