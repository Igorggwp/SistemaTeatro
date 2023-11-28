lista* criarlista(){
    lista *inicio = (lista*) malloc(sizeof(lista));
    if (inicio != NULL){
        *inicio = NULL;
    }else{
        printf("Erro na alocaçãooo");
    }
    return inicio;
}

void exibelista(lista*inicio){
    
    if(*inicio == NULL){
        printf("Lista vazia");
    }else{
        node *temp;
        temp = (*inicio);

        while (temp != NULL){
            printf("%s\n", temp->evento->status);
            temp = temp->prox;
        }
    }
}

int inserenofinal(lista* inicio, Evento nodeArv) {
    node* novo = (node*)malloc(sizeof(node));
    if (novo == NULL) {
        printf("Erro na alocação\n");
        return 0;
    } else {
        if ((*inicio) == NULL) {
            *inicio = novo;
        } else {
            node* temp;
            temp = (*inicio);
            while (temp->prox != NULL) {
                temp = temp->prox;
            }
            temp->prox = novo;
            novo->prox = NULL;
        }
        novo->evento = nodeArv;
        return 1;
    }
}

int construirLista(Evento nodeArv, lista* list) {
    if (nodeArv == NULL) {
        return 1;
    }
    construirLista(nodeArv->esquerda, list);
    inserenofinal(list, nodeArv);
    construirLista(nodeArv->direita, list);
    
}

no *criarNo(int numero, const char *status) {
    no *novoNo = (no *)malloc(sizeof(no));
    novoNo->numero = numero;
    strcpy(novoNo->status, status);
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

no *listaParaArvore(lista *head, int tamanho) {
    if (tamanho <= 0) {
        return NULL;
    }

    // Encontrar o meio da lista
    int meio = tamanho / 2;

    // Avançar até o meio da lista
    lista *atual = head;
    for (int i = 0; i < meio; i++) {
        atual = &((*atual)->prox);
    }

    // Criar o nó correspondente ao meio
    no *raiz = criarNo((*atual)->evento->numero, (*atual)->evento->status);

    // Recursivamente construir as subárvores
    raiz->esquerda = listaParaArvore(head, meio);
    raiz->direita = listaParaArvore(&((*atual)->prox), tamanho - meio - 1);

    return raiz;
}

void contador(no *no_print, int*cont){
    if(no_print == NULL){
        return;
    }else{
        contador(no_print->esquerda, cont);
        contador(no_print->direita, cont);
        *cont += 1;
    }
}

int contar_nos(Evento * raiz){
    if(raiz == NULL){
        return 0;
    }else{
        int cont = 0;
        contador(*raiz, &cont);
        return cont;
    }
}