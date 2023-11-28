/* Funções para Atualizar status da poltrona */

poltrona *busca(poltrona *raiz, int numero) {
    if (raiz == NULL || raiz->numero == numero) {
        return raiz;
    }

    poltrona *esquerda = busca(raiz->esquerda, numero);
    if (esquerda != NULL) {
        return esquerda;
    }

    return busca(raiz->direita, numero);
}

void atualizar(poltrona *no_print) {
    if (no_print == NULL) {
        return;
    }

    int numero;
    char status;

    printf("Informe o numero da poltrona que deseja atualizar: ");
    scanf("%d", &numero);

    poltrona *alvo = busca(no_print, numero);

    if (alvo != NULL) {
        printf("Informe o novo status para a poltrona %d: ", numero);
        scanf(" %c", &status);

        alvo->status = status;

        printf("Atualização: Número: %d | Novo Status: %c\n", numero, status);
    } else {
        printf("Poltrona com número %d não encontrada.\n", numero);
    }
}