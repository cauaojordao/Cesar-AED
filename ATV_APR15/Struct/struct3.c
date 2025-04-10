#include <stdio.h>

typedef struct Produto{
    char nome[50];
    int codigo;
    float preco;
} Produto;

void detalhes(Produto p){
    printf("Nome: %s\n", p.nome);
    printf("Código: %d\n", p.codigo);
    printf("Preço: %.2f\n", p.preco);
}

int main()
{
    Produto p = {
        .nome = "Sabão",
        .codigo = 2,
        .preco = 20.5f,
    };
    
    detalhes(p);

    return 0;
}