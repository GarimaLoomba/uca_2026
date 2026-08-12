#include <stdio.h>

int fitsBits(int x, int n) {
    int shift = x << (32-n);
    int right = shift >> (32-n);
    return !(shift ^right);

}

int main() {
    printf("fitsBits(5, 3) = %d\n", fitsBits(5, 3));
    printf("fitBits(-4,3) = %d\n" , fitsBits(-4 ,3));
   

    return 0;
}
