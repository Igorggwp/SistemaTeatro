void listar(Arvore raiz) {
    printf("Lista de Poltronas:\n");
    if (raiz != NULL) {
        listar(raiz->esquerda);
        printf("Número: %d | Status: %c\n", raiz->numero, raiz->status);
        listar(raiz->direita);
    } else {
        printf("A árvore está vazia.\n");
    }
}