#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

int isEmpty(No* topo) {
    return topo == NULL;
}

No* push(No* topo, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = topo;
    return novo;
}

No* pop(No* topo) {
    if (isEmpty(topo)) {
        printf("Pilha vazia.\n");
        return topo;
    }
    No* temp = topo;
    topo = topo->prox;
    free(temp);
    return topo;
}

int top(No* topo) {
    if (isEmpty(topo)) {
        printf("Pilha vazia.\n");
        return 0;
    }
    return topo->valor;
}

void limpar(No* topo) {
    while (!isEmpty(topo)) {
        topo = pop(topo);
    }
}

void imprimir_pilha(No* topo) {
    printf("TOPO -> ");
    while (topo) {
        printf("%d -> ", topo->valor);
        topo = topo->prox;
    }
    printf("NULL\n");
}

int main() {
    No* pilha = NULL;

    for (int i = 1; i <= 5; i++) {
        pilha = push(pilha, i);
    }

    imprimir_pilha(pilha);
    printf("Topo atual: %d\n", top(pilha));

    while (!isEmpty(pilha)) {
        printf("Removendo: %d\n", top(pilha));
        pilha = pop(pilha);
    }

    limpar(pilha);
    return 0;
}
