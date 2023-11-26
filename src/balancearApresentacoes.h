int altura(ApresentacaoArvore no) {
    if (no == NULL) 
        return 0;
    int alturaEsquerda = altura(no->esquerda);
    int alturaDireita = altura(no->direita);
    return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
}

int fator(ApresentacaoArvore no) {
    if (no == NULL)
        return 0;
    return altura(no->esquerda) - altura(no->direita);
}

ApresentacaoArvore rotacaoDireita(ApresentacaoArvore y) {
    ApresentacaoArvore x = y->esquerda;
    ApresentacaoArvore T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    return x;
}

ApresentacaoArvore rotacaoEsquerda(ApresentacaoArvore x) {
    ApresentacaoArvore y = x->direita;
    ApresentacaoArvore T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    return y;
}

ApresentacaoArvore balancearApresentacoes(ApresentacaoArvore raiz, ApresentacaoArvore novoNo) {
    if (raiz == NULL)
        return novoNo;
        
    if (strcmp(novoNo->nome, raiz->nome) < 0)
        raiz->esquerda = balancearApresentacoes(raiz->esquerda, novoNo);
    else if (strcmp(novoNo->nome, raiz->nome) > 0)
        raiz->direita = balancearApresentacoes(raiz->direita, novoNo);
    else
        return raiz; 

    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);

    int fatorBal = alturaEsquerda - alturaDireita;

    // Rotação simples direita
    if (fatorBal > 1 && strcmp(novoNo->nome, raiz->esquerda->nome) < 0)
        return rotacaoDireita(raiz);

    // Rotação simples esquerda
    if (fatorBal < -1 && strcmp(novoNo->nome, raiz->direita->nome) > 0)
        return rotacaoEsquerda(raiz);

    // Rotação dupla direita
    if (fatorBal > 1 && strcmp(novoNo->nome, raiz->esquerda->nome) > 0) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    // Rotação dupla esquerda
    if (fatorBal < -1 && strcmp(novoNo->nome, raiz->direita->nome) < 0) {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}