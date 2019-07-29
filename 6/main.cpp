#include <stdio.h>
#include <string.h>

static const int max_factor_num = 64;
static const int invalid_int = 0;

static int factor_index = 0;

void insert_sort(int* const factors) {
    for (int i = 1; i <= max_factor_num - 1; ++i) {
        int tmp = factors[i];
        if (tmp == invalid_int)
            break;
        int j = i;
        for (; j >= 0 && factors[j - 1] > tmp; --j) {
            factors[j] = factors[j - 1];
        }
        factors[j] = tmp;
    }
}

bool get_factors(const int input_int, int* const factors) {
    bool goon_split = false;
    int binary = input_int / 2;
    int tmp_int = input_int;
    for (int i = 2; i <= binary; ++i) {
        int mod = tmp_int % i;
        if (mod == 0) {
            if (!get_factors(i, factors))
                factors[factor_index++] = i;
            goon_split = true;
            tmp_int /= i;
            if (tmp_int == i)
                factors[factor_index++] = i;
        }
        else if (tmp_int < i && mod > 1) {
            if (!get_factors(tmp_int, factors))
                factors[factor_index++] = tmp_int;
            break;
        } 
    }
    return goon_split;
}

int main(int argc, char** argv) {
    int input_int = 0;
    scanf("%d", &input_int);
    int factors[max_factor_num + 1] = {invalid_int};
    factors[0] = input_int;
    get_factors(input_int, factors);
    insert_sort(factors);
    for (int i = 0; i < max_factor_num; ++i)
        if (factors[i] != invalid_int)
            printf("%d ", factors[i]);
    return 0;
}
