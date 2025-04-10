#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contato {
    char nome[50];
    char telefone[9];
} Contato;

void detalhes(char nome[50], Contato* agenda, int length) {
    for (int i = 0; i < length; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            printf("Telefone: %s\n", agenda[i].telefone);
            return;
        }
    }
}

int main() {
    int length;
    scanf("%d", &length);
    
    Contato* agenda = (Contato*)malloc(length * sizeof(Contato));
    
    for (int i = 0; i < length; i++) {
        printf("Digite o nome e o telefone do contato %d:\n", i + 1);
        scanf(" %49[^\n]", agenda[i].nome);
        scanf(" %8[^\n]", agenda[i].telefone);
    }
    
    char nome[50];
    printf("Digite o nome a buscar: ");
    scanf(" %49[^\n]", nome);
    
    detalhes(nome, agenda, length);
    free(agenda);
    return 0;
}