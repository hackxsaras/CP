#include <stdio.h>
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
int main()
{
    printf("%d", naturalXor(10));
    return 0;
}