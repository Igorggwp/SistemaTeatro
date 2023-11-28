listaPoltronas* criarlista(){
    listaPoltronas *inicio = (listaPoltronas*) malloc(sizeof(listaPoltronas));
    if (inicio != NULL){
        *inicio = NULL;
    }else{
        printf("Erro na alocaçãooo");
    }
    return inicio;
}

void exibelista(listaPoltronas* inicio){
    
    if (*inicio == NULL) {
        printf("Lista vazia\n");
    } else {
        poltronaNode *temp;
        temp = (*inicio);

        while (temp != NULL) {
            printf("%c\n", temp->apresentacao->status);
            temp = temp->prox;
        }
    }
}

int inserenofinal(listaPoltronas* inicio, Apresentacao nodeArv) {
    poltronaNode* novo = (poltronaNode*)malloc(sizeof(poltronaNode));
    if (novo == NULL) {
        printf("Erro na alocação\n");
        return 0;
    } else {
        if ((*inicio) == NULL) {
            *inicio = novo;
        } else {
            poltronaNode* temp;
            temp = (*inicio);
            while (temp->prox != NULL) {
                temp = temp->prox;
            }
            temp->prox = novo;
            novo->prox = NULL;
        }
        novo->apresentacao = nodeArv;
        return 1;
    }
}

int construirLista(Apresentacao nodeArv, listaPoltronas* list) {
    if (nodeArv == NULL) {
        return 1;
    }
    construirLista(nodeArv->esquerda, list);
    inserenofinal(list, nodeArv);
    construirLista(nodeArv->direita, list);
    return 0;
}

poltrona *criarNo(int numero, const char status) {
    poltrona *novoNo = (poltrona *)malloc(sizeof(poltrona));
    novoNo->numero = numero;
    novoNo->status = status;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

poltrona *listaParaArvore(listaPoltronas *head, int tamanho) {
    if (tamanho <= 0) {
        return NULL;
    }

    // Encontrar o meio da lista
    int meio = tamanho / 2;

    // Avançar até o meio da lista
    listaPoltronas *atual = head;
    for (int i = 0; i < meio; i++) {
        atual = &((*atual)->prox);
    }

    // Criar o nó correspondente ao meio
    poltrona *raiz = criarNo((*atual)->apresentacao->numero, (*atual)->apresentacao->status);

    // Recursivamente construir as subárvores
    raiz->esquerda = listaParaArvore(head, meio);
    raiz->direita = listaParaArvore(&((*atual)->prox), tamanho - meio - 1);

    return raiz;
}

void contador(poltrona *no_print, int*cont){
    if(no_print == NULL){
        return;
    }else{
        contador(no_print->esquerda, cont);
        contador(no_print->direita, cont);
        *cont += 1;
    }
}

int contarNos(Apresentacao * raiz){
    if(raiz == NULL){
        return 0;
    }else{
        int cont = 0;
        contador(*raiz, &cont);
        return cont;
    }
}