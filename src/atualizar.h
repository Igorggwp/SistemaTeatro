/* Função para Atualizar status da poltrona */

void atualizar(no *no_print, int numero, char status, no *ant) {
    if (no_print == NULL) {
        return;
    } else {
        atualizar(no_print->esquerda, numero, status, ant);
        atualizar(no_print->direita, numero, status, ant);
        if (no_print->numero == numero) {
            no_print->status = status;
        }
    }
}