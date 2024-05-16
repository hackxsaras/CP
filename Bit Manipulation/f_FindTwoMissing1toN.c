#include<stdio.h>
#include<stdlib.h>

int naturalXor(int n) {
    int b = n % 4;
    if (b == 0) {
        return n;
    }
    else if (b == 1) {
        return 1;
    }
    else if (b == 2) {
        return n + 1;
    }
    return 0;
}
int xorOfArray(int a[], int n) {
    int x = 0;
    for(int i=0;i<n;i++) x^=a[i];
    return x;
}
int* find2Missing(int a[], int n){
    int x = xorOfArray(a, n-2);
    int nx = naturalXor(n);

    x ^= nx;

    // rightmost set bit
    printf("%d ", x );
    x = x & ~(x-1);
    printf("%d ", x );
    int p = 0, q = 0;
    
    for(int i=0;i<n-2;i++){
        if(a[i] & x) p ^= a[i];
        else q ^= a[i];
    }
    for(int i=1;i<=n;i++){
        if(i & x) p ^= i;
        else q ^= i;
    }
    int* r = (int*)malloc(sizeof(int)*2);
    r[0] = p;
    r[1] = q;
    return r;
    
}
int main(){
    int a[] = {2, 3, 5, 6};
    int* x = find2Missing(a, 6);
    printf("%d %d", x[0], x[1]);
    return 0;
}