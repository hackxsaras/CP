#include<stdio.h>
int countBits(int n){
    int c = 0;
    while(n){
        n &= (n-1);
        c++;
    }
    return c;
}
int main(){
    printf("%d", countBits(10));
    return 0;
}