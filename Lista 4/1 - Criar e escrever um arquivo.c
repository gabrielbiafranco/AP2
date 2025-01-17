#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;

    arquivo = fopen("saida.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }

    fprintf(arquivo, "Este e um exemplo de texto.\n");
    fprintf(arquivo, "Este e outro exemplo.\n");
    fprintf(arquivo, "Ultimo exemplo de texto.\n");

    fclose(arquivo);

    printf("Arquivo criado e linhas escritas com sucesso!\n");
    return 0;
}
