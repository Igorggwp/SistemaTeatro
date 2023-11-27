Arvore buscar(Arvore raiz, int numero) {
    if (raiz == NULL) {
        return NULL;
    }

    if (numero < raiz->numero) {
        return buscar(raiz->esquerda, numero);
    } else if (numero > raiz->numero) {
        return buscar(raiz->direita, numero);
    } else {
        return raiz;
    }
}

void atualizar(Arvore* raiz) {
    int numero;

    printf("Digite o número da poltrona para atualizar: ");
    scanf("%d", &numero);

    Arvore poltrona = buscar(*raiz, numero);

    if (poltrona != NULL) {
        printf("poltrona encontrada!\n");

        printf("Número atual: %d\n", poltrona->numero);

        printf("Digite o status correto da poltrona: ");
        scanf("%c", &poltrona->status);

        *raiz = balancear(*raiz, NULL);

        printf("Poltrona atualizada com sucesso!\n");
    } else {
        printf("Poltrona nao encontrada.\n");
    }
}