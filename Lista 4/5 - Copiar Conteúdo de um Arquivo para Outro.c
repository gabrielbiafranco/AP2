#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *entrada, *saida;
    char c;

    entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir entrada.txt!\n");
        return 1;     }

    saida = fopen("copia.txt", "w");
    if (saida == NULL) {
        printf("Erro ao criar copia.txt!\n");
        fclose(entrada);
        return 1;    }

    while ((c = fgetc(entrada)) != EOF) {
        fputc(c, saida);
    }

    fclose(entrada);
    fclose(saida);

    printf("Conteudo copiado para copia.txt com sucesso!\n");
    return 0;
}
