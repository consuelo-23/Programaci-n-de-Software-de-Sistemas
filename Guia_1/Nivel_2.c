#include <stdio.h>

unsigned char a = 75;
unsigned char b = 43;
signed char c = -12;

int main() {
    int nc = ~c;
    int nc_right = nc >> 1;
    printf("%d\n", nc_right);

    int a_left = a<<1;
    int al_xor_c = a_left ^ c;
    printf("%d\n", al_xor_c);
    return 0;
}