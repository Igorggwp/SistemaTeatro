void listar(Arvore raiz) {
    static int frase = 0;

    if (raiz != NULL) {
        if (!frase) {
            printf("Lista de Poltronas:\n");
            frase = 1;
        }

        listar(raiz->esquerda);
        printf("Número: %d | Status: %c\n", raiz->numero, raiz->status);
        listar(raiz->direita);
    } else {
        if (!frase) {
            printf("A árvore está vazia.\n");
            frase = 1;
        }
    }
}
