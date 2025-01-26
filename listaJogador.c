#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome [100];
    int idade;  
} registroJogadores;

void listasJogadores(registroJogadores *jogador){
    printf("Digite o nome do jogador..: ");

    fgets(jogador->nome, sizeof(jogador->nome), stdin);

    jogador->nome[strcspn(jogador->nome, "\n")] = '\0';//Usado strcspn para remover o caractere '\n', que o fgets adiciona
    /* Digitar a idade do jogador */

    getchar();

    printf("Digite a idade do jogador:");
    if(scanf("%d", &jogador->idade) != 1){
        printf("Erro: Idade invalida\n");
        exit(1); //finaliza o por erro
    }
    getchar();//limpar o buffer
}

int classificacaoJogador(registroJogadores *jogador){
    /* Determina a categoria do jogador */
    if(jogador->idade >= 10 && jogador->idade <= 12){
    printf("Jodor pertence ao sub-12\n");
    return 12;
    }
    else if(jogador->idade > 12 && jogador->idade <= 15){
    printf("Jogador pertence ao sub-15\n");
    return 15;
    }
    else if(jogador->idade > 15 && jogador->idade <= 17){
    printf("Jogador perence ao sub-17\n");
    return 17;
    }
    else{
    printf("Jogador se alocando para time profissional\n");
    return 18;
    }

}

int main(){
    registroJogadores jogador;

    listasJogadores(&jogador);

    int categoria = classificacaoJogador(&jogador);

    printf("\n--Jogador registrado--\n");
    printf("Nome..: %s\n", jogador.nome);
    printf("Idade do jogador..: %d\n", jogador.idade);

    printf("A qual categoria ele pertence: ");
    if(categoria == 12){
        printf("Pertence ao sub-12\n");
    }
    else if(categoria == 15){
        printf("Pertence ao sub-15\n");
    }
    else if(categoria == 17){
        printf("Pertence ao sub-17\n");
    }
    else if (categoria >= 18){
        printf("Time principal\n");
    }


    return 0;

}