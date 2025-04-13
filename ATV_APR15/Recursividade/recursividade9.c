#include <stdio.h>

int contar_digitos(long long d)
{

    if (d == 0)
        return 0;

    long long n = 0;
    n = contar_digitos(d / 10);
    return n + 1;
}

int soma_digitos(int n)
{
    if (n == 0)
        return 0;

    int s;
    
    while (n != 0)
    {
        s += n % 10;
        n = n / 10;
    }

    return s;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", soma_digitos(n));
    return 0;
}
