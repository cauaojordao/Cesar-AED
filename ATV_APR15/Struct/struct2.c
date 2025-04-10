#include <stdio.h>

typedef struct Aluno{
    char nome[50];
    int matricula;
    float nota;
} Aluno;

int main(){
    
    int length = 2;
    Aluno alunos[length];
    float media = 0;
    
    for(int i = 0; i < length; i++){
        printf("Dados do aluno %d\n", i);
        scanf("%s", alunos[i].nome);
        scanf("%d", &alunos[i].matricula);
        scanf("%f", &alunos[i].nota);
        
        media = media + alunos[i].nota;
    }
    
    for(int i = 0; i < length; i++){
        printf("\nAluno %d:\nNome: %s\nMatrícula: %d\nNota: %f\n", i, alunos[i].nome,alunos[i].matricula,alunos[i].nota);
    }
    
    printf("\n\nMédia: %f", media/length);
    
    
    return 0;
}