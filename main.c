#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <windows.h>

struct ApresentacaoNo {
    char nome[20];  // Nome da Apresentacao
    int dia;
    int mes;
    char horario[5];
    struct PoltronaNo *poltronas;
    struct ApresentacaoNo *esquerda;
    struct ApresentacaoNo *direita;
};
typedef struct ApresentacaoNo ApresentacaoNo;
typedef struct ApresentacaoNo *ApresentacaoArvore;

struct PoltronaNo {
    int NumPoltrona;
    struct PoltronaNo *esquerda;
    struct PoltronaNo *direita;
};
typedef struct PoltronaNo PoltronaNo;
typedef struct PoltronaNo *PoltronaArvore;

void logo() {
    printf("-----------------------------\n");
    printf("|       Teatro Vegetti      |\n");
    printf("-----------------------------\n");
}

ApresentacaoArvore balancearApresentacoes(ApresentacaoArvore raizApresentacao, ApresentacaoArvore novoNo);

PoltronaArvore balancearPoltronas(PoltronaArvore raizPoltrona);

ApresentacaoArvore CriarNoApresentacao(char nome[], int dia, int mes, char horario[]) {
    ApresentacaoArvore novoNo = (ApresentacaoArvore)malloc(sizeof(ApresentacaoNo));
    if (novoNo != NULL) {
        strcpy(novoNo->nome, nome);
        novoNo->dia = dia;
        novoNo->mes = mes;
        strcpy(novoNo->horario, horario);
        novoNo->poltronas = NULL;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
    } else {
        printf("Erro na alocação de memória.\n");
    }
    return novoNo;
}

PoltronaArvore CriarNoPoltrona(int numPoltrona) {
    PoltronaArvore novoNo = (PoltronaArvore)malloc(sizeof(PoltronaNo));
    if (novoNo != NULL) {
        novoNo->NumPoltrona = numPoltrona;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
    } else {
        printf("Erro na alocação de memória.\n");
    }
    return novoNo;
}

#include "src/atualizarApresentacao.h"
#include "src/balancearApresentacoes.h"
#include "src/cadastrarApresentacao.h"
#include "src/deletarApresentacao.h"
#include "src/listarApresentacoes.h"
#include "src/atualizarPoltrona.h"
#include "src/balancearPoltronas.h"
#include "src/deletarPoltrona.h"
#include "src/cadastrarPoltrona.h"
#include "src/listarPoltronas.h"


void liberarArvoreApresentacao(ApresentacaoArvore raiz) {
    if (raiz != NULL) {
        liberarArvoreApresentacao(raiz->esquerda);
        liberarArvoreApresentacao(raiz->direita);
        free(raiz);
    }
}

void liberarArvorePoltronas(PoltronaArvore raiz) {
    if (raiz != NULL) {
        liberarArvorePoltronas(raiz->esquerda);
        liberarArvorePoltronas(raiz->direita);
        free(raiz);
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    ApresentacaoArvore raizApresentacao = NULL;
    PoltronaArvore raizPoltrona = NULL;
    char nome[20];
    // int numPoltrona;
    int alt = 0;
    int alt1 = 0;

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
                    printf("Selecione a opção desejada\n[1] - Cadastrar Apresentação\n[2] - Atualizar Apresentação\n[3] - Listar Apresentações\n[4] - Deletar Apresentação\n[0] - Voltar\n->");
                    scanf("%d", &alt1);

                    switch (alt1) {
                        case 1:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|        Cadastrar Apresentação        |\n");
                            printf("----------------------------------------\n");
                            cadastrarApresentacao(&raizApresentacao);
                            break;
                        case 2:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|        Atualizar Apresentação        |\n");
                            printf("----------------------------------------\n");
                            atualizarApresentacao(&raizApresentacao);
                            break;
                        case 3:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|         Listar Apresentações         |\n");
                            printf("----------------------------------------\n");
                            listarApresentacoes(raizApresentacao);
                            break;
                        case 4:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|          Deletar Apresentação        |\n");
                            printf("----------------------------------------\n");
                            deletarApresentacao(&raizApresentacao, nome);
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
                            cadastrarPoltrona(&raizPoltrona);
                            break;
                        case 2:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|           Atualizar Poltrona         |\n");
                            printf("----------------------------------------\n");
                            atualizarPoltrona(&raizPoltrona);
                            break;
                        case 3:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|           Listar Poltronas           |\n");
                            printf("----------------------------------------\n");
                            listarPoltronas(raizPoltrona);
                            break;
                        case 4:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|            Deletar Poltrona          |\n");
                            printf("----------------------------------------\n");
                            deletarPoltrona(&raizPoltrona);
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
    liberarArvoreApresentacao(raizApresentacao);
    liberarArvorePoltronas(raizPoltrona);
    return 0;
}