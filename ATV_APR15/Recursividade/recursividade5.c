#include <stdio.h>

void contagem_regressiva(int n)
{
    if (n == 0)
        printf("0\n");
        return;
    printf("%d\n", n);
    contagem_regressiva(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    contagem_regressiva(n);
    return 0;
}