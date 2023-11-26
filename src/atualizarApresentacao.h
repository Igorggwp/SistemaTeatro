ApresentacaoArvore buscarApresentacao(ApresentacaoArvore raiz, char nome[]) {
    if (raiz == NULL) {
        return NULL;
    }

    int comparacaoNome = strcmp(nome, raiz->nome);

    if (comparacaoNome < 0) {
        return buscarApresentacao(raiz->esquerda, nome);
    } else if (comparacaoNome > 0) {
        return buscarApresentacao(raiz->direita, nome);
    } else {
        return raiz;
    }
}

void atualizarApresentacao(ApresentacaoArvore* raiz) {
    char nome[20];

    printf("Digite o nome da apresentacao para atualizar: ");
    scanf("%s", nome);

    ApresentacaoArvore apresentacao = buscarApresentacao(*raiz, nome);

    if (apresentacao != NULL) {
        printf("Apresentacao encontrada!\n");

        printf("Nome atual: %s\n", apresentacao->nome);

        printf("Digite o novo nome da apresentacao: ");
        scanf("%s", apresentacao->nome);

        do {
            printf("Dia da apresentacao (1-31): ");
            scanf("%d", &apresentacao->dia);
        } while (apresentacao->dia < 1 || apresentacao->dia > 31);

        do {
            printf("Mes da apresentacao (1-12): ");
            scanf("%d", &apresentacao->mes);
        } while (apresentacao->mes < 1 || apresentacao->mes > 12);

        printf("Horario da apresentacao (hh:mm): ");
        scanf("%s", apresentacao->horario);

        *raiz = balancearApresentacoes(*raiz, NULL);

        printf("Apresentacao atualizada com sucesso!\n");
    } else {
        printf("Apresentacao nao encontrada.\n");
    }
}