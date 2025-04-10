#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    char diagnostico[100];
} Paciente;

void exibirIdosos(Paciente pacientes[], int length) {
    printf("\nPacientes acima de 60 anos:\n");
    for(int i = 0; i < length; i++) {
        if(pacientes[i].idade > 60) {
            printf("Nome: %s\n", pacientes[i].nome);
            printf("Idade: %d\n", pacientes[i].idade);
            printf("Diagnóstico: %s\n\n", pacientes[i].diagnostico);
        }
    }
}

int main() {
    
    int length;
    scanf("%d", &length);
    
    Paciente* pacientes = (Paciente*)malloc(length * sizeof(Paciente));
    
    for(int i = 0; i < length; i++) {
        printf("\nPaciente %d:\n", i+1);
        scanf("%s", pacientes[i].nome);
        
        printf("Idade: ");
        scanf("%d", &pacientes[i].idade);
        
        printf("Diagnóstico: ");
        scanf("%[^\n]", pacientes[i].diagnostico);
    }
    
    exibirIdosos(pacientes, length);
    
    return 0;
}