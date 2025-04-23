#include <stdio.h>

int buscaValor(int vetor[], int valor,int tamanho){
    if(tamanho == 0) return -1;
    for(int i = 0; i < tamanho; i++){
        if(vetor[i] == valor) return i;
    }
    return -1;
}

int main() {
    int vetor[] = {10, 20, 30, 40, 50, 60};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valor = 30;

    int posicao = buscaValor(vetor, valor, tamanho);

    if (posicao == -1) {
        printf("O valor %d nao foi encontrado no vetor.\n", valor);
    } else {
        printf("O valor %d foi encontrado na posicao %d do vetor.\n", valor, posicao);
    }
    return 0;
}
