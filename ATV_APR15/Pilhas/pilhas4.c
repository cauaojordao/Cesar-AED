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
    if (isEmpty(topo)) return topo;
    No* temp = topo;
    topo = topo->prox;
    free(temp);
    return topo;
}

int top(No* topo) {
    if (isEmpty(topo)) return -1;
    return topo->valor;
}

void imprimirBinario(No** topo) {
    while (!isEmpty(*topo)) {
        printf("%d", top(*topo));
        *topo = pop(*topo);
    }
    printf("\n");
}

void limpar(No** topo) {
    while (!isEmpty(*topo)) {
        *topo = pop(*topo);
    }
}

int main() {
    No* pilha = NULL;
    int numero;

    printf("Digite um número decimal: ");
    scanf("%d", &numero);

    if (numero == 0) {
        printf("Binário: 0\n");
        return 0;
    }

    while (numero > 0) {
        int resto = numero % 2;
        pilha = push(pilha, resto);
        numero /= 2;
    }

    printf("Binário: ");
    imprimirBinario(&pilha);
    limpar(&pilha);
    return 0;
}
