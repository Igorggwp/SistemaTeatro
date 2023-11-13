#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <windows.h>

struct Seat {
    int seatNum;
    struct Seat *next;
};
typedef struct Seat seat;
typedef seat* SeatList;

struct Node {
    char name[20];  // Nome da Apresentacao
    int day; // Dia do evento
    char time[5]; // Horario do evento
    SeatList seats;
    struct Node *left;
    struct Node *right;
};
typedef struct Node node;
typedef struct Node *Presentation;

void logo() {
    printf("-----------------------------\n");
    printf("|       Teatro da Gama      |\n");
    printf("-----------------------------\n");
}

Presentation createNode(char name[], int day, char time[]) {
    Presentation newNode = (Presentation)malloc(sizeof(node)); // Aloca ponteiro newNode(raiz) da árvore
    if (newNode != NULL) {
        strcpy(newNode->name, name);
        newNode->day = day;
        strcpy(newNode->time, time);
        newNode->seats = NULL;
        newNode->left = NULL;
        newNode->right = NULL;
    } else {
        printf("Erro na alocação de memôria.\n");
    }
    return newNode;
}

#include "src/balanceSeat.h"
#include "src/deleteSeat.h"
#include "src/insertSeat.h"
#include "src/searchSeats.h"
#include "src/updateSeat.h"
#include "src/balancePresentation.h"
#include "src/deletePresentation.h"
#include "src/insertPresentation.h"
#include "src/searchPresentation.h"
#include "src/updatePresentation.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Presentation root = NULL;
    int alt = 0;
    int alt1 = 0;
    int day;
    char name[20];
    char time[5];

    do {
        system("cls");
        logo();
        printf("Seja bem vindo ao Teatro da Gama!\n\nSelecione a opção desejada\n[1] - Apresentações\n[2] - Poltronas\n[0] - Sair\n->");
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
                            insertPresentation();
                            break;
                        case 2:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|        Atualizar Apresentação        |\n");
                            printf("----------------------------------------\n");
                            updatePresentation();
                            break;
                        case 3:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|        Listar Apresentações        |\n");
                            printf("----------------------------------------\n");
                            searchPresentations();
                            break;
                        case 4:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|          Deletar Apresentação        |\n");
                            printf("----------------------------------------\n");
                            deletePresentation();
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
                    printf("Selecione a opção desejada\n[1] - Cadastrar Poltrona\n[2] - Atualizar Poltrona\n[3] - Listar Poltronas\n[4] - Deletar Poltrona\n[0] - Voltar\n->");
                    scanf("%d", &alt1);

                    switch (alt1) {
                        case 1:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|           Cadastrar Poltrona         |\n");
                            printf("----------------------------------------\n");
                            insertSeat();
                            break;
                        case 2:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|           Atualizar Poltrona         |\n");
                            printf("----------------------------------------\n");
                            updateSeat();
                            break;
                        case 3:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|           Listar Poltronas           |\n");
                            printf("----------------------------------------\n");
                            searchSeats();
                            break;
                        case 4:
                            system("cls");
                            printf("----------------------------------------\n");
                            printf("|            Deletar Poltrona          |\n");
                            printf("----------------------------------------\n");
                            deleteSeat();
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