#include <stdio.h>
#define SIZE 100000

void identify_identical(int vlaues[], int n);
int identical_right(int snow1[], int snow2[], int start);
int identical_left(int snow1[], int snow2[], int start);
int are_identical(int snow1[], int snow2[]);
void identify_identical(int snowflakes[SIZE][6], int n);

int main(void)
{
    static int snow[SIZE][6];

    int n, i, j;

    printf("Enter the size of SnowFlakes: ");
    scanf("%d", &n);

    printf("Now start inputing snowFlakes arms size.\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("Input arms: [%d][%d]: ", i, j);
            scanf("%d", &snow[i][j]);
        }
    }

    identify_identical(snow, 6);
    // int a[6] = {1, 2, 3, 4, 5, 6};
    // int i[6] = {3, 2, 1, 6, 5, 4};

    // if (are_identical(a, i))
    // {
    //     printf("Like Identical");
    // }
    // else
    // {
    //     printf("Unlike Identical");
    // }

    return 0;
}

int are_identical(int snow1[], int snow2[])
{
    int start;

    for (start = 0; start < 6; start++)
    {
        if (identical_right(snow1, snow2, start))
            return 1;
        if (identical_left(snow1, snow2, start))
            return 1;
    }

    return 0;
}

int identical_right(int snow1[], int snow2[], int start)
{
    int offset;
    for (offset = 0; offset < 6; offset++)
    {
        // Mod trick : Use the logic without variable declaration
        if (snow1[offset] != snow2[(start + offset) % 6])
            return 0;
    }

    return 1;
}

int identical_left(int snow1[], int snow2[], int start)
{
    int offset, snow2_index;

    for (offset = 0; offset < 6; offset++)
    {
        snow2_index = start - offset;
        if (snow2_index < 0)
            snow2_index = snow2_index + 6;
        if (snow1[offset] != snow2[snow2_index])
            return 0;
    }

    return 1;
}

void identify_identical(int values[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (values[i] == values[j])
            {
                printf("Twin integers found.\n");
                return;
            }
        }
    }

    printf("No two integers are alike.\n");
}

void identify_identical(int snowflakes[SIZE][6], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (are_identical(snowflakes[i], snowflakes[j]))
            {
                printf("Twin snowflakes found.\n");
                return;
            }
        }
    }

    printf("No two snowflakes are alike.\n");
}
