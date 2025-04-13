#include <stdio.h>

int contar_digitos(long long d)
{
    
    if (d == 0) 
        return 0;
    
    long long n = 0;
    n = contar_digitos(d / 10);
    return n + 1;
}

int main()
{
    long long n;
    printf("Digite um número: ");
    scanf("%lld", &n);
    long long s = contar_digitos(n);
    printf("O número possui %lld dígitos.", s);
    return 0;
}
