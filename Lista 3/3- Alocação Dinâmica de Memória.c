#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *array;

    printf("Digite o tamanho do array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Entrada inv�lida! Por favor, insira um n�mero inteiro positivo.\n");
        return 1;
    }

    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Erro ao alocar mem�ria!\n");
        return 1;
    }

    printf("Digite os elementos do array:\n");
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        while (scanf("%d", &array[i]) != 1) {
            printf("Entrada inv�lida! Por favor, insira um n�mero inteiro.\n");
            while (getchar() != '\n');
            printf("Elemento %d: ", i + 1);
        }
    }

    printf("\nElementos do array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}
