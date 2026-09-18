
#include <stdio.h>

int isPower2(int x) {
    int positive;
    int one_bit;
    int nonzero;

    positive = !(x >> 31);
    one_bit = !(x & (x + ~0));
    nonzero = !!x;

    return positive & one_bit & nonzero;
}

int main() {
    printf("isPower2(0)  = %d\n", isPower2(0));
    printf("isPower2(1)  = %d\n", isPower2(1));
   

    return 0;
}


