#include<stdio.h>


int bitXor(int x , int y ){
        return ~(~(~x&y)&(~(x&~y)));

}
int main(){
        int x , y ;
        printf("Enter the first Number");
        scanf("%d",&x);
        printf("Enter the 2nd Number");
        scanf("%d",&y);
        int ans = bitXor(x,y);
        printf("%d\n" , ans);

}
