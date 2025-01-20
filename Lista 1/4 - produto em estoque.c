#include <stdio.h>
#include <string.h>
#include "produto.h"

#define MAX_PRODUTOS 50

int main() {
    Produto produtos[MAX_PRODUTOS];
    int totalProdutos = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar produto\n");
        printf("2. Exibir produtos cadastrados\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                if (totalProdutos < MAX_PRODUTOS) {
                    printf("\nCadastro de Produto\n");
                    printf("Nome do produto: ");
                    fgets(produtos[totalProdutos].nome, 50, stdin);
                    produtos[totalProdutos].nome[strcspn(produtos[totalProdutos].nome, "\n")] = 0; 
                    printf("Codigo do produto: ");
                    scanf("%d", &produtos[totalProdutos].codigo);
                    printf("Preco do produto: ");
                    scanf("%f", &produtos[totalProdutos].preco);
                    printf("Quantidade em estoque: ");
                    scanf("%d", &produtos[totalProdutos].quantidade);
                    totalProdutos++;
                    printf("Produto cadastrado com sucesso!\n");
                } else {
                    printf("Limite de produtos cadastrados atingido!\n");
                }
                break;

            case 2:
                if (totalProdutos > 0) {
                    printf("\nProdutos cadastrados:\n");
                    for (int i = 0; i < totalProdutos; i++) {
                        printf("\nProduto %d:\n", i + 1);
                        printf("Nome: %s\n", produtos[i].nome);
                        printf("Codigo: %d\n", produtos[i].codigo);
                        printf("Preco: R$ %.2f\n", produtos[i].preco);
                        printf("Quantidade em estoque: %d\n", produtos[i].quantidade);
                        printf("Valor total em estoque: R$ %.2f\n", produtos[i].preco * produtos[i].quantidade);
                    }
                } else {
                    printf("Nenhum produto cadastrado.\n");
                }
                break;

            case 3:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
