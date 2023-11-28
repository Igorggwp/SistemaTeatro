void remover_folha(no *no_print, no *ant) {
    if (ant->numero > no_print->numero) {
        ant->esquerda = NULL;
    } else {
        ant->direita = NULL;
    }
    free(no_print);
}

void remover_umFilho(no *no_print, no *ant) {
    if (ant->numero > no_print->numero) {
        if (no_print->direita != NULL) {
            ant->esquerda = no_print->direita;
        } else {
            ant->esquerda = no_print->esquerda;
        }
    } else {
        if (no_print->direita != NULL) {
            ant->direita = no_print->direita;
        } else {
            ant->direita = no_print->esquerda;
        }
    }
    free(no_print);
}

void remover_interno(no *no_print, no *ant) {
    no *atual2 = no_print->esquerda;
    no *anterior2 = no_print->esquerda;

    while (atual2->direita != NULL) {
        anterior2 = atual2;
        atual2 = atual2->direita;
    }

    anterior2->direita = NULL;
    atual2->direita = no_print->direita;

    if (atual2 == no_print->esquerda) {
        atual2->esquerda = NULL;
    } else {
        atual2->esquerda = no_print->esquerda;
    }

    if (ant->numero > no_print->numero) {
        ant->esquerda = atual2;
    } else {
        ant->direita = atual2;
    }
    free(no_print);
}

void acha_no(no *no_print, int numero, no *ant) {
    int confirma = 0;
    if(no_print == NULL) {
        return;
    }else {
        acha_no(no_print->esquerda, numero, no_print);
        acha_no(no_print->direita, numero, no_print);
        if(no_print->numero == numero ){
            printf("Numero: %d - Status: %c\n", no_print->numero, no_print->status);
            printf("Tem certeza que deseja remover esse evento?\n[1]-SIM\n[2]-CANCELAR\n->");
            scanf("%i", &confirma);
            if (confirma == 1){
                if(no_print->esquerda == NULL && no_print->direita == NULL){
                    remover_folha(no_print, ant);
                    return;
                }else if((no_print->esquerda == NULL && no_print->direita != NULL) || (no_print->esquerda != NULL && no_print->direita == NULL)){
                    remover_umFilho(no_print, ant);
                    return;
                }else{
                    remover_interno(no_print, ant);
                    return;
                }
                system("clear");
                printf("Elemento removido!\n");
            }else{
                system("clear");
                printf("Operacao cancelada\n");
            }
        }
    }
}

void remover_folha_raiz(no **raiz) {
    free(*raiz);
    *raiz = NULL;
}

void remover_umFilho_raiz(no **raiz) {
    if ((*raiz)->esquerda != NULL) {
        no *temp = *raiz;
        *raiz = (*raiz)->esquerda;
        free(temp);
    } else {
        no *temp = *raiz;
        *raiz = (*raiz)->direita;
        free(temp);
    }
}

void remover_interno_raiz(no **raiz) {
    no *atual2 = (*raiz)->esquerda;
    no *anterior2 = (*raiz)->esquerda;

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

int remove_no(Evento *raiz, int numero) {
    int confirma;
    if (raiz == NULL){
        return 0;
    }else if((*raiz)->numero == numero ) {
        printf("Numero: %d - Status: %c\n", (*raiz)->numero, (*raiz)->status);
        printf("Tem certeza que deseja remover esse evento?\n[1]-SIM\n[2]-CANCELAR\n->");
        scanf("%i", &confirma);
        if (confirma == 1){
            if ((*raiz)->esquerda == NULL && (*raiz)->direita == NULL) {
                remover_folha_raiz(raiz);
            } else if (((*raiz)->esquerda == NULL && (*raiz)->direita != NULL) ||
                    ((*raiz)->esquerda != NULL && (*raiz)->direita == NULL)) {
                remover_umFilho_raiz(raiz);
            } else {
                remover_interno_raiz(raiz);
            }
            system("clear");
            printf("Elemento removido!\n");
            return 1;
        }else{
            system("clear");
            printf("Operação cancelada\n");
            return 0;  
        }
    }else{
        acha_no(*raiz, numero, *raiz);
    }
}