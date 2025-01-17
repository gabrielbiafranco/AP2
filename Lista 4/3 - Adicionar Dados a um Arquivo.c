#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;

    arquivo = fopen("saida.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;     }

    fprintf(arquivo, "Esta linha foi adicionada.\n");
    fprintf(arquivo, "Esta tambem.\n");

    fclose(arquivo);

    printf("Novas linhas adicionadas com sucesso!\n");
    return 0;
}
