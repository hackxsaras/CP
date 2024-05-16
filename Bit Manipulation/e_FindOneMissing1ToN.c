#include<stdio.h>
int naturalXor(int n)
{
    int b = n % 4;
    if (b == 0)
    {
        return n;
    }
    else if (b == 1)
    {
        return 1;
    }
    else if (b == 2)
    {
        return n + 1;
    }

    return 0;
}
int findMissing(int a[], int n){
    int x = naturalXor(n);
    for(int i=0;i<n-1;i++){
        x ^= a[i];
    }
    return x;
}

int main(){
    int a[] = {1, 2, 3, 8, 5, 6, 7, 9};
    printf("%d", findMissing(a, 9));
    return 0;
}