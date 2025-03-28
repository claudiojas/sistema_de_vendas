#include <stdio.h>
#include <stdlib.h>

#define TAMCli 3
#define TAMProd 3
#define TAMVenda 10

typedef struct {
    int id;
    char nome[20];
    int quantidade;
    float valor;
} Produto;

typedef struct {
    int id;
    char nome[20];
} Cliente;

typedef struct {
    int idCliente;
    int idProduto;
    int quantProduto;
    float valorTotal;
} Venda;

void exibirUEMA() {
    printf(" U   U   EEEEE  M     M   AAAAA  \n");
    printf(" U   U   E      MM   MM  A     A \n");
    printf(" U   U   EEEE   M M M M  AAAAAAA \n");
    printf(" U   U   E      M  M  M  A     A \n");
    printf(" UUUUU   EEEEE  M     M  A     A \n");
}

void cadastrarCliente(Cliente c[]) {
    for (int i = 0; i < TAMCli; i++) {
        printf("Cliente %d, Primeiro Nome: ", i + 1);
        scanf("%19s", c[i].nome);
        c[i].id = i + 1;
    }
}

void cadastrarProduto(Produto p[]) {
    for (int i = 0; i < TAMProd; i++) {
        printf("\nNome do Produto %d: ", i + 1);
        scanf("%19s", p[i].nome);
        
        printf("Quantidade: ");
        while (scanf("%d", &p[i].quantidade) != 1) {
            printf("Entrada inválida! Digite um número inteiro: ");
            while (getchar() != '\n');  // Limpa o buffer
        }

        printf("Valor: ");
        while (scanf("%f", &p[i].valor) != 1) {
            printf("Entrada inválida! Digite um número válido: ");
            while (getchar() != '\n');
        }

        p[i].id = i + 1;
    }
}

void consultarCliente(Cliente c[]) {
    printf("\n>>>> Clientes Cadastrados <<<<\n");
    for (int i = 0; i < TAMCli; i++) {
        printf("\nId Cliente: %d", c[i].id);
        printf("\nNome: %s\n", c[i].nome);
    }
    printf("\nPressione Enter para voltar ao menu...");
    getchar();
    getchar();
}

void consultarProduto(Produto p[]) {
    printf("\n>>>> Produtos Cadastrados <<<<\n");
    for (int i = 0; i < TAMProd; i++) {
        printf("\nId Produto: %d", p[i].id);
        printf("\nNome: %s", p[i].nome);
        printf("\nQuantidade: %d", p[i].quantidade);
        printf("\nValor: %.2f\n", p[i].valor);
    }
    printf("\nPressione Enter para voltar ao menu...");
    getchar();
    getchar();
}

void realizarVenda(Venda v[], Produto p[], int *vendaCount) {

    if (*vendaCount >= TAMVenda) {
        printf("\nLimite de vendas atingido!\n");
        return;
    }
    
    int idCliente, idProduto, quantidade;
    printf("\nId do Cliente: ");
    scanf("%d", &idCliente);
    printf("Id do Produto: ");
    scanf("%d", &idProduto);
    printf("Quantidade: ");
    scanf("%d", &quantidade);
    
    if (idProduto < 1 || idProduto > TAMProd || idCliente < 1 || idCliente > TAMCli) {
        printf("\nCliente ou Produto inválido!\n");
        return;
    }
    
    if (p[idProduto - 1].quantidade < quantidade) {
        printf("\nEstoque insuficiente!\n");
        return;
    }
    
    v[*vendaCount].idCliente = idCliente;
    v[*vendaCount].idProduto = idProduto;
    v[*vendaCount].quantProduto = quantidade;
    v[*vendaCount].valorTotal = quantidade * p[idProduto - 1].valor;
    
    p[idProduto - 1].quantidade -= quantidade;
    (*vendaCount)++;
    printf("\nVenda realizada com sucesso!\n");
}

void consultarVendas(Venda v[], int vendaCount) {
    if (vendaCount == 0) {
        printf("\nNenhuma venda registrada!\n");
        return;
    }
    
    for (int i = 0; i < vendaCount; i++) {
        printf("\nVenda %d - Cliente ID: %d, Produto ID: %d, Quantidade: %d, Total: %.2f", i + 1, v[i].idCliente, v[i].idProduto, v[i].quantProduto, v[i].valorTotal);
    }
    printf("\n\n");
}

int main() {
    int opcao, sair = 0, vendaCount = 0;
    Cliente clientes[TAMCli];
    Produto produtos[TAMProd];
    Venda vendas[TAMVenda];

    system("clear");
    exibirUEMA();
    printf("\n----------------------------------");

    do {
        printf("\n\n>>>> Sistema de Vendas <<<< ");
        printf("\n1 - Cadastrar Clientes");
        printf("\n2 - Cadastrar Produtos");
        printf("\n3 - Consultar Clientes");
        printf("\n4 - Consultar Produtos");
        printf("\n5 - Realizar Venda");
        printf("\n6 - Consultar Vendas");
        printf("\n7 - Sair\n>>>> ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                cadastrarCliente(clientes);
                break;
            case 2:
                cadastrarProduto(produtos);
                break;
            case 3:
                consultarCliente(clientes);
                break;
            case 4:
                consultarProduto(produtos);
                break;
            case 5:
                realizarVenda(vendas, produtos, &vendaCount);
                break;
            case 6:
                consultarVendas(vendas, vendaCount);
                break;
            case 7:
                sair = 1;
                break;
            default:
                printf("\nOpcao Invalida!\n");
        }
    } while (sair != 1);

    printf("\nSaindo...\n");
    return 0;
}
