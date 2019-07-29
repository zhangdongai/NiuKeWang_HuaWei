#include <stdio.h>

int main(int, char**) {
    int input_i = 0;
    scanf("%d", &input_i);
    char mod = input_i % 10;
    int div = input_i / 10;
    while (mod !=0 || div != 0) {
        printf("%c", mod + '0');
        mod = div % 10;
        div /= 10;
    }
    return 0;
}
