#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 100
#define MAX_USUARIOS 100
#define TAM_NOME 50
#define TAM_TITULO 100


typedef struct {
    char titulo[TAM_TITULO];
    char autor[TAM_NOME];
    int ano;
} Livro;

typedef struct {
    char nome[TAM_NOME];
    int id;
} Usuario;

typedef struct {
    Livro livros[MAX_LIVROS];
    Usuario usuarios[MAX_USUARIOS];
    int totalLivros;
    int totalUsuarios;
} Biblioteca;

void adicionarLivro(Biblioteca *biblioteca);
void adicionarUsuario(Biblioteca *biblioteca);
void listarLivros(Biblioteca *biblioteca);
void listarUsuarios(Biblioteca *biblioteca);
int buscarLivro(Biblioteca *biblioteca, char *titulo, int indice);

int main() {
    Biblioteca biblioteca = {0};
    int opcao;
    char tituloBusca[TAM_TITULO];

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Livro\n");
        printf("2. Adicionar Usuario\n");
        printf("3. Listar Livros\n");
        printf("4. Listar Usuarios\n");
        printf("5. Buscar Livro \n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                adicionarLivro(&biblioteca);
                break;
            case 2:
                adicionarUsuario(&biblioteca);
                break;
            case 3:
                listarLivros(&biblioteca);
                break;
            case 4:
                listarUsuarios(&biblioteca);
                break;
            case 5:
                printf("Digite o titulo do livro a buscar: ");
                fgets(tituloBusca, TAM_TITULO, stdin);
                tituloBusca[strcspn(tituloBusca, "\n")] = '\0';
                if (buscarLivro(&biblioteca, tituloBusca, 0) == -1) {
                    printf("Livro nao encontrado.\n");
                }
                break;
            case 6:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 6);

    return 0;
}

void adicionarLivro(Biblioteca *biblioteca) {
    if (biblioteca->totalLivros >= MAX_LIVROS) {
        printf("Capacidade maxima de livros atingida.\n");
        return;
    }
    Livro novoLivro;
    printf("Digite o titulo do livro: ");
    fgets(novoLivro.titulo, TAM_TITULO, stdin);
    novoLivro.titulo[strcspn(novoLivro.titulo, "\n")] = '\0';
    printf("Digite o autor do livro: ");
    fgets(novoLivro.autor, TAM_NOME, stdin);
    novoLivro.autor[strcspn(novoLivro.autor, "\n")] = '\0';
    printf("Digite o ano de publicacao: ");
    scanf("%d", &novoLivro.ano);
    getchar();
    biblioteca->livros[biblioteca->totalLivros++] = novoLivro;
    printf("Livro adicionado com sucesso!\n");
}

void adicionarUsuario(Biblioteca *biblioteca) {
    if (biblioteca->totalUsuarios >= MAX_USUARIOS) {
        printf("Capacidade maxima de usuarios atingida.\n");
        return;
    }
    Usuario novoUsuario;
    printf("Digite o nome do usuario: ");
    fgets(novoUsuario.nome, TAM_NOME, stdin);
    novoUsuario.nome[strcspn(novoUsuario.nome, "\n")] = '\0';
    novoUsuario.id = biblioteca->totalUsuarios + 1;
    biblioteca->usuarios[biblioteca->totalUsuarios++] = novoUsuario;
    printf("Usuario adicionado com sucesso! ID: %d\n", novoUsuario.id);
}

void listarLivros(Biblioteca *biblioteca) {
    if (biblioteca->totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    printf("\nLista de Livros:\n");
    for (int i = 0; i < biblioteca->totalLivros; i++) {
        printf("Titulo: %s, Autor: %s, Ano: %d\n",
               biblioteca->livros[i].titulo,
               biblioteca->livros[i].autor,
               biblioteca->livros[i].ano);
    }
}

void listarUsuarios(Biblioteca *biblioteca) {
    if (biblioteca->totalUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }
    printf("\nLista de Usuarios:\n");
    for (int i = 0; i < biblioteca->totalUsuarios; i++) {
        printf("ID: %d, Nome: %s\n",
               biblioteca->usuarios[i].id,
               biblioteca->usuarios[i].nome);
    }
}

int buscarLivro(Biblioteca *biblioteca, char *titulo, int indice) {
    if (indice >= biblioteca->totalLivros) {
        return -1;
    }
    if (strcmp(biblioteca->livros[indice].titulo, titulo) == 0) {
        printf("Livro encontrado: Titulo: %s, Autor: %s, Ano: %d\n",
               biblioteca->livros[indice].titulo,
               biblioteca->livros[indice].autor,
               biblioteca->livros[indice].ano);
        return indice;
    }
    return buscarLivro(biblioteca, titulo, indice + 1);
}
