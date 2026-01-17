#include <stdio.h>
#include <stdlib.h>

void Recursion(int);

int main(void)
{
    Recursion(5);
    return 0;
}

void Recursion(int num)
{
    if (num == 0)
    {
        return;
    }
    printf("Recursion %d\n", num);
    Recursion(num - 1);
    printf("BackTrack %d\n", num);
}
