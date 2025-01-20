#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int matricula;
    float nota1;
    float nota2;
} Aluno;

float calcularMedia(Aluno aluno) {
    return (aluno.nota1 + aluno.nota2) / 2;
}

int main() {
    Aluno aluno;

    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, 50, stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0';

    printf("Digite o numero de matricula do aluno: ");
    scanf("%d", &aluno.matricula);

    printf("Digite a primeira nota: ");
    scanf("%f", &aluno.nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &aluno.nota2);

    float media = calcularMedia(aluno);
    printf("\nAluno: %s\n", aluno.nome);
    printf("Matricula: %d\n", aluno.matricula);
    printf("Nota 1: %.2f\n", aluno.nota1);
    printf("Nota 2: %.2f\n", aluno.nota2);
    printf("Media: %.2f\n", media);

    return 0;
}
