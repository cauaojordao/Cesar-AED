#include <stdio.h>
#include <stdlib.h>

typedef struct Carro{
    char marca[50];
    int ano;
    float preco;
} Carro;

int main(){

    Carro* c = (Carro*)malloc(sizeof(Carro));
    scanf("%s", c->marca);
    scanf("%d", &c->ano);
    scanf("%f", &c->preco);

    printf("Informa es sobre o carro:\nNome: %s\nAno: %d\nPre o: %.2f", c->marca, c->ano, c->preco);

    free(c);
    return 0;
}