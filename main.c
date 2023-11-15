#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <windows.h>


struct Poltrona {
    int NumPoltrona;
    struct Poltrona *prox;
};
typedef struct Poltrona poltrona;
typedef poltrona* ListaPoltrona;

struct No {
    char nome[20];  // Nome da Apresentacao
    int dia;
    char horario[5];
    ListaPoltrona poltronas;
    struct No *esquerda;
    struct No *direita;
};
typedef struct No no;
typedef struct No *Apresentacao;

void logo() {
    printf("-----------------------------\n");
    printf("|       Teatro Vegetti      |\n");
    printf("-----------------------------\n");
}

Apresentacao balancearApresentacoes(Apresentacao raiz);

Apresentacao CriarNo(char nome[], int dia, char horario[]) {
    Apresentacao novoNo = (Apresentacao)malloc(sizeof(no));
    if (novoNo != NULL) {
        strcpy(novoNo->nome, nome);
        novoNo->dia = dia;
        strcpy(novoNo->horario, horario);
        novoNo->poltronas = NULL;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
    } else {
        printf("Erro na alocação de memôria.\n");
    }
    return novoNo;
}

#include "src/atualizarApresentacao.h"
#include "src/balancearApresentacoes.h"
#include "src/deletarApresentacao.h"
#include "src/inserirApresentacao.h"
#include "src/listarApresentacoes.h"
#include "src/atualizarPoltrona.h"
#include "src/balancearPoltronas.h"
#include "src/deletarPoltrona.h"
#include "src/inserirPoltrona.h"
#include "src/listarPoltronas.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Apresentacao raiz = NULL;
    int alt = 0;
    int alt1 = 0;
    // int dia;
    // char nome[20];
    // char horario[5];

    do {
        system("cls");
        logo();
        printf("Seja bem vindo ao Teatro Vegetti!\n\nSelecione a opção desejada\n[1] - Apresentações\n[2] - Poltronas\n[0] - Sair\n->");
        scanf("%d", &alt);

        switch (alt) {
            case 1:
                do {
                    system("cls");
                    logo();
                    printf("Selecione a opção desejada\n[1] - Cadastrar Apresentação\n[2] - Atualizar Apresentação\n[3] -aar Apresentações\n[4] - Deletar Apresentação\n[0] - Voltar\n->");
                    scanf("%d", &alt1);

                    switch (alt1) {
                        case 1:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|        Cadastrar Apresentação        |\n");
                            printf("----------------------------------------\n");
                            inserirApresentacao(&raiz);
                            break;
                        case 2:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|        Atualizar Apresentação        |\n");
                            printf("----------------------------------------\n");
                            atualizarApresentacao(&raiz);
                            break;
                        case 3:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|         Listar Apresentações         |\n");
                            printf("----------------------------------------\n");
                            listarApresentacoes();
                            break;
                        case 4:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|          Deletar Apresentação        |\n");
                            printf("----------------------------------------\n");
                            deletarApresentacao(&raiz);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Opção inválida. Tente novamente.\n");
                            break;
                    }
                } while (alt1 != 0);
                break;
            case 2:
                do {
                    system("cls");
                    logo();
                    printf("Selecione a opção desejada\n[1] - Cadastrar Poltrona\n[2] - Atualizar Poltrona\n[3] -aar Poltronas\n[4] - Deletar Poltrona\n[0] - Voltar\n->");
                    scanf("%d", &alt1);

                    switch (alt1) {
                        case 1:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|           Cadastrar Poltrona         |\n");
                            printf("----------------------------------------\n");
                            inserirPoltrona();
                            break;
                        case 2:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|           Atualizar Poltrona         |\n");
                            printf("----------------------------------------\n");
                            atualizarPoltrona();
                            break;
                        case 3:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|           Listar Poltronas           |\n");
                            printf("----------------------------------------\n");
                            listarPoltronas();
                            break;
                        case 4:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|            Deletar Poltrona          |\n");
                            printf("----------------------------------------\n");
                            deletarPoltrona();
                            break;
                        case 0:
                            break;
                        default:
                            printf("Opção inválida. Tente novamente.\n");
                            break;
                    }
                } while (alt1 != 0);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (alt != 0);

    return 0;
}