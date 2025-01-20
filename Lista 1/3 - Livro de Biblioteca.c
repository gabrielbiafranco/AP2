#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Biblioteca {
    char titulo[50];
    char autor[50];
    int anoPublicacao;
};

int main() {
    struct Biblioteca biblioteca;
    int opcao;
    int dadosPreenchidos = 0; 

    do {
        printf("\n--- Menu Biblioteca ---\n");
        printf("1. Adicionar livro\n");
        printf("2. Exibir livro\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                printf("\nDigite um titulo: ");
                fgets(biblioteca.titulo, 50, stdin);
                biblioteca.titulo[strcspn(biblioteca.titulo, "\n")] = '\0';

                printf("Digite um autor: ");
                fgets(biblioteca.autor, 50, stdin);
                biblioteca.autor[strcspn(biblioteca.autor, "\n")] = '\0';

                printf("Digite o ano de publicacao: ");
                scanf("%d", &biblioteca.anoPublicacao);
                getchar(); 

                dadosPreenchidos = 1; 
                printf("\nLivro adicionado com sucesso!\n");
                break;

            case 2:
                if (dadosPreenchidos) {
                    printf("\n--- Informacoes do Livro ---\n");
                    printf("Titulo: %s\n", biblioteca.titulo);
                    printf("Autor: %s\n", biblioteca.autor);
                    printf("Ano de Publicacao: %d\n", biblioteca.anoPublicacao);
                } else {
                    printf("\nNenhum livro foi adicionado ainda.\n");
                }
                break;

            case 3:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
