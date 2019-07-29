#include <stdio.h>

int main(int argc, char** argv) {
    float f;
    scanf("%f", &f);
    printf("%d\n", (int)(f + 0.5f));
    return 0;
}
