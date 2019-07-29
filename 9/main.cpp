#include <stdio.h>

int main(int, char**) {
    int raw_int = 0;
    scanf("%d", &raw_int);
    int mod = raw_int % 10;
    int div = raw_int / 10;
    int digits[10] = {0};
    int ret_i = 0;
    while (mod != 0 || div != 0) {
        if (digits[mod] == 0) {
            digits[mod] = 1;
            ret_i *= 10;
            ret_i += mod;
        }
        mod = div % 10;
        div /= 10;
    }
    printf("%d", ret_i);
    return 0;
}
