#include <stdio.h>

int soma_digitos(int n) {
    if (n == 0)
        return 0;
    return n % 10 + soma_digitos(n / 10);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", soma_digitos(n));
    return 0;
}
