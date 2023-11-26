ApresentacaoArvore encontrarMenorNo(ApresentacaoArvore raiz);

void deletarApresentacao(ApresentacaoArvore* raiz, char nome[]) {
    printf("Digite o nome da apresentacao para excluir: ");
    scanf("%s", nome);

    if (*raiz == NULL) {
        printf("Apresentacao nao encontrada.\n");
        return;
    }

    int comparacaoNome = strcmp(nome, (*raiz)->nome);

    if (comparacaoNome < 0) {
        deletarApresentacao(&(*raiz)->esquerda, nome);
    } else if (comparacaoNome > 0) {
        deletarApresentacao(&(*raiz)->direita, nome);
    } else {
        ApresentacaoArvore temp = *raiz;

        if ((*raiz)->esquerda == NULL) {
            *raiz = (*raiz)->direita;
        } else if ((*raiz)->direita == NULL) {
            *raiz = (*raiz)->esquerda;
        } else {
            temp = encontrarMenorNo((*raiz)->direita);

            strcpy((*raiz)->nome, temp->nome);
            (*raiz)->dia = temp->dia;
            (*raiz)->mes = temp->mes;
            strcpy((*raiz)->horario, temp->horario);

            deletarApresentacao(&(*raiz)->direita, temp->nome);
        }

        free(temp);
        printf("Apresentacao deletada com sucesso!\n");
    }
}


ApresentacaoArvore encontrarMenorNo(ApresentacaoArvore raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}