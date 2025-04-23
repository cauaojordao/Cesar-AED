#include <stdio.h>
#include <stdlib.h>

typedef struct Endereco {
    int numero;
    char rua[50];
} Endereco;

typedef struct Pessoa {
    char nome[50];
    int idade;
    Endereco *end;
} Pessoa;

int main(){
    
    Pessoa *p = (Pessoa*)malloc(sizeof(Pessoa));
    p->end = (Endereco*)malloc(sizeof(Endereco));

    scanf("%d", p->end->numero);

    return 0;
}