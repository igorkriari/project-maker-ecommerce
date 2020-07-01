#include <stdio.h>
#include <stdlib.h>

int main()
{
  int codProd[3], qtdEstoque[3], i, busca, posicao = -1, estoque, carrinhoProd[10], item = 0, carrinhoQtd[10];
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
  printf("\n--------- Inserir no Carrinho -----------------------------------\n");
  printf("\n Codigo do Produto...: ");
  scanf("%d", &carrinhoProd[item]);
  printf("\n Quantidade do Produto...: ");
  scanf("%d", &carrinhoQtd[item]);
  for (i = 0; i < 3; i++)
  {
    if (codProd[i] == carrinhoProd[item])
    {
      posicao = i;
    }
  }

  printf("\n Valor de posicao %d", posicao);
  printf("\n---------------------------------------------------------");
  printf("\nTotal do Produto..: %.2f", precoProd[posicao] * carrinhoQtd[item]);

  return 0;
}