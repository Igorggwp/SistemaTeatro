/* Função para criar a lista encadeada */

listaPoltronas criarlista() {
    listaPoltronas inicio = (listaPoltronas)malloc(sizeof(poltronaNode)); // Alocar memória para o primeiro nó
    if (inicio != NULL) {
        inicio->prox = NULL; // Inicia com a lista vazia
    } else {
        printf("Erro na alocação\n");
    }
    return inicio; // Ponteiro que aponta para o primeiro nó da lista
}

/* Função para inserir na lista encadeada */

int inserir(listaPoltronas *inicio, Apresentacao nodeArv) {
    poltronaNode *novo = (poltronaNode *)malloc(sizeof(poltronaNode));  // Alocação para um novo nó
    if (novo == NULL) {
        printf("Erro na alocação\n");
        return 0;
    }

    novo->apresentacao = nodeArv;
    novo->prox = NULL;

    if (*inicio == NULL || (*inicio)->apresentacao->numero > nodeArv->numero) { // Se for null ou menor - Insere no Início
        novo->prox = *inicio;
        *inicio = novo;
    } else {
        poltronaNode *temp = *inicio;
        while (temp->prox != NULL && temp->prox->apresentacao->numero < nodeArv->numero) { // Se não for no Início, percorre até encontrar o lugar certo
            temp = temp->prox;
        }

        novo->prox = temp->prox;
        temp->prox = novo;
    }

    return 1;
}

/* Função para criar um novo nó da árvore */

poltrona *criarNo(int numero, char status) { // Aloca memória para armazenar o nó
    poltrona *novoNo = (poltrona *)malloc(sizeof(poltrona));
    novoNo->numero = numero;
    novoNo->status = status;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

/* Função para construir a lista encadeada a partir da árvore */
int construirLista(Apresentacao nodeArv, listaPoltronas *list) {
    if (nodeArv == NULL) {
        return 1;
    }

    // É um In Ordem
    construirLista(nodeArv->esquerda, list); // Chamada recursiva para construir a lista a partir da esq
    inserir(list, nodeArv); // Insere o nó atual na lista encadeada
    construirLista(nodeArv->direita, list); // Chamada recursiva para construir a lista a partir da esq

    return 0;
}

/* Função para constrir uma árvore binária de busca a partir de uma lista encadeada */

poltrona *listaParaArvore(listaPoltronas *head, int tamanho) {
    if (tamanho <= 0 || *head == NULL) {
        return NULL;
    }

    poltronaNode *atualNode = *head; // Ter o nó atual
    poltrona *raiz = criarNo(atualNode->apresentacao->numero, atualNode->apresentacao->status); // Cria um nó na arvore pelo nó atual da lista

    *head = atualNode->prox; // Atualiza para apontar para o próximo

    raiz->direita = listaParaArvore(head, tamanho - 1); // Recursivo para usar todos os elementos e construir  a subárvore direita do nó atual

    return raiz;
}

/* Função para contar dentro o  número de nós na árvore */

void contador(poltrona *no, int *contagem) {
    if (no == NULL) {
        return;
    } else {
        contador(no->esquerda, contagem);
        contador(no->direita, contagem);
        *contagem += 1;
    }
}

/* Função para contar o número de nós na árvore a partir da raiz */

int contarNos(Apresentacao *raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        int contagem = 0;
        contador(*raiz, &contagem);
        return contagem;
    }
}