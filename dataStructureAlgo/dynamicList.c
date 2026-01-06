#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int capacity = 3;
    int *list = malloc(capacity * sizeof(int));

    if (list == NULL)
    {
        return 1;
    }

    list[0] = 3;
    list[1] = 5;
    list[2] = 8;

    int *temp = realloc(list, 4 * sizeof(int));
    if (temp == NULL)
    {
        free(list);
        return 1;
    }

    temp[3] = 10;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", temp[i]);
    }

    free(list);

    return 0;
}
