#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PERGUNTA 200
#define MAX_ALT 80
#define MAX_NOME 50

typedef struct {
    char enunciado[MAX_PERGUNTA];
    char alternativas[4][MAX_ALT];
    int correta;
} Pergunta;

typedef struct {
    char nome[MAX_NOME];
    int pontos;
} Jogador;




int main(){
    srand(time(NULL));

    int opcao;
    do{ 
        printf("contestas.io\n");
        printf("1. Jogar\n");
        printf("2. Ver ranking\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                jogar();
                break;
            case 2:
                verRanking();
                break;
            case 4:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while(opcao != 4);

    return 0;

}
