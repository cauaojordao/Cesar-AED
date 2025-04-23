#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *prox;
} No;

No* inserir_inicio(No* lista, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = lista;
    return novo;
}

No* inserir_final(No* lista, int valor){
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    if(!lista) return novo;

    No* temp = lista;
    while(temp->prox != NULL){
        temp = temp->prox;
    }
    temp->prox = novo;
    return lista;
}

void imprimir_lista(No* lista) {
    if(lista == NULL) return;
    printf("%d", lista->valor);
    imprimir_lista(lista->prox);
}

No* excluir_especifico(No* lista, int valor){
    if(!lista) {
        printf("Lista vazia\n");
        return lista;
    }

    if(lista->valor == valor){
        No* temp = lista;
        lista = lista->prox;
        free(temp);
        printf("valor exluido\n");
        return lista;
    }

    No* anterior = lista;
    No* temp = lista->prox;
    while(temp != NULL){
        if(temp->valor == valor){
            anterior->prox = temp->prox;
            free(temp);
            printf("Valor Excluído\n");
            return lista;
        }    
        anterior = temp;
        temp = temp->prox;
    }
    printf("Valor não encontrado\n");
    return lista;
}

void limpar_memoria(No* lista){
    if(lista == NULL) return;
    limpar_memoria(lista->prox);
    free(lista);
}

int main(){

    No* lista = NULL;
    
    lista = inserir_inicio(lista, 4);
    lista = inserir_inicio(lista, 1);
    lista = inserir_inicio(lista, 2);
    lista = inserir_final(lista, 5);
    lista = inserir_final(lista, 8);
    lista = inserir_final(lista, 7);
    lista = inserir_inicio(lista, 9);
    lista = inserir_inicio(lista, 3);
    imprimir_lista(lista);
    excluir_especifico(lista, 8);
    imprimir_lista(lista);
    limpar_memoria(lista);
    return 0;
}