// lista encadeada inicial
listaPoltronas criarlista() {
    // primeiro nó da lista
    listaPoltronas inicio = (listaPoltronas)malloc(sizeof(poltronaNode));
    if (inicio != NULL) {
        inicio->prox = NULL; 
    } else {
        printf("Erro na alocação\n");
    }
    return inicio;
}

// inserir na lista encadeada
int inserir(listaPoltronas *inicio, Apresentacao nodeArv) {
    // espaço para um novo nó
    poltronaNode *novo = (poltronaNode *)malloc(sizeof(poltronaNode));
    if (novo == NULL) {
        printf("Erro na alocação\n");
        return 0;
    }

    novo->apresentacao = nodeArv;  // Armazena no novo nó
    novo->prox = NULL; 

    // vazia ou primeiro
    if (*inicio == NULL || (*inicio)->apresentacao->numero > nodeArv->numero) {
        novo->prox = *inicio;  // novo nó no início 
        *inicio = novo;
    } else {
        // Encontra a posição correta 
        poltronaNode *temp = *inicio;
        while (temp->prox != NULL && temp->prox->apresentacao->numero < nodeArv->numero) {
            temp = temp->prox;
        }

        novo->prox = temp->prox;  // Adiciona o novo nó na posição correta
        temp->prox = novo;
    }

    return 1; 
}

// Função para criar um novo nó da árvore
poltrona *criarNo(int numero, char status) {
    // Novo nó da árvore
    poltrona *novoNo = (poltrona *)malloc(sizeof(poltrona));
    novoNo->numero = numero;
    novoNo->status = status;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para construir a lista encadeada a partir da árvore
int construirLista(Apresentacao nodeArv, listaPoltronas *list) {

    if (nodeArv == NULL) {
        return 1;
    }

    // Constrói a lista encadeada
    construirLista(nodeArv->esquerda, list);
    inserir(list, nodeArv);  // Insere o nó atual na lista
    construirLista(nodeArv->direita, list);

    return 0;
}   

// Função para converter a lista encadeada em uma árvore binária de busca balanceada
poltrona *listaArvoreBalanceada(listaPoltronas *head, int tamanho) {

    if (tamanho <= 0 || *head == NULL) {
        return NULL;
    }

    // Encontra o nó do meio da lista
    int meio = tamanho / 2;
    poltronaNode *meioNode = *head;
    for (int i = 0; i < meio; i++) {
        meioNode = meioNode->prox;
    }

    // raiz da árvore
    poltrona *raiz = criarNo(meioNode->apresentacao->numero, meioNode->apresentacao->status);

    // subárvore esquerda
    raiz->esquerda = listaArvoreBalanceada(head, meio);

    // Atualiza para o próximo nó após o nó do meio
    *head = meioNode->prox;

    // subárvore direita
    raiz->direita = listaArvoreBalanceada(head, tamanho - meio - 1);

    return raiz;
}


// contar o número de nós na árvore
void numeroNo(poltrona *no, int *contagem) {

    if (no == NULL) {
        return;
    } else {
        // Conta o nó atual e subárvores
        numeroNo(no->esquerda, contagem);
        numeroNo(no->direita, contagem);
        *contagem += 1;
    }
}

//  contar o número de nós
int contarNos(Apresentacao *raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        int contagem = 0;
        numeroNo(*raiz, &contagem);  // contagem
        return contagem;
    }
}
