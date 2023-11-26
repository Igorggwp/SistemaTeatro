void listarApresentacoes(ApresentacaoArvore raiz) {
    printf("Lista de Apresentações:\n");
    
    if (raiz != NULL) {
        listarApresentacoes(raiz->esquerda);

        printf("Nome: %s\n", raiz->nome);
        printf("Data: %d/%d\n", raiz->dia, raiz->mes);
        printf("Horário: %s\n", raiz->horario);
        printf("\n");
        
        listarApresentacoes(raiz->direita);
    } else {
        printf("A árvore está vazia.\n");
    }
}