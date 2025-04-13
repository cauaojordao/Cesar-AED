#include <stdio.h>

int palindromo(const char *str) {
    static const char *inicio = NULL;
    static const char *fim = NULL;

    if (inicio == NULL) {
        inicio = str;
        fim = str;
        while (*fim != '\0') fim++;
        fim--;
    }

    if (inicio >= fim) {
        inicio = fim = NULL;
        return 1;
    }

    if (*inicio != *fim) {
        inicio = fim = NULL;
        return 0;
    }

    inicio++;
    fim--;
    return palindromo(str);
}

int main() {
    char palavra[100];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    printf("%d", palindromo(palavra));

    return 0;
}
