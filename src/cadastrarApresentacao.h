void cadastrarApresentacao(ApresentacaoArvore* raiz) {
    char nome[20];
    int dia, mes;
    char horario[5];

    printf("Nome da apresentacao: ");
    scanf("%s", nome);

    do {
        printf("Dia da apresentacao (1-31): ");
        scanf("%d", &dia);
    } while (dia < 1 || dia > 31);

    do {
        printf("Mes da apresentacao (1-12): ");
        scanf("%d", &mes);
    } while (mes < 1 || mes > 12);

    printf("Horario da apresentacao (hh:mm): ");
    scanf("%s", horario);

    ApresentacaoArvore novoNo = CriarNoApresentacao(nome, dia, mes, horario);
    
    *raiz = balancearApresentacoes(*raiz, novoNo);

    printf("Apresentacao cadastrada com sucesso!\n");
}