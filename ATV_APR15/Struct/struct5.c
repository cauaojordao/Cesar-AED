#include <stdio.h>
#include <stdlib.h>

typedef struct Funcionario{
    char nome[50];
    char cargo[50];
    float salario;
} Funcionario;

int main(){

    int length;
    scanf("%d", &length);
    Funcionario* funcionarios = (Funcionario*)malloc(length * sizeof(Funcionario));
    
    for (int i = 0; i < length; i++) {
        printf("Digite nome, cargo e salário do funcionário %d:\n", i + 1);
        scanf("%s %s %f", funcionarios[i].nome, funcionarios[i].cargo, &funcionarios[i].salario);
    }

    free(funcionarios);
    return 0;
}