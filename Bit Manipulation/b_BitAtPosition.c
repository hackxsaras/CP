#include<stdio.h>
int bitAtPosition(int n, int x){
    return (n & (1 << x))? 1 : 0;
}
int main(){
    printf("%d", bitAtPosition(10, 2));
    return 0;
}