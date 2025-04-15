#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
} Cliente;

typedef struct {
    Cliente* dados;
    int capacidade;
    int inicio;
    int fim;
    int tamanho;
} Fila;

Fila* criarFila(int capacidade) {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->dados = (Cliente*)malloc(sizeof(Cliente) * capacidade);
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

void enqueue(Fila* fila, char* nome) {
    if (isFull(fila)) {
        printf("Fila cheia! Não é possível adicionar %s\n", nome);
        return;
    }
    strcpy(fila->dados[fila->fim].nome, nome);
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

Cliente dequeue(Fila* fila) {
    Cliente vazio = { "" };
    if (isEmpty(fila)) {
        printf("Fila vazia! Nenhum cliente para atender.\n");
        return vazio;
    }
    Cliente atendido = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
    return atendido;
}

void liberarFila(Fila* fila) {
    free(fila->dados);
    free(fila);
}

int main() {
    Fila* filaBanco = criarFila(3);

    enqueue(filaBanco, "Alice");
    enqueue(filaBanco, "Bob");
    enqueue(filaBanco, "Carlos");
    enqueue(filaBanco, "Diana");

    while (!isEmpty(filaBanco)) {
        Cliente c = dequeue(filaBanco);
        printf("Atendendo cliente: %s\n", c.nome);
    }

    liberarFila(filaBanco);
    return 0;
}
