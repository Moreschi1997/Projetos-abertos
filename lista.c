#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Usando union para fazer um bloco de variaveis diferentes*/
typedef union{
    struct {
        char nome[100];
        char numero_telefone[16];
    } dados_basicos;
    struct {
        char email[100];
        char cpf[12];
    } dados_detalhados;
} dados;
    /* Funções */
    void adicionar_dados(dados dados_cadastrados[], int *total); /* Criado a Arrays dados_cadastrados assim fazendo armazenamento do que for escrito; int *total = ponteiro */
    void exibir_dados(dados dados_cadastrados[], int total); /* Retorno do ponteiro, fazendo a contagem, assim também e criado um tipo de array contendo os registros*/

int main(){
    dados dados_cadastrados[100];
    int totaldados = 0; /*Criando um contador*/
    int opcao;
    /* Usado a lógica do-while */
    do{
        printf("\n===Gerenciador de dados===\n");
        printf("1. Adicionar os dados\n");
        printf("2. Exibir contatos\n");
        printf("3. Sair\n");
        printf("Escolha uma opção");
            scanf("%d", &opcao);
        getchar();

    switch(opcao){
        case 1:
        adicionar_dados(dados_cadastrados, &totaldados);
        break;
        case 2:
        exibir_dados(dados_cadastrados, totaldados);
        break;
        case 3:
        printf("Saindo...\n");
        break;
        default:
        printf("Opção invalida!\n");
            }   
    } while (opcao != 3);
    return 0;
}

void adicionar_dados(dados dados_cadastrados[], int *total){
    const int MAX_DADOS = 100; /* Limite de registro */
        if(*total >= MAX_DADOS){
            printf("Limites de dados cadastrados");
            return 0;
        }

}

