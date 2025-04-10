#include <stdio.h>
#include <stdlib.h>

typedef struct Livro{
    char titulo[50];
    char autor[50];
    int ano;
} Livro;

int lancadosApos(int ano, Livro* livros){
    int count = 0;
    for(int i = 0; i < 5; i++){
        if(livros[i].ano > ano){
            printf("Livro: %s foi publicado no ano %d\n", livros[i].titulo, livros[i].ano);
            count++;
        }
    }
    return count;
}

int main(){

    int length;
    scanf("%d", &length);
    Livro* livros = (Livro*)malloc(length * sizeof(Livro));
    
    for (int i = 0; i < length; i++) {
        printf("Digite titulo, autor e ano de lancamento do livro %d:\n", i + 1);
        scanf("%s %s %d", livros[i].titulo, livros[i].autor, &livros[i].ano);
    }

    int count = lancadosApos(2000, livros);
    printf("Livros lancados depois de 2000: %d", count);
    free(livros);
    return 0;
}