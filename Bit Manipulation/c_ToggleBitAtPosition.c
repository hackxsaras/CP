#include<stdio.h>
int toggleBitAtPosition(int n, int x){
    return (n ^ (1 << x));
}
int main(){
    printf("%d", toggleBitAtPosition(10, 2));
    return 0;
}