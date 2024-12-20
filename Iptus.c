#include <stdio.h>
#include <stdlib.h>

int main(){
    float valor_casa;
        printf("Digite o valor da sua casa");
            scanf("%f", &valor_casa);
    if (valor_casa >= 150 && valor_casa <= 200){
        float calculo;
            calculo = valor_casa * 0.02;
        printf("Valor do IPTU e de %.3f\n", calculo);
    }
        if (valor_casa >= 200 && valor_casa <= 300){
        float calculo;
            calculo = valor_casa * 0.05;
        printf("Valor do IPTU e de %.3f\n", calculo);   
        }
        
        if (valor_casa >= 300 && valor_casa <= 500){
        float calculo;
            calculo = valor_casa * 0.10;
        printf("Valor do IPTU e de %.3f\n", calculo);   
        }
    
}