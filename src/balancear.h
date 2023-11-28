// Função para criar a lista encadeada inicial
listaPoltronas criarlista() {
    listaPoltronas inicio = (listaPoltronas)malloc(sizeof(poltronaNode));
    if (inicio != NULL) {
        inicio->prox = NULL;
    } else {
        printf("Erro na alocação\n");
    }
    return inicio;
}

// Função para inserir no final da lista encadeada
int inserirFinal(listaPoltronas *inicio, Apresentacao nodeArv) {
    poltronaNode *novo = (poltronaNode *)malloc(sizeof(poltronaNode));
    if (novo == NULL) {
        printf("Erro na alocação\n");
        return 0;
    } else {
        novo->apresentacao = nodeArv;
        novo->prox = NULL;

        if (*inicio == NULL) {
            *inicio = novo;
        } else {
            // Verificar se o elemento já está na lista
            poltronaNode *temp = *inicio;
            while (temp != NULL) {
                if (temp->apresentacao == nodeArv) {
                    free(novo);
                    return 0;
                }
                temp = temp->prox;
            }

            // Adicionar novo elemento ao final da lista
            temp = *inicio;
            while (temp->prox != NULL) {
                temp = temp->prox;
            }
            temp->prox = novo;
        }
        return 1;
    }
}

// Função para construir a lista encadeada a partir da árvore
int construirLista(Apresentacao nodeArv, listaPoltronas *list) {
    if (nodeArv == NULL) {
        return 1;
    }
    construirLista(nodeArv->esquerda, list);
    inserirFinal(list, nodeArv);
    construirLista(nodeArv->direita, list);
    return 0;
}

// Função para criar um novo nó da árvore
poltrona *criarNo(int numero, char status) {
    poltrona *novoNo = (poltrona *)malloc(sizeof(poltrona));
    novoNo->numero = numero;
    novoNo->status = status;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para exibir a lista encadeada
void exibelista(listaPoltronas *inicio) {
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

// Função para converter a lista encadeada em uma árvore binária de busca
poltrona *listaParaArvore(listaPoltronas *head, int tamanho) {
    if (tamanho <= 0 || *head == NULL) {
        return NULL;
    }

    poltronaNode *atualNode = *head;
    poltrona *raiz = criarNo(atualNode->apresentacao->numero, atualNode->apresentacao->status);

    // Avançar para o próximo elemento na lista
    *head = atualNode->prox;

    raiz->direita = listaParaArvore(head, tamanho - 1);

    return raiz;
}

// Função para contar o número de nós na árvore
void contador(poltrona *no, int *contagem) {
    if (no == NULL) {
        return;
    } else {
        contador(no->esquerda, contagem);
        contador(no->direita, contagem);
        *contagem += 1;
    }
}

// Função para contar o número de nós na árvore a partir da raiz
int contarNos(Apresentacao *raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        int contagem = 0;
        contador(*raiz, &contagem);
        return contagem;
    }
}