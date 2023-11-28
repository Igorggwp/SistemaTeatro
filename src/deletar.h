// Função de Confirmação
int confirmar(int numero) {
    int confirma;
    printf("Número: %d\n", numero);
    printf("Tem certeza que deseja remover essa poltrona?\n[1] - SIM\n[2] - CANCELAR\n->");
    scanf("%i", &confirma);
    return confirma;
}

// Função para remover folha
void folha(poltrona *no, poltrona *ant) {
    if (ant->numero > no->numero) {
        ant->esquerda = NULL;
    } else {
        ant->direita = NULL;
    }
    free(no);
}

// Função para remover nó com um filho
void filho(poltrona *no, poltrona *ant) {
    if (ant->numero > no->numero) {
        ant->esquerda = (no->direita != NULL) ? no->direita : no->esquerda;
    } else {
        ant->direita = (no->direita != NULL) ? no->direita : no->esquerda;
    }
    free(no);
}

// Função para remover nó interno
void interno(poltrona *no, poltrona *ant) {
    poltrona *atual2 = no->esquerda;
    poltrona *anterior2 = no->esquerda;

    while (atual2->direita != NULL) {
        anterior2 = atual2;
        atual2 = atual2->direita;
    }

    anterior2->direita = NULL;
    atual2->direita = no->direita;

    if (atual2 == no->esquerda) {
        atual2->esquerda = NULL;
    } else {
        atual2->esquerda = no->esquerda;
    }

    if (ant->numero > no->numero) {
        ant->esquerda = atual2;
    } else {
        ant->direita = atual2;
    }
    free(no);
}

// Função para encontrar e remover nó
void acharNo(poltrona *no, int numero, poltrona *ant) {
    int confirma = 0;
    if(no == NULL) {
        return;
    } else {
        acharNo(no->esquerda, numero, no);
        acharNo(no->direita, numero, no);
        if(no->numero == numero ){
            confirma = confirmar(no->numero);
            if (confirma == 1){
                if(no->esquerda == NULL && no->direita == NULL){
                    folha(no, ant);
                } else if((no->esquerda == NULL && no->direita != NULL) || (no->esquerda != NULL && no->direita == NULL)){
                    filho(no, ant);
                } else {
                    interno(no, ant);
                }
                printf("Elemento removido!\n");
            } else {
                printf("Operacao cancelada\n");
            }
        }
    }
}

// Função para remover folha na raiz
void folhaRaiz(poltrona **raiz) {
    free(*raiz);
    *raiz = NULL;
}

// Função para remover nó com um filho na raiz
void filhoRaiz(poltrona **raiz) {
    poltrona *temp = ((*raiz)->esquerda != NULL) ? (*raiz)->esquerda : (*raiz)->direita;
    free(*raiz);
    *raiz = temp;
}

// Função para remover nó interno na raiz
void internoRaiz(poltrona **raiz) {
    poltrona *atual2 = (*raiz)->esquerda;
    poltrona *anterior2 = (*raiz)->esquerda;

    while (atual2->direita != NULL) {
        anterior2 = atual2;
        atual2 = atual2->direita;
    }

    anterior2->direita = NULL;
    atual2->direita = (*raiz)->direita;

    if (atual2 == (*raiz)->esquerda) {
        atual2->esquerda = NULL;
    } else {
        atual2->esquerda = (*raiz)->esquerda;
    }

    free(*raiz);
    *raiz = atual2;
}

// Função principal para deletar nó
int deletar(poltrona **raiz) {
    int numero, confirma;

    printf("Informe o número: ");
    scanf("%d", &numero);

    if (*raiz == NULL) {
        printf("A árvore está vazia.\n");
        return 0;
    }

    // Verifica se a poltrona existe
    poltrona *no = *raiz;
    while (no != NULL) {
        if (no->numero == numero) {
            break;
        } else if (numero < no->numero) {
            no = no->esquerda;
        } else {
            no = no->direita;
        }
    }

    if (no == NULL) {
        printf("A poltrona com o número %d não existe na árvore.\n", numero);
        return 0;
    }

    if (no == *raiz) {
        confirma = confirmar(no->numero);
        if (confirma == 1) {
            if (no->esquerda == NULL && no->direita == NULL) {
                folhaRaiz(raiz);
            } else if ((no->esquerda == NULL && no->direita != NULL) ||
                       (no->esquerda != NULL && no->direita == NULL)) {
                filhoRaiz(raiz);
            } else {
                internoRaiz(raiz);
            }
            printf("Elemento removido!\n");
            return 1;
        } else {
            printf("Remoção cancelada.\n");
            return 0;
        }
    } else {
        // O nó não é a raiz, chama a função acharNo
        acharNo(*raiz, numero, *raiz);
    }
    return 0;
}