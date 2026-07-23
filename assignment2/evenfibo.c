#include<stdio.h>

int evenfiboSum(int n){
     int sum = 0 ;

     int a = 0 ;
     int b = 1;
     while(b<=n){
        if(b%2==0){
            sum+=b;
        }
        int c= a+b;
        a = b;
        b = c;
        
       
     }
     return sum ;
}

int evenfiboSumOpt(int n){
    if(n<2){
        return 0 ;
    }
    int sum = 2 ;

    int prev = 2 ;
    int curr = 8 ;
    while(curr<=n){
        sum+=curr;

        int next = 4*curr + prev;
        prev = curr ;
        curr = next;
    }

    return sum ;
}

int main(){
    printf("Enter the value of n");
    int n ;
    scanf("%d",&n);
    int sum = evenfiboSum(n);
    printf(sum);
}
