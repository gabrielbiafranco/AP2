#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[15];
    char email[50];
} Contato;

int main() {
    Contato contato;

    printf("Digite o nome do contato: ");
    fgets(contato.nome, 50, stdin);
    contato.nome[strcspn(contato.nome, "\n")] = '\0';

    printf("Digite o telefone do contato: ");
    fgets(contato.telefone, 15, stdin);
    contato.telefone[strcspn(contato.telefone, "\n")] = '\0';

    printf("Digite o email do contato: ");
    fgets(contato.email, 50, stdin);
    contato.email[strcspn(contato.email, "\n")] = '\0';

    printf("\nInformacoes do Contato:\n");
    printf("Nome: %s\n", contato.nome);
    printf("Telefone: %s\n", contato.telefone);
    printf("Email: %s\n", contato.email);

    return 0;
}
