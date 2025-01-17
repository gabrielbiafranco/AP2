#include <stdio.h>
#include <stdlib.h>


typedef struct {
    float x;
    float y;
} Ponto;

void atualizarPonto(Ponto *p, float novoX, float novoY) {
    if (p != NULL) {
        p->x = novoX;
        p->y = novoY;
    }
}

int main() {
    Ponto ponto;

    printf("Digite as coordenadas iniciais do ponto:\n");
    printf("x: ");
    scanf("%f", &ponto.x);
    printf("y: ");
    scanf("%f", &ponto.y);

   printf("\nCoordenadas antes da atualizacao: x = %.2f, y = %.2f\n", ponto.x, ponto.y);

    float novoX, novoY;
    printf("\nDigite as novas coordenadas do ponto:\n");
    printf("Novo x: ");
    scanf("%f", &novoX);
    printf("Novo y: ");
    scanf("%f", &novoY);

    atualizarPonto(&ponto, novoX, novoY);

    printf("\nCoordenadas apos a atualizacao: x = %.2f, y = %.2f\n", ponto.x, ponto.y);

    return 0;
}
