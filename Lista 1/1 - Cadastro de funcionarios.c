#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float salario;
} Funcionario;

void cadastrarFuncionario(Funcionario *f) {
    printf("Digite o nome do funcionario: ");
    fgets(f->nome, sizeof(f->nome), stdin);

    printf("Digite a idade do funcionario: ");
    scanf("%d", &f->idade);

    printf("Digite o salario do funcionario: ");
    scanf("%f", &f->salario);
}

void exibirFuncionario(Funcionario f) {
    printf("\nInformacoes do Funcionario:\n");
    printf("Nome: %s", f.nome);
    printf("Idade: %d\n", f.idade);
    printf("Salario: %.2f\n", f.salario);
}

int main() {
    Funcionario f;

    cadastrarFuncionario(&f);

    while ((getchar()) != '\n');

    exibirFuncionario(f);

    return 0;
}
