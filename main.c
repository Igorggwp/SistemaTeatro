#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <windows.h>

struct Poltrona {
    int numero;
    char status; // R = Reservado, L = Livre
    struct Poltrona *esquerda;
    struct Poltrona *direita;
};
typedef struct Poltrona Poltrona;
typedef struct Poltrona *Arvore;

struct Apresentacao {
    char nome[20];  // Nome da Apresentacao
    int dia;
    int mes;
    char horario[6];
    Arvore poltronas;
    struct Apresentacao *proxima;
};
typedef struct Apresentacao Apresentacao;

struct NoApresentacao {
    Apresentacao apresentacao;
    struct NoApresentacao *proxima;
};
typedef struct NoApresentacao NoApresentacao;
typedef NoApresentacao *Lista;


void logo() {
    printf("-----------------------------\n");
    printf("|       Teatro Vegetti      |\n");
    printf("-----------------------------\n");
}



Arvore encontrarMenorNo(Arvore raiz);

Arvore balancear(Arvore raiz, Arvore novoNo);

Arvore CriarNo(int numero, char status) {
    Arvore novoNo = (Arvore)malloc(sizeof(Poltrona));
    if (novoNo != NULL) {
        novoNo->numero = numero;
        novoNo->status = status;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
    } else {
        printf("Erro na alocação de memória.\n");
    }
    return novoNo;
}

#include "src/atualizar.h"
#include "src/balancear.h"
#include "src/cadastrar.h"
#include "src/deletar.h"
#include "src/listar.h"
#include "src/lista.h"

void liberarArvore(Arvore raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

void liberarLista(Lista lista) {
    while (lista != NULL) {
        NoApresentacao *temp = lista;
        lista = lista->proxima;
        liberarArvore(temp->apresentacao.poltronas);
        free(temp);
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Arvore raiz = NULL;
    int alt = 0;
    int alt1 = 0;
    int alt2 = 0;
    Lista lista = NULL;

    do {
        system("cls");
        logo();
        printf("Seja bem vindo ao Teatro Vegetti!\n\nSelecione a opção desejada\n[1] - Apresentações\n[2] - Poltronas\n[0] - Sair\n->");
        scanf("%d", &alt);

        switch (alt) {
            case 1:
                do {
                    // system("cls");
                    logo();
                    printf("Selecione a opção desejada\n[1] - Cadastrar Apresentação\n[2] - Listar Apresentação\n[0] - Voltar\n->");
                    scanf("%d", &alt1);

                    switch (alt1) {
                        case 1:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|         Cadastrar Apresentação        |\n");
                            printf("----------------------------------------\n");
                            cadastrarApresentacao(&lista);
                            break;
                        case 2:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|          Listar Apresentações         |\n");
                            printf("----------------------------------------\n");
                            listarApresentacoes(lista);
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
                    // system("cls");
                    logo();
                    printf("Selecione a opção desejada\n[1] - Cadastrar Poltrona\n[2] - Atualizar Poltrona\n[3] - Listar Poltrona\n[4] - Deletar Poltrona\n[0] - Voltar\n->");
                    scanf("%d", &alt2);

                    switch (alt2) {
                        case 1:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|          Cadastrar Poltrona          |\n");
                            printf("----------------------------------------\n");
                            cadastrar(&raiz);
                            break;
                        case 2:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|          Atualizar Poltrona          |\n");
                            printf("----------------------------------------\n");
                            atualizar(&raiz);
                            break;
                        case 3:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|           Listar Poltrona            |\n");
                            printf("----------------------------------------\n");
                            listar(raiz);
                            break;
                        case 4:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|            Deletar Poltrona          |\n");
                            printf("----------------------------------------\n");
                            deletar(&raiz);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Opção inválida. Tente novamente.\n");
                            break;
                    }
                } while (alt2 != 0);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (alt != 0);
    liberarLista(lista);
    liberarArvore(raiz);
    return 0;
}