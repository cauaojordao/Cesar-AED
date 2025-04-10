#include <stdio.h>

typedef struct {
    float base;
    float altura;
} Retangulo;

float calcularArea(Retangulo r) {
    return r.base * r.altura;
}

float calcularPerimetro(Retangulo r) {
    return 2 * (r.base + r.altura);
}

int main() {
    Retangulo ret;
    
    printf("Digite a base do retângulo: ");
    scanf("%f", &ret.base);
    
    printf("Digite a altura do retângulo: ");
    scanf("%f", &ret.altura);
    
    printf("Área: %.2f\n", calcularArea(ret));
    printf("Perímetro: %.2f\n", calcularPerimetro(ret));
    
    return 0;
}