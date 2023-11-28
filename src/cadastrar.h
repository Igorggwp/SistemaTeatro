/* Função para Cadastrar Poltronas */

int cadastrar(Evento *raiz, int numero, char status) {
    no *novo = (no *)malloc(sizeof(no));

    if (novo == NULL) {
        printf("O valor é nulo");
        return 0;
    } else {

        novo->esquerda = NULL;
        novo->direita = NULL;
        novo->numero = numero;
        novo->status = status;

        if (*raiz == NULL) {
            *raiz = novo;
            return 1;
        } else {
            no *atual = *raiz;
            no *ant = NULL;

            while (atual != NULL) {
                ant = atual;
                if (atual->numero == novo->numero) {
                    printf("Essa Poltrona já foi cadastrada.");
                    free(novo);
                    return 0;
                }
                if (novo->numero > atual->numero) {
                    atual = atual->direita;
                } else {
                    atual = atual->esquerda;
                }
            }

            if (novo->numero > ant->numero) {
                ant->direita = novo;
            } else {
                ant->esquerda = novo;
            }
            return 1;
        }
    }
}