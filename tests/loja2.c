#include <stdio.h>
#include <stdlib.h>

int main()
{
    int codProd[3], qtdEstoque[3], i, busca, posicao = -1, estoque;
    float precoProd[3];

    //Cadastro de Produtos
    for (i = 0; i < 3; i++)
    {
        printf("Codigo do Produto..:");
        scanf("%d", &codProd[i]);
        printf("Quantidade em Estoque..:");
        scanf("%d", &qtdEstoque[i]);
        printf("Preco do Produto..:");
        scanf("%f", &precoProd[i]);
        printf("\n--------------------------------------------\n");
    }
    // Consultado
    printf("\n---------Atualizar Estoque-----------------------------------\n");
    printf("\n Codigo do Produto...: ");
    scanf("%d", &busca);
    for (i = 0; i < 3; i++)
    {
        if (codProd[i] == busca)
        {
            posicao = i;
        }
    }
    // Apresentando o resultado da busca
    if (posicao == -1)
    {
        printf("\nProduto indisponivel");
    }
    else
    {
        printf("\nQuantidade...: ");
        scanf("%d", &estoque);
        qtdEstoque[posicao] = estoque;
        printf("\nQuantidade em Estoque..: %d", qtdEstoque[posicao]);
    }

    return 0;
}