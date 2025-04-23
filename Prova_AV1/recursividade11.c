#include <stdio.h>

int somarVetor(int vetor[], int n) {
    if (n == 0) return 0;
    return vetor[n - 1] + somarVetor(vetor, n - 1);
}

int main(){

    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 5;

    int soma = somarVetor(vetor, n);
    printf("Soma: %d\n", soma);
    return 0;
}