#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // Limite do estoque

// Estrutura do produto
typedef struct {
    int id;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

// Funções do sistema
void inserirProduto(Produto estoque[], int *contador);
void alterarProduto(Produto estoque[], int contador);
void removerProduto(Produto estoque[], int *contador);
void consultarProduto(Produto estoque[], int contador);
void listarProduto(Produto estoque[], int contador);

int main() {
    Produto estoque[MAX];
    int contador = 0;
    int opcao;

    do {
        printf("\n=== Sistema de Estoque CLOUDTECH ===\n");
        printf("1 - Inserir Produto\n");
        printf("2 - Alterar Produto\n");
        printf("3 - Remover Produto\n");
        printf("4 - Consultar Produto\n");
        printf("5 - Listar Produtos\n");
        printf("0 - Salvar/Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer

        switch (opcao) {
            case 1: inserirProduto(estoque, &contador); break;
            case 2: alterarProduto(estoque, contador); break;
            case 3: removerProduto(estoque, &contador); break;
            case 4: consultarProduto(estoque, contador); break;
            case 5: listarProduto(estoque, contador); break;
            case 0: printf("Encerrando o sistema...\n"); break;
            default: printf("Opcao invalida, digite novamente!\n");
        }
    } while (opcao != 0);

    return 0;
}

void inserirProduto(Produto estoque[], int *contador) {
    if (*contador >= MAX) {
        printf("Estoque cheio.\n");
        return;
    }

    Produto p;
    p.id = *contador + 1; // gera ID automático

    printf("Nome do produto: ");
    fgets(p.nome, 50, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0'; // remover \n

    printf("Quantidade: ");
    scanf("%d", &p.quantidade);

    printf("Preco: ");
    scanf("%f", &p.preco);
    getchar(); // limpa enter

    estoque[*contador] = p;
    (*contador)++;

    printf("Produto inserido com sucesso!\n");
}

void alterarProduto(Produto estoque[], int contador) {
    int id;
    printf("Digite o ID do produto para altera-lo: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < contador; i++) {
        if (estoque[i].id == id) {
            printf("Novo nome: ");
            fgets(estoque[i].nome, 50, stdin);
            estoque[i].nome[strcspn(estoque[i].nome, "\n")] = '\0';

            printf("Nova quantidade: ");
            scanf("%d", &estoque[i].quantidade);

            printf("Novo preco: ");
            scanf("%f", &estoque[i].preco);
            getchar();

            printf("Produto alterado com sucesso!\n");
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

void removerProduto(Produto estoque[], int *contador) {
    int id;
    printf("Digite o ID do produto que sera removido: ");
    scanf("%d", &id);

    for (int i = 0; i < *contador; i++) {
        if (estoque[i].id == id) {
            // deslocando os elementos
            for (int j = i; j < *contador - 1; j++) {
                estoque[j] = estoque[j + 1];
                estoque[j].id = j + 1; // atualiza ID
            }
            (*contador)--;
            printf("Produto removido com sucesso!\n");
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

void consultarProduto(Produto estoque[], int contador) {
    int id;
    printf("Digite o ID do produto: ");
    scanf("%d", &id);

    for (int i = 0; i < contador; i++) {
        if (estoque[i].id == id) {
            printf("ID: %d | Nome: %s | Quantidade: %d | Preco: %.2f\n",
                   estoque[i].id, estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
            return;
        }
    }
    printf("Produto nao encontrado.\n");
}

void listarProduto(Produto estoque[], int contador) {
    printf("\n=== Lista de Produtos ===\n");
    if (contador == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    for (int i = 0; i < contador; i++) {
        printf("ID: %d | Nome: %s | Quantidade: %d | Preco: %.2f\n",
               estoque[i].id, estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
    }
}
