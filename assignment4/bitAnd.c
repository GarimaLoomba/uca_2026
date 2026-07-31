#include<stdio.h>

int bitAnd(int x , int y ){
        int and = ~((~x)|(~y));
        return and ;
}
int main(){

        int bitand = bitAnd(6,5);
        printf("%d" , bitand);
}
