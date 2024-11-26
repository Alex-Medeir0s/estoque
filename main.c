#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 5


typedef struct {
    char nome[50];
    int quantidade;
    float preco;
} Produto;


Produto estoque[MAX_PRODUTOS];
int totalProdutos = 0;


void exibirMenu();
void adicionarProduto();
void consultarEstoque();
void venderProduto();

int main() {
    int opcao;

    do {
        exibirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto();
                break;
            case 2:
                consultarEstoque();
                break;
            case 3:
                venderProduto();
                break;
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcaoo invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}


void exibirMenu() {
    printf("\n=== Sistema de Gerenciamento de Estoque ===\n");
    printf("1. Adicionar produto\n");
    printf("2. Consultar estoque\n");
    printf("3. Vender produto\n");
    printf("4. Sair\n");
    printf("===========================================\n");
}
void adicionarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Estoque cheio! nao e possivel adicionar mais produtos.\n");
        return;
    }

    Produto novoProduto;
    printf("Digite o nome do produto: ");
    scanf("%s", novoProduto.nome);
    printf("Digite a quantidade: ");
    scanf("%d", &novoProduto.quantidade);
    printf("Digite o preco: ");
    scanf("%f", &novoProduto.preco);

    estoque[totalProdutos] = novoProduto;
    totalProdutos++;

    printf("Produto adicionado com sucesso!\n");
}
void consultarEstoque() {
    if (totalProdutos == 0) {
        printf("O estoque esta vazio.\n");
        return;
    }

    printf("\n=== Estoque ===\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("Produto: %s | Quantidade: %d | Preco: R$%.2f\n",
               estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
    }
    printf("================\n");
}
void venderProduto() {
    char nome[50];
    int quantidade;

    printf("Digite o nome do produto: ");
    scanf("%s", nome);
    printf("Digite a quantidade vendida: ");
    scanf("%d", &quantidade);

    for (int i = 0; i < totalProdutos; i++) {
        if (strcmp(estoque[i].nome, nome) == 0) {
            if (estoque[i].quantidade >= quantidade) {
                estoque[i].quantidade -= quantidade;
                printf("Venda realizada com sucesso!\n");
            } else {
                printf("Quantidade insuficiente no estoque!\n");
            }
            return;
        }
    }

    printf("Produto nao encontrado no estoque!\n");
}
