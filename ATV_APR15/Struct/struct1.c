#include <stdio.h>

typedef struct Pessoa{
    char nome[50];
    int idade;
    float altura;
} Pessoa;

int main(){
    
    Pessoa p1;
    
    scanf("%s", p1.nome);
    scanf("%d", &p1.idade);
    scanf("%f", &p1.altura);
    
    printf("Pessoa 1: %s\nIdade: %d\nAltura: %f",p1.nome,p1.idade,p1.altura);
    
    return 0;
}