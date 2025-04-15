#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* dados;
    int capacidade;
    int inicio;
    int fim;
    int tamanho;
} Fila;

Fila* criarFila(int capacidade) {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->dados = (int*)malloc(sizeof(int) * capacidade);
    fila->capacidade = capacidade;
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    return fila;
}

int isEmpty(Fila* fila) {
    return fila->tamanho == 0;
}

int isFull(Fila* fila) {
    return fila->tamanho == fila->capacidade;
}

void enqueue(Fila* fila, int valor) {
    if (isFull(fila)) {
        printf("Fila cheia! Não é possível adicionar %d\n", valor);
        return;
    }

    fila->dados[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

void dequeue(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Fila vazia! Nada a remover.\n");
        return;
    }

    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
}

int front(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Fila vazia! Nenhum elemento no início.\n");
        return -1;
    }

    return fila->dados[fila->inicio];
}

void liberarFila(Fila* fila) {
    free(fila->dados);
    free(fila);
}

int main() {
    Fila* fila = criarFila(5);

    for (int i = 1; i <= 5; i++) {
        enqueue(fila, i);
    }

    dequeue(fila);
    dequeue(fila);

    enqueue(fila, 6);
    enqueue(fila, 7);

    while (!isEmpty(fila)) {
        printf("Dequeue: %d\n", front(fila));
        dequeue(fila);
    }

    liberarFila(fila);
    return 0;
}
