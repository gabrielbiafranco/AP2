#include <stdio.h>
#include <stdlib.h>


int contarCaracteres(const char *str) {
    int contador = 0;

    while (*str != '\0') {
        contador++;
        str++;
    }

    return contador;
}

int main() {
    char string[100];

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    char *p = string;
    while (*p != '\0') {
        if (*p == '\n') {
            *p = '\0';
            break;
        }
        p++;
    }

    int resultado = contarCaracteres(string);

    printf("A string \"%s\" contem %d caracteres.\n", string, resultado);

    return 0;
}
