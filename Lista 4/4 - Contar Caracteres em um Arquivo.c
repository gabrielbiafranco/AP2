#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    char c;
    int contador = 0;

    arquivo = fopen("saida.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    while ((c = fgetc(arquivo)) != EOF) {
        contador++;
    }

    fclose(arquivo);

    printf("O arquivo saida.txt contem %d caracteres.\n", contador);
    return 0;
}
