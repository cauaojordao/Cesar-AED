#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* dados;
    int tamanho;
    int capacidade;
} Fila;

Fila* criarFila(int capacidade) {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->dados = (int*)malloc(sizeof(int) * capacidade);
    fila->tamanho = 0;
    fila->capacidade = capacidade;
    return fila;
}

int isEmpty(Fila* fila) {
    return fila->tamanho == 0;
}

void enqueue(Fila* fila, int valor) {
    if (fila->tamanho == fila->capacidade) {
        fila->capacidade *= 2;
        fila->dados = realloc(fila->dados, fila->capacidade * sizeof(int));
    }
    fila->dados[fila->tamanho++] = valor;
}

void dequeue(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Fila vazia!\n");
        return;
    }
    for (int i = 0; i < fila->tamanho - 1; i++) {
        fila->dados[i] = fila->dados[i + 1];
    }
    fila->tamanho--;
}

int front(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Fila vazia!\n");
        return -1;
    }
    return fila->dados[0];
}

void liberarFila(Fila* fila) {
    free(fila->dados);
    free(fila);
}

int main() {
    Fila* fila = criarFila(4);

    for (int i = 1; i <= 10; i++) {
        enqueue(fila, i);
        printf("Enqueued: %d\n", i);
    }

    printf("Primeiro elemento: %d\n", front(fila));

    while (!isEmpty(fila)) {
        printf("Dequeue: %d\n", front(fila));
        dequeue(fila);
    }

    liberarFila(fila);
    return 0;
}
