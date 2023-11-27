int altura(Arvore no) {
    if (no == NULL) 
        return 0;
    int alturaEsquerda = altura(no->esquerda);
    int alturaDireita = altura(no->direita);
    return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
}

int fator(Arvore no) {
    if (no == NULL)
        return 0;
    return altura(no->esquerda) - altura(no->direita);
}

Arvore rotacaoDireita(Arvore y) {
    Arvore x = y->esquerda;
    Arvore T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    return x;
}

Arvore rotacaoEsquerda(Arvore x) {
    Arvore y = x->direita;
    Arvore T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    return y;
}

Arvore balancear(Arvore raiz, Arvore novoNo) {
    if (raiz == NULL)
        return novoNo;
        
    if (novoNo->numero < raiz->numero)
        raiz->esquerda = balancear(raiz->esquerda, novoNo);
    else if (novoNo->numero > raiz->numero)
        raiz->direita = balancear(raiz->direita, novoNo);
    else
        return raiz; 

    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);

    int fatorBal = alturaEsquerda - alturaDireita;

    // Rotação simples direita
    if (fatorBal > 1 && novoNo->numero < raiz->esquerda->numero)
        return rotacaoDireita(raiz);

    // Rotação simples esquerda
    if (fatorBal < -1 && novoNo->numero > raiz->direita->numero)
        return rotacaoEsquerda(raiz);

    // Rotação dupla direita
    if (fatorBal > 1 && novoNo->numero > raiz->esquerda->numero) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
    return rotacaoDireita(raiz);
    }

    return raiz;
}