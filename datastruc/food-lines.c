#include <stdio.h>
#define MAX_LINES 100

void solve(int lines[], int n, int m);
int shortest_line_index(int lines[], int n);

int main()
{
    int lines[MAX_LINES];
    int n, m, i;

    scanf("%d%d", &n, &m);

    for (i = 0; i < n; i++)
        scanf("%d", &lines[i]);
    solve(lines, n, m);
    return 0;
}

void solve(int lines[], int n, int m)
{
    int i, shortest;

    for (i = 0; i < n; i++)
    {
        shortest = shortest_line_index(lines, n);
        printf("%d shortest\n", lines[shortest]);

        lines[shortest]++;
    }
}

int shortest_line_index(int lines[], int n)
{
    int i;
    int shortest = 0;

    for (i = 1; i < n; i++)
    {
        if (lines[i] < lines[shortest])
        {
            shortest = i;
        }
    }

    return i;
}
