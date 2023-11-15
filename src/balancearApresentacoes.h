int altura(Apresentacao no) {
    if (no == NULL) 
        return 0;
    int alturaEsquerda = altura(no->esquerda);
    int alturaDireita = altura(no->direita);
    return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
}
int fator(Apresentacao no) {
    if (no == NULL)
        return 0;
    return altura(no->esquerda) - altura(no->direita);
}
Apresentacao rotacaoDireita(Apresentacao y) {
    Apresentacao x = y->esquerda;
    Apresentacao T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    return x;
}

Apresentacao rotacaoEsquerda(Apresentacao x) {
    Apresentacao y = x->direita;
    Apresentacao T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    return y;
}

Apresentacao balancearApresentacoes(Apresentacao raiz) {
    if (raiz == NULL)
        return raiz;

    int balanco = fator(raiz);

    if (balanco > 1) {
        if (fator(raiz->esquerda) < 0) {
            raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        }
        return rotacaoDireita(raiz);
    }
    else if (balanco < -1) {
        if (fator(raiz->direita) > 0) {
            raiz->direita = rotacaoDireita(raiz->direita);
        }
        return rotacaoEsquerda(raiz);
    }
    return raiz;
}