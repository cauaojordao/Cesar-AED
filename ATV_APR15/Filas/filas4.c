#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* dados;
    int capacidade;
    int inicio;
    int fim;
    int tamanho;
} Fila;

typedef struct {
    int* dados;
    int topo;
    int capacidade;
} Pilha;

Fila* criarFila(int capacidade) {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->dados = (int*)malloc(sizeof(int) * capacidade);
    fila->capacidade = capacidade;
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    return fila;
}

Pilha* criarPilha(int capacidade) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->dados = (int*)malloc(sizeof(int) * capacidade);
    pilha->topo = -1;
    pilha->capacidade = capacidade;
    return pilha;
}

int isEmptyFila(Fila* fila) {
    return fila->tamanho == 0;
}

int isFullFila(Fila* fila) {
    return fila->tamanho == fila->capacidade;
}

void enqueue(Fila* fila, int valor) {
    if (isFullFila(fila)) return;
    fila->dados[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

int dequeue(Fila* fila) {
    if (isEmptyFila(fila)) return -1;
    int valor = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
    return valor;
}

void push(Pilha* pilha, int valor) {
    if (pilha->topo + 1 == pilha->capacidade) return;
    pilha->dados[++pilha->topo] = valor;
}

int pop(Pilha* pilha) {
    if (pilha->topo == -1) return -1;
    return pilha->dados[pilha->topo--];
}

void inverterFila(Fila* fila) {
    Pilha* pilha = criarPilha(fila->capacidade);
    while (!isEmptyFila(fila)) {
        push(pilha, dequeue(fila));
    }
    while (pilha->topo != -1) {
        enqueue(fila, pop(pilha));
    }
    free(pilha->dados);
    free(pilha);
}

void imprimirFila(Fila* fila) {
    int i = fila->inicio;
    int count = fila->tamanho;
    while (count--) {
        printf("%d ", fila->dados[i]);
        i = (i + 1) % fila->capacidade;
    }
    printf("\n");
}

int main() {
    Fila* fila = criarFila(10);

    enqueue(fila, 1);
    enqueue(fila, 2);
    enqueue(fila, 3);
    enqueue(fila, 4);
    enqueue(fila, 5);

    printf("Fila original: ");
    imprimirFila(fila);

    inverterFila(fila);

    printf("Fila invertida: ");
    imprimirFila(fila);

    free(fila->dados);
    free(fila);
    return 0;
}
