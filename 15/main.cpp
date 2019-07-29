#include <stdio.h>

int main(int, char**) {
    int input_i = 0;
    scanf("%d", &input_i);
    int mod = input_i % 2;
    int div = input_i / 2;
    int num_1 = 0;
    while (mod != 0 || div != 0) {
        if (mod == 1)
            ++num_1;
        mod = div % 2;
        div /= 2;
    }
    printf("%d\n", num_1);
    return 0;
}
