#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char valor;
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
    while (topo) {
        printf("%c", topo->valor);
        topo = topo->prox;
    }
}

int main() {
    No* pilha = NULL;

    char p[100];
    scanf("%[^\n]%*c", p);

    for (int i = 0; p[i]; i++) {
        
            pilha = push(pilha, p[i]);
        
    }

    imprimir_pilha(pilha);
    limpar(pilha);
    return 0;
}
