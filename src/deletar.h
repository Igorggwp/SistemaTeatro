Arvore encontrarMenorNo(Arvore raiz);

void deletar(Arvore *raiz) {
    if (*raiz == NULL) {
        printf("Árvore vazia. Nenhuma poltrona para deletar.\n");
        return;
    }

    printf("Digite o número da poltrona para excluir: ");
    int numero;
    if (scanf("%d", &numero) != 1) {
        printf("Entrada inválida para o número da poltrona.\n");
        return;
    }

    int comparacaoNumero = numero - (*raiz)->numero;

    if (comparacaoNumero < 0) {
        deletar(&(*raiz)->esquerda);
    } else if (comparacaoNumero > 0) {
        deletar(&(*raiz)->direita);
    } else {
        Arvore temp = encontrarMenorNo((*raiz)->direita);

        if ((*raiz)->esquerda == NULL) {
            *raiz = temp->direita;
        } else if ((*raiz)->direita == NULL) {
            *raiz = temp->esquerda;
        } else {
            (*raiz)->numero = temp->numero;
            (*raiz)->status = temp->status;

            deletar(&(*raiz)->direita);
        }

        free(temp);
        printf("Poltrona deletada com sucesso!\n");
    }
}

Arvore encontrarMenorNo(Arvore raiz) {
    if (raiz == NULL) {
        printf("Erro.\n");
        return NULL;
    }

    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}
