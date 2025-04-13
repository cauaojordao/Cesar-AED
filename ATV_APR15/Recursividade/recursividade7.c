#include <stdio.h>

void contagem_regressiva(int n)
{
    for(int i = n; i >= 0; i--)
        printf("%d\n", i);
}

int main()
{
    int n;
    scanf("%d", &n);
    contagem_regressiva(n);
    return 0;
}