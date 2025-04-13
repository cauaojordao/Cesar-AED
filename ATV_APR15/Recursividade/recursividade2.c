#include <stdio.h>

int maior_elemento(int v[], int n)
{
    if (n == 1)
        return v[0];

    else
    {
        int maior = maior_elemento(v, n - 1);
        if (v[n - 1] > maior)
        {
            return v[n - 1];
        }
        else
        {
            return maior;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    printf("%d\n", maior_elemento(v, n));
    return 0;
}