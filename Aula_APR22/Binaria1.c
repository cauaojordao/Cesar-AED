#include <stdio.h>

int buscaBinaria(int vetor[], int tamanho, int valor){
    int inicio = 0, fim = tamanho - 1;
    while(inicio <= fim){

        int meio = (inicio + fim) / 2;
        
        if(vetor[meio] == valor) return meio;
        
        else if(vetor[meio] > valor) fim = meio - 1;

        else if(vetor[meio] < valor) inicio = meio + 1;
    }
    return -1;
}

int main(){

    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valor = 5;

    int posicao = buscaBinaria(vetor, tamanho, valor);

    if(posicao == -1) printf("O valor %d nao foi encontrado no vetor.\n", valor);
    else printf("O valor %d foi encontrado na posicao %d do vetor.\n", valor, posicao);
    return 0;

}