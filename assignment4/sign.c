#include <stdio.h>

int sign(int x) {
    int sign_bit = x >> 31;
    int nonzero = !!x;
    return sign_bit | nonzero;
}

int main() {
    printf("sign(130) = %d\n", sign(130));
   

    return 0;
}
