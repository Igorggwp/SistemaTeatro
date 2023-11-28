void listagem(Apresentacao no) {
    if (no != NULL) {
        listagem(no->esquerda);
        printf("Número: %d | Status: %c\n", no->numero, no->status);
        listagem(no->direita);
    }
}

void listar(Apresentacao raiz) {
    if (raiz != NULL) {
        printf("Lista de Poltronas:\n");
        listagem(raiz);
    } else {
        printf("A árvore está vazia.\n");
    }
}