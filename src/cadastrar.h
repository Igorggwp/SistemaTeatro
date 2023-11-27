void cadastrar(Arvore *raiz) {
    int numero;
    char status;

    printf("Número da Poltrona: ");
    scanf("%d", &numero);

    while (getchar() != '\n');

    printf("Status da Poltrona: ([R] = Reservado | [L] = Livre): ");
    scanf(" %c", &status);

    Arvore novoNo = CriarNo(numero, status);

    *raiz = balancear(*raiz, novoNo);

    printf("Poltrona cadastrada com sucesso!\n");
    printf("Número: %d | Status: %c\n", numero, status);
}