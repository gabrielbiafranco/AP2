#include <stdio.h>
#include <stdlib.h>


int somaArray(int *array, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += *(array + i);
    }
    return soma;
}

int main() {
    int n;

    printf("Digite o tamanho do array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Entrada invalida! Por favor, insira um numero inteiro positivo.\n");
        return 1;
    }

    int array[n];

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        while (scanf("%d", &array[i]) != 1) {
            printf("Entrada invalida! Por favor, insira um numero inteiro.\n");
            while (getchar() != '\n');
            printf("Elemento %d: ", i + 1);
        }
    }

    int resultado = somaArray(array, n);

    printf("A soma dos elementos do array e: %d\n", resultado);

    return 0;
}
