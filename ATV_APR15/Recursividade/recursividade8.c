#include <stdio.h>

int maior_elemento(int v[], int n)
{
    int maior = 0;

    if (n == 1)
        maior = v[0];

    else
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] > maior)
            {
                maior = v[i];
            }
        }
    }

    return maior;
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