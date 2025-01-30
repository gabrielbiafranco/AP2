#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define FILE_NAME "inventario.txt"

typedef struct {
    char nome[MAX_NAME];
    int codigo;
    float preco;
    int quantidade;
} Produto;

typedef struct {
    Produto *produtos;
    int tamanho;
} Inventario;

void inicializarInventario(Inventario *inv) {
    inv->produtos = NULL;
    inv->tamanho = 0;
}

void adicionarProduto(Inventario *inv) {
    Produto novo;
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", novo.nome);
    printf("Digite o codigo do produto: ");
    scanf("%d", &novo.codigo);
    printf("Digite o preco do produto: ");
    scanf("%f", &novo.preco);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &novo.quantidade);

    inv->produtos = realloc(inv->produtos, (inv->tamanho + 1) * sizeof(Produto));
    if (inv->produtos == NULL) {
        printf("Erro ao alocar memoria!\n");
        return;
    }

    inv->produtos[inv->tamanho] = novo;
    inv->tamanho++;
    printf("Produto adicionado com sucesso!\n");
}

void listarProdutos(Inventario *inv) {
    if (inv->tamanho == 0) {
        printf("Nenhum produto no inventario.\n");
        return;
    }

    printf("Lista de produtos:\n");
    for (int i = 0; i < inv->tamanho; i++) {
        Produto p = inv->produtos[i];
        printf("Nome: %s | Codigo: %d | Preco: %.2f | Quantidade: %d\n",
               p.nome, p.codigo, p.preco, p.quantidade);
    }
}

void buscarProduto(Inventario *inv, int codigo) {
    for (int i = 0; i < inv->tamanho; i++) {
        if (inv->produtos[i].codigo == codigo) {
            Produto p = inv->produtos[i];
            printf("Produto encontrado: Nome: %s | Codigo: %d | Preco: %.2f | Quantidade: %d\n",
                   p.nome, p.codigo, p.preco, p.quantidade);
            return;
        }
    }
    printf("Produto com codigo %d nao encontrado.\n", codigo);
}

void salvarEmArquivo(Inventario *inv) {
    FILE *arquivo = fopen(FILE_NAME, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para escrita.\n");
        return;
    }

    fprintf(arquivo, "%d\n", inv->tamanho);
    for (int i = 0; i < inv->tamanho; i++) {
        Produto p = inv->produtos[i];
        fprintf(arquivo, "%s\n%d\n%.2f\n%d\n", p.nome, p.codigo, p.preco, p.quantidade);
    }

    fclose(arquivo);
    printf("Inventario salvo com sucesso em '%s'.\n", FILE_NAME);
}

void carregarDeArquivo(Inventario *inv) {
    FILE *arquivo = fopen(FILE_NAME, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para leitura.\n");
        return;
    }

    fscanf(arquivo, "%d", &inv->tamanho);
    inv->produtos = realloc(inv->produtos, inv->tamanho * sizeof(Produto));
    if (inv->produtos == NULL) {
        printf("Erro ao alocar memoria para carregar produtos.\n");
        fclose(arquivo);
        return;
    }

    for (int i = 0; i < inv->tamanho; i++) {
        Produto *p = &inv->produtos[i];
        fscanf(arquivo, " %[^\n]", p->nome);
        fscanf(arquivo, "%d", &p->codigo);
        fscanf(arquivo, "%f", &p->preco);
        fscanf(arquivo, "%d", &p->quantidade);
    }

    fclose(arquivo);
    printf("Inventrio carregado com sucesso de '%s'.\n", FILE_NAME);
}

void liberarMemoria(Inventario *inv) {
    free(inv->produtos);
}

int main() {
    Inventario inventario;
    inicializarInventario(&inventario);

    int opcao, codigo;

    do {
        printf("\nMenu de opcoes:\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Buscar Produto\n");
        printf("4. Salvar em Arquivo\n");
        printf("5. Carregar de Arquivo\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(&inventario);
                break;
            case 2:
                listarProdutos(&inventario);
                break;
            case 3:
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigo);
                buscarProduto(&inventario, codigo);
                break;
            case 4:
                salvarEmArquivo(&inventario);
                break;
            case 5:
                carregarDeArquivo(&inventario);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    liberarMemoria(&inventario);
    return 0;
}
