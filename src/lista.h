Apresentacao cadastrarApresentacao(Lista *lista) {
    Apresentacao novaApresentacao;

    printf("Digite o nome da apresentacao: ");
    scanf("%19s", novaApresentacao.nome);
    printf("Digite o dia, mes e horario (DD MM HH:MM): ");
    scanf("%d %d %6s", &novaApresentacao.dia, &novaApresentacao.mes, novaApresentacao.horario);

    novaApresentacao.poltronas = NULL;
    novaApresentacao.proxima = NULL;

    NoApresentacao *novoNo = (NoApresentacao *)malloc(sizeof(NoApresentacao));
    if (novoNo != NULL) {
        strcpy(novoNo->apresentacao.nome, novaApresentacao.nome);
        novoNo->apresentacao.dia = novaApresentacao.dia;
        novoNo->apresentacao.mes = novaApresentacao.mes;
        strcpy(novoNo->apresentacao.horario, novaApresentacao.horario);
        novoNo->apresentacao.poltronas = NULL;
        novoNo->proxima = *lista;
        *lista = novoNo;

        printf("Apresentacao cadastrada com sucesso!\n");
    } else {
        printf("Erro na alocação de memória.\n");
    }

    return novaApresentacao;
}

void listarApresentacoes(Lista lista) {
    if (lista == NULL) {
        printf("Lista de apresentacoes vazia.\n");
        return;
    }

    NoApresentacao *atual = lista;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->apresentacao.nome);
        printf("Data e Horario: %d/%d %s\n", atual->apresentacao.dia, atual->apresentacao.mes, atual->apresentacao.horario);
        printf("----------------------------\n");
        atual = atual->proxima;
    }
}