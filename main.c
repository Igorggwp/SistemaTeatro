#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>

struct Poltrona {
    int numero; 
    char status; // R = Reservado, L = Livre
    struct Poltrona *esquerda;
    struct Poltrona *direita;
};
typedef struct Poltrona poltrona;
typedef struct Poltrona *Apresentacao;

struct PoltronaNode {
    Apresentacao apresentacao;
    struct PoltronaNode *prox;
};
typedef struct PoltronaNode poltronaNode;
typedef poltronaNode *listaPoltronas;

void logo() {
    printf("-----------------------------\n");
    printf("|       Teatro Vegetti      |\n");
    printf("-----------------------------\n");
}

#include "src/atualizar.h"
#include "src/balancear.h"
#include "src/cadastrar.h"
#include "src/deletar.h"
#include "src/listar.h"

// Função para criar uma árvore
Apresentacao *criaArvore() {
    Apresentacao *raiz = (Apresentacao *)malloc(sizeof(Apresentacao));
    if (raiz != NULL) {
        *raiz = NULL;
    }
    else {
        printf("Erro na alocacao");
        return 0;
    };
    return raiz;
}

// Função recursiva para liberar a memória
void liberarNo(poltrona *liberacao) { // liberacao libera a memória de um nó
    if (liberacao == NULL) {
        return;
    }
    else {
        liberarNo(liberacao->esquerda);
        liberarNo(liberacao->direita);
        free(liberacao);
    }
}

// Libera a memória de toda árvore 
int liberarArvore(Apresentacao *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    else {
        liberarNo(*raiz);
    }
    free(raiz);
    return 1;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    listaPoltronas cabeca = criarlista();
    Apresentacao *raiz = criaArvore();
    int alt, verificar = 0, contagem = 0;
    system("cls");

    while (1) {

        logo();
        printf("Selecione a opção desejada\n[1] - Cadastrar Poltrona\n[2] - Atualizar Poltrona\n[3] - Listar Poltronas\n[4] - Deletar Poltrona\n[0] - Sair\n->");

        if (scanf("%d", &alt) != 1) {
            while (getchar() != '\n');
            system("cls");
            printf("Opção inválida! Insira um número válido.\n");
        } else if (alt == 1 || alt == 2 || alt == 3 || alt == 4 || alt == 0) {
            switch (alt) {
                case 1:
                    system("cls");
                    printf("----------------------------------------\n");
                    printf("|          Cadastrar Poltrona          |\n");
                    printf("----------------------------------------\n");
                    cadastrar(raiz);
                    verificar++;
                    break;
                case 2:
                    system("cls");
                    printf("----------------------------------------\n");
                    printf("|          Atualizar Poltrona          |\n");
                    printf("----------------------------------------\n");
                    atualizar(*raiz);
                    break;
                case 3:
                    system("cls");
                    printf("----------------------------------------\n");
                    printf("|           Listar Poltrona            |\n");
                    printf("----------------------------------------\n");
                    listar(*raiz);
                    break;
                case 4:
                    system("cls");
                    printf("----------------------------------------\n");
                    printf("|            Deletar Poltrona          |\n");
                    printf("----------------------------------------\n");
                    deletar(raiz);
                    break;
                case 0:
                    liberarArvore(raiz);
                    printf("Saindo do Sistema.");
                    exit(1);
            }
        } else {
            system("cls");
            printf("Opção inválida! Por favor, insira uma opção válida.\n");
        }

        // Realizar balanceamento estático
        if (verificar == 3) {
            construirLista(*raiz, &cabeca);
            contagem = contarNos(raiz);
            *raiz = listaParaArvore(&cabeca, contagem);
            verificar = 0;
        }
    }

    liberarArvore(raiz);
    return 0;
}