#include <stdio.h>

int produto(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    return a + produto(a, b - 1);
}

int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d\n", produto(a, b));
    return 0;
}