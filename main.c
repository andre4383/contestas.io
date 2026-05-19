#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PERGUNTA 200
#define MAX_ALT 80
#define MAX_NOME 50

typedef struct {
    char categoria[MAX_ALT];
    char enunciado[MAX_PERGUNTA];
    char alternativas[4][MAX_ALT];
    int correta; 
} Pergunta;

typedef struct {
    char nome[MAX_NOME];
    int pontos; 
} Jogador;

// RECURSIVIDADE: Uma funcao que chama a si mesma repetidas vezes ate atingir uma condicao de parada.
void embaralhar(Pergunta *vetor, int tamanho) {
    if (tamanho <= 1) return; 
    
    int i = rand() % tamanho; 
    
    Pergunta temp = vetor[tamanho - 1];
    vetor[tamanho - 1] = vetor[i];
    vetor[i] = temp;
    
    // Chamada Recursiva: A funcao chama a si mesma passando o vetor com um tamanho menor (-1), deixando a ultima carta (ja embaralhada) quieta.
    embaralhar(vetor, tamanho - 1);
}

void atualizar_ranking(char *nome, int pontos) {
    Jogador ranking[11]; 
    int qtd = 0;
    
    FILE *f = fopen("ranking.txt", "r");
    if (f != NULL) {
        while (fscanf(f, "%[^;];%d\n", ranking[qtd].nome, &ranking[qtd].pontos) != EOF) {
            qtd++;
        }
        fclose(f);
    }

    strcpy(ranking[qtd].nome, nome);
    ranking[qtd].pontos = pontos;
    qtd++;

    for (int i = 0; i < qtd - 1; i++) {
        for (int j = i + 1; j < qtd; j++) {
            if (ranking[i].pontos < ranking[j].pontos) {
                Jogador temp = ranking[i];
                ranking[i] = ranking[j];
                ranking[j] = temp;
            }
        }
    }

    f = fopen("ranking.txt", "w");
    int limite = (qtd > 10) ? 10 : qtd;
    for (int i = 0; i < limite; i++) {
        fprintf(f, "%s;%d\n", ranking[i].nome, ranking[i].pontos);
    }
    fclose(f);
}

void jogar() {
    FILE *f = fopen("perguntas.txt", "r");
    if (f == NULL) {
        printf("\nNenhuma pergunta encontrada! Use o Modo Professor primeiro.\n");
        return;
    }

    int linhas = 0;
    char buffer[250];
    while (fgets(buffer, 250, f) != NULL) {
        linhas++;
    }
    int qtd_perguntas = linhas / 7;
    
    rewind(f);

    // MALLOC (Alocacao Dinamica): O programa nao sabe quantas perguntas existem no txt de antemao.
    // O malloc serve para pedir ao computador exatamente o espaco de memoria necessario no momento em que o jogo roda.
    Pergunta *perguntas = (Pergunta*) malloc(qtd_perguntas * sizeof(Pergunta));

    for (int i = 0; i < qtd_perguntas; i++) {
        fscanf(f, " %[^\n]", perguntas[i].categoria);
        fscanf(f, " %[^\n]", perguntas[i].enunciado);
        for (int j = 0; j < 4; j++) {
            fscanf(f, " %[^\n]", perguntas[i].alternativas[j]);
        }
        fscanf(f, "%d", &perguntas[i].correta);
    }
    fclose(f);

    embaralhar(perguntas, qtd_perguntas);

    int pontos = 0;
    int multiplicador = 1;
    printf("\n=== VAMOS JOGAR! ===\n");
    
    for (int i = 0; i < qtd_perguntas; i++) {
        printf("\n[%s] %d) %s\n", perguntas[i].categoria, i + 1, perguntas[i].enunciado);
        for (int j = 0; j < 4; j++) {
            printf("   %d. %s\n", j + 1, perguntas[i].alternativas[j]);
        }
        
        int resposta;
        printf("Escolha uma alternativa (1 a 4) [TEMPO LIMITE: 10s]: ");
        
        time_t tempo_inicio = time(NULL);
        scanf("%d", &resposta);
        time_t tempo_fim = time(NULL);
        
        if (tempo_fim - tempo_inicio > 10) {
            printf(">>> TEMPO ESGOTADO! Demorou %d segundos. Perdeu a vez.\n", (int)(tempo_fim - tempo_inicio));
            multiplicador = 1; // Zera o combo se demorar muito
            continue; // Pula para a próxima pergunta
        }

        switch (resposta) {
            case 1: case 2: case 3: case 4:
                if ((resposta - 1) == perguntas[i].correta) {
                    int pontos_ganhos = 10 * multiplicador;
                    printf(">>> CERTO! +%d pontos (Combo x%d)\n", pontos_ganhos, multiplicador);
                    pontos += pontos_ganhos;
                    multiplicador++;
                } else {
                    printf(">>> ERRADO! A correta era a numero %d\n", perguntas[i].correta + 1);
                    multiplicador = 1;
                }
                break;
            default:
                printf(">>> OPCAO INVALIDA! Perdeu a vez.\n");
                multiplicador = 1;
                break;
        }
    }

    printf("\nFim do Quiz! Voce fez %d pontos.\n", pontos);
    char nome[MAX_NOME];
    printf("Qual o seu nome? ");
    scanf(" %[^\n]", nome); 
    
    atualizar_ranking(nome, pontos);
    
    free(perguntas); 
}

void ver_ranking() {
    FILE *f = fopen("ranking.txt", "r");
    if (f == NULL) {
        printf("\nO ranking ainda esta vazio!\n");
        return;
    }

    printf("\n=== TOP 10 JOGADORES ===\n");
    char nome[MAX_NOME];
    int pontos;
    int pos = 1;
    
    while (fscanf(f, "%[^;];%d\n", nome, &pontos) != EOF) {
        printf("%d. %s - %d pontos\n", pos++, nome, pontos);
    }
    fclose(f);
    printf("========================\n");
}

void modo_professor() {
    FILE *f = fopen("perguntas.txt", "a"); 
    if (f == NULL) {
        printf("\nErro ao abrir o arquivo.\n");
        return;
    }

    Pergunta p;
    printf("\n--- MODO PROFESSOR ---\n");
    
    printf("Categoria da pergunta: ");
    scanf(" %[^\n]", p.categoria);
    fprintf(f, "%s\n", p.categoria);
    
    printf("Enunciado da pergunta: ");
    scanf(" %[^\n]", p.enunciado);
    fprintf(f, "%s\n", p.enunciado);

    for (int i = 0; i < 4; i++) {
        printf("Alternativa %d: ", i + 1);
        scanf(" %[^\n]", p.alternativas[i]);
        fprintf(f, "%s\n", p.alternativas[i]);
    }

    printf("Indique a correta (1 a 4): ");
    scanf("%d", &p.correta);
    fprintf(f, "%d\n", p.correta - 1); 

    fclose(f);
    printf("\nPergunta adicionada com sucesso no arquivo!\n");
}

int main() {
    srand(time(NULL));
    int opcao;

    do {
        printf("\n======== MENU DO QUIZ ========\n");
        printf("1) Jogar\n");
        printf("2) Ver ranking\n");
        printf("3) Modo professor\n");
        printf("4) Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: jogar(); break;
            case 2: ver_ranking(); break;
            case 3: modo_professor(); break;
            case 4: printf("Saindo do programa...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}
