#include <stdio.h>

int Fact(int n);

int main()
{
    int num = 5;
    printf("%d", Fact(num));
    return 0;
}

int Fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * Fact(n - 1);
    }
}
