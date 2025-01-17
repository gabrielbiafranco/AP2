#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    char linha[256];

    arquivo = fopen("saida.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    printf("Conteudo de saida.txt:\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo);

    return 0;
}
