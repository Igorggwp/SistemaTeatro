// Função para criar a lista encadeada inicial
listaPoltronas criarlista() {
    // Aloca espaço para o primeiro nó da lista
    listaPoltronas inicio = (listaPoltronas)malloc(sizeof(poltronaNode));
    if (inicio != NULL) {
        inicio->prox = NULL; 
    } else {
        printf("Erro na alocação\n");
    }
    return inicio;
}

// Função para inserir na lista encadeada
int inserir(listaPoltronas *inicio, Apresentacao nodeArv) {
    // Aloca espaço para um novo nó da lista
    poltronaNode *novo = (poltronaNode *)malloc(sizeof(poltronaNode));
    if (novo == NULL) {
        printf("Erro na alocação\n");
        return 0;
    }

    novo->apresentacao = nodeArv;  // Armazena o ponteiro para a apresentação no novo nó
    novo->prox = NULL; 

    // Verifica se a lista está vazia ou se o novo nó deve ser o primeiro
    if (*inicio == NULL || (*inicio)->apresentacao->numero > nodeArv->numero) {
        novo->prox = *inicio;  // Adiciona o novo nó no início da lista
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

    // Constrói a lista encadeada recursivamente
    construirLista(nodeArv->esquerda, list);
    inserir(list, nodeArv);  // Insere o nó atual na lista
    construirLista(nodeArv->direita, list);

    return 0;
}

// Função para converter a lista encadeada em uma árvore binária de busca
poltrona *listaArvore(listaPoltronas *head, int tamanho) {

    if (tamanho <= 0 || *head == NULL) {
        return NULL;
    }

    poltronaNode *atualNode = *head;
    // Cria o nó raiz da árvore a partir do primeiro nó da lista
    poltrona *raiz = criarNo(atualNode->apresentacao->numero, atualNode->apresentacao->status);

    *head = atualNode->prox;  // Atualiza para a cabeça da lista

    // Constrói a subárvore direita
    raiz->direita = listaArvore(head, tamanho - 1);

    return raiz;
}

// Função para contar o número de nós na árvore
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

// Função para contar o número de nós a partir da raiz
int contarNos(Apresentacao *raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        int contagem = 0;
        numeroNo(*raiz, &contagem);  // Função de contagem recursiva
        return contagem;
    }
}
