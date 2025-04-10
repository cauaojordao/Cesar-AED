#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char titular[50];
    int numero;
    float saldo;
} ContaBancaria;

void depositar(ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    printf("Depósito realizado. Novo saldo: %.2f\n", conta->saldo);
}

bool sacar(ContaBancaria *conta, float valor) {
    if(valor > conta->saldo) {
        printf("Saldo insuficiente!\n");
        return false;
    }
    conta->saldo -= valor;
    printf("Saque realizado. Novo saldo: %.2f\n", conta->saldo);
    return true;
}

void exibirSaldo(ContaBancaria conta) {
    printf("Saldo atual: %.2f\n", conta.saldo);
}

int main() {
    ContaBancaria conta;
    
    printf("Nome do titular: ");
    scanf("%[^\n]", conta.titular);
    
    printf("Número da conta: ");
    scanf("%d", &conta.numero);
    
    conta.saldo = 0;
    
    int opcao;
    float valor;
    
    do {
        printf("\n1 - Depositar\n2 - Sacar\n3 - Ver saldo\n0 - Sair\n");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Valor para depositar: ");
                scanf("%f", &valor);
                depositar(&conta, valor);
                break;
            case 2:
                printf("Valor para sacar: ");
                scanf("%f", &valor);
                sacar(&conta, valor);
                break;
            case 3:
                exibirSaldo(conta);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);
    
    return 0;
}