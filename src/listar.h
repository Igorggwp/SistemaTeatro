void listar(Arvore raiz) {
    static int frase = 1;

    if (raiz != NULL) {
        if (frase) {
            printf("Lista de Poltronas:\n");
            frase = 0;
        }

        listar(raiz->esquerda);
        printf("Número: %d | Status: %c\n", raiz->numero, raiz->status);
        listar(raiz->direita);
    } else {
        if (frase) {
            printf("A árvore está vazia.\n");
        }
    }
}