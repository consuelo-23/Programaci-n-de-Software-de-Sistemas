#include <stdio.h>

unsigned char a = 75;
unsigned char b = 43;
signed char c = -12;

int main() {
    int a_and_b = a&b;
    int or_c = a_and_b | c;
    printf("%d\n", or_c);

    int a_xor_b = a ^ b;
    int and_c = a_xor_b & c;
    printf("%d\n", and_c);

    int not_c = ~ c;
    int a_or_b = a | b;
    int not_c_and_a_or_b = not_c & a_or_b;
    printf("%d\n", not_c_and_a_or_b);

    return 0;
}