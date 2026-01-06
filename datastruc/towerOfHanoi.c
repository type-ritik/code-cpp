#include <stdio.h>

void TowerOfHanoi(int n, char fromPeg, char toPeg, char auxPeg);

int main()
{
    TowerOfHanoi(3, 'A', 'C', 'B');
    return 0;
}

void TowerOfHanoi(int n, char fromPeg, char toPeg, char auxPeg)
{
    if (n == 1)
    {
        printf("\nMove disk 1 from Peg %c to Peg %c", fromPeg, toPeg);
        return;
    }

    TowerOfHanoi(n - 1, fromPeg, auxPeg, toPeg);

    printf("\nMove disk %d from peg %c to peg %c", n, fromPeg, toPeg);

    TowerOfHanoi(n - 1, auxPeg, toPeg, fromPeg);
}
