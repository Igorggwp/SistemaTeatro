#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct No {
    int numero; 
    char status; // R = Reservado, L = Livre
    struct No *esquerda;
    struct No *direita;
};
typedef struct No no;
typedef struct No *Evento;

struct Node {
    Evento evento;
    struct Node *prox;
};
typedef struct Node node;
typedef node *lista;

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

Evento *criaArvore() {
    Evento *raiz = (Evento *)malloc(sizeof(Evento));
    if (raiz != NULL) {
        *raiz = NULL;
    }
    else {
        printf("Erro na alocacao");
        return 0;
    };
    return raiz;
}

void libera_no(no *no_liberar) {
    if (no_liberar == NULL) {
        return;
    }
    else {
        libera_no(no_liberar->esquerda);
        libera_no(no_liberar->direita);
        free(no_liberar);
    }
}

int libera_arvore(Evento *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    else {
        libera_no(*raiz);
    }
    free(raiz);
    return 1;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    lista *cabeca = criarlista();
    Evento *raiz = criaArvore();
    int esc, numero, cont_balanceamento = 0, cont = 0;
    char status;
    system("cls");

    while (1) {
        if (cont_balanceamento == 3) {
            printf("Realizando o balanceamento estático.\n");
            construirLista(*raiz, cabeca);
            cont = contar_nos(raiz);
            *raiz = listaParaArvore(cabeca, cont);
            cont_balanceamento = 0;
        }

        logo();
        printf("Selecione a opção desejada\n[1] - Cadastrar Poltrona\n[2] - Atualizar Poltrona\n[3] - Listar Poltronas\n[4] - Deletar Poltrona\n[0] - Voltar\n->");
        scanf("%d", &esc);

        switch (esc) {
        case 1:
            system("cls");
            printf("----------------------------------------\n");
            printf("|          Cadastrar Poltrona          |\n");
            printf("----------------------------------------\n");
            printf("Informe o numero: ");
            scanf("%d", &numero);
            printf("Informe o status: ");
            scanf(" %c", &status);
            if (cadastrar(raiz, numero, status)) {
                printf("Evento inserido com sucesso.\n");
                cont_balanceamento++;
            }
            break;
        case 2:
            system("cls");
            printf("----------------------------------------\n");
            printf("|          Atualizar Poltrona          |\n");
            printf("----------------------------------------\n");
            printf("Informe o numero: ");
            scanf("%d", &numero);
            printf("Informe o status: ");
            scanf(" %c", &status);
            atualizar(*raiz, numero, status, *raiz);
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
            printf("Informe o numero: ");
            scanf("%d", &numero);
            remove_no(raiz, numero);
            break;
        case 0:
            libera_arvore(raiz);
            exit(1);
        case 6:
            construirLista(*raiz, cabeca);
            exibelista(cabeca);
            cont = contar_nos(raiz);
            *raiz = listaParaArvore(cabeca, cont);
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    }
    libera_arvore(raiz);
    return 0;
}