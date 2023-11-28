/* Função para Cadastrar Poltronas */

int cadastrar(Apresentacao *raiz) {
    poltrona *novo = (poltrona *)malloc(sizeof(poltrona));

    if (novo == NULL) {
        printf("O valor é nulo");
        return 0;
    } else {
        novo->esquerda = NULL;
        novo->direita = NULL;

        printf("Informe o numero da Poltrona: ");
        scanf("%d", &(novo->numero));

        printf("Informe o status da Poltrona: ");
        scanf(" %c", &(novo->status));

        if (*raiz == NULL) {
            *raiz = novo;
            system("cls");
            printf("Poltrona cadastrada com sucesso!\n");
            printf("Número: %d | Status: %c\n", novo->numero, novo->status);
            return 1;
        } else {
            poltrona *atual = *raiz;
            poltrona *ant = NULL;

            while (atual != NULL) {
                ant = atual;
                if (atual->numero == novo->numero) {
                    printf("Essa Poltrona já foi cadastrada anteriormente.\n");
                    free(novo);
                    return 0;
                }
                if (novo->numero > atual->numero) {
                    atual = atual->direita;
                } else {
                    atual = atual->esquerda;
                }
            }

            if (novo->numero > ant->numero) {
                ant->direita = novo;
            } else {
                ant->esquerda = novo;
            }
            return 1;
        }
    }
}