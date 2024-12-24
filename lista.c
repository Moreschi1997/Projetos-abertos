#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Usando union para fazer um bloco de variaveis diferentes*/

    typedef struct {
        char nome[85];
        char numero_telefone[16];
        char email[100];
        char cpf[12];
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
        printf("\n=== Gerenciador de dados ===\n");
        printf("1. Adicionar os dados\n");
        printf("2. Exibir dados\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
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
        printf("Limites de dados cadastrados\n");
        return;
            }
    printf("\n=== Adicionar dados ===\n");

    printf("Digite o seu nome: ");
    fgets(dados_cadastrados[*total].nome, 85, stdin);
    dados_cadastrados[*total].nome[strcspn(dados_cadastrados[*total].nome, "\n")] = '\0'; /* Contagem no índice 0 */

    printf("Digite o seu número de telefone: ");
    fgets(dados_cadastrados[*total].numero_telefone, 16, stdin);
    dados_cadastrados[*total].numero_telefone[strcspn(dados_cadastrados[*total].numero_telefone, "\n")] = '\0'; /*Contagem no índice 0*/

    printf("Digite o e-mail: ");
    fgets(dados_cadastrados[*total].email, 100, stdin);
    dados_cadastrados[*total].email[strcspn(dados_cadastrados[*total].email, "\n")] = '\0';

    printf("Digite o CPF: ");
    fgets(dados_cadastrados[*total].cpf, 12, stdin);
    dados_cadastrados[*total].cpf[strcspn(dados_cadastrados[*total].cpf, "\n")] = '\0';

    (*total)++;
    printf("Dados adicionados com sucesso!\n");
    }
    void exibir_dados(dados dados_cadastrados[], int total){
        printf("\n=== Exibir dados ===\n");

        if(total == 0){
            printf("nenhum dado cadastrado\n");
            return;
            }
        
        for(int i = 0; i < total; i++){
            printf("Registro: %d\n", i +1);
            printf("Nome: %s\n", dados_cadastrados[i].nome);
            printf("Número: %s\n", dados_cadastrados[i].numero_telefone);
            printf("e-mail: %s\n", dados_cadastrados[i].email);
            printf("CPF: %s\n", dados_cadastrados[i].cpf);

        }
    }





