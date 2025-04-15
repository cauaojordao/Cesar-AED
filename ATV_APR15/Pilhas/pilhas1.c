#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* dados;
    int topo;
    int capacidade;
} Pilha;

Pilha* criarPilha(int capacidade) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->dados = (int*)malloc(sizeof(int) * capacidade);
    pilha->topo = 0;
    pilha->capacidade = capacidade;
    return pilha;
}

void push(Pilha* pilha, int valor) {
    if (pilha->topo + 1 == pilha->capacidade) {
        pilha->capacidade *= 2;
        pilha->dados = realloc(pilha->dados, pilha->capacidade * sizeof(int));
    }
    pilha->dados[++pilha->topo] = valor;
}

void pop(Pilha* pilha) {
    if (pilha->topo >= 0) {
        pilha->topo--;
    }
}

int top(Pilha* pilha) {
    if (pilha->topo >= 0) {
        return pilha->dados[pilha->topo];
    }
    return 0;
}

int isEmpty(Pilha* pilha) {
    return pilha->topo == 0;
}

void liberarPilha(Pilha* pilha) {
    free(pilha->dados);
    free(pilha);
}

int main() {
    Pilha* pilha = criarPilha(4);

    for (int i = 0; i < 10; i++) {
        push(pilha, i);
    }

    printf("Topo da pilha: %d\n", top(pilha));

    while (!isEmpty(pilha)) {
        printf("Pop: %d\n", top(pilha));
        pop(pilha);
    }

    liberarPilha(pilha);
    return 0;
}
