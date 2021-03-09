#include "lite_parsing.h"

char code[100] = {"var: 42"};

int main() {
    int digit_result = digit('1');
    int symbol_result = symbol(':');
    int lower_result = lower('a');
    int upper_result = upper('A');
    int space_result = space(' ');

    printf("digit() = %d\n", digit_result);
    printf("symbol() = %d\n", symbol_result);
    printf("lower() = %d\n", lower_result);
    printf("upper() = %d\n", upper_result);
    printf("space() = %d\n", space_result);

    return 0;
}