#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Função para exibir IP's*/
void exibir_ip(unsigned int ip){
    printf("%d.%d.%d.%d",
    (ip >> 24) & 0xFF, /* Usado operador ">>" para os bits se alocarem a direita */
    (ip >> 16) & 0xFF,
    (ip >> 8) & 0xFF,
    ip & 0xFF);
}

/* Gerador de IP's, contendo classes */ /* Unsigned para gerar valores positivos */
/* Função */
unsigned int gerar_ip(char classes){
    unsigned int ip = 0;
    /* Endereços de classe A entre 1.0.0.0 a 126.255.255.255 */
        if(classes == 'A'){
            ip |= (rand() % 126 + 1) << 24; /* Valores no intervalo de 1 a 126 */
            ip |= (rand() % 256) << 16;  /* Valores no intervalo de 0 a 255 */
            ip |= (rand() % 256) << 8; /* Valores no intervalo de 0 a 255*/
            ip |= (rand() % 256);
        }
        else if(classes == 'B'){
            ip |= (rand() % 64 + 128) << 24; /* Valores no intervalo de 128 a 191*/
            ip |= (rand() % 256) << 16;
            ip |= (rand() % 256) << 8;
            ip |= (rand() % 256);
        }
        else if(classes == 'C'){
            ip |= (rand() % 32 + 192) << 24; /* Valores no intervalo de 193 a 223 */
            ip |= (rand() % 256) << 16;
            ip |= (rand() % 256) << 8;
            ip |= (rand() % 256);
        }
        else{
            printf("Classes invalidas\n");
            return 0;
        }
    return ip;
}

int main(){
    srand(time(NULL)); /* Gera números aleatórios */
    char classes;

    /*Escolha da Classe*/
    printf("Escolha a classe IP A, B e C:...  ");
    scanf(" %c", &classes);

    /* Usado a lógica "for" para ter um determinado valor, usando "i" como contador e o valor máximo de "i" será  10  */

    for(int i = 0; i <= 10; i++){
    unsigned int ip;
    ip = gerar_ip(classes); 
        if(ip != 0){
            printf("IP gerado: ");
            exibir_ip(ip);
            printf("\n");
       }
    }
    return 0;

}