#include <stdio.h>
#include <stdlib.h>


int main()
{
float vetPreco[5], total=0, totalProd, menorPreco;
int i, vetQtd[5],maior, posicao;

printf("\n ------------- Produtos ----------------");
// entrada de dados
for (i=0; i<5; i++) // i começa com zero -- Primeira posição do vetor em C é 0.
{
printf("\nPreco..: ");
scanf("%f", &vetPreco[i]);
printf("Quantidade Vendida..: ");
scanf("%d", &vetQtd[i]);

}

menorPreco = vetPreco[0];
maior = vetQtd[0];
posicao = 0;
// imprimindo a relação dos produtos e suas respectivas quantidades vendidas.
printf("\n------------------ Relacao de Produtos ------------------");

for ( i=0; i<5 ;i++)
{
totalProd = vetPreco[i] * vetQtd[i];
total = total + totalProd;

// Identificando o produto mais vendido
if (vetQtd[i] > maior)
{
maior = vetQtd[i];
posicao = i;
}

// Identificando o produto mais barato - aquele que tem o menor preco
if(vetPreco[i] < menorPreco)
{
menorPreco = vetPreco[i];
}

printf("\nProduto..: %d", i+1);
printf("\nPreco do Produto..: %.2f", vetPreco[i]);
printf("\nQuantidade Vendida..: %d", vetQtd[i]);
printf("\nTotal da venta deste Produto..: %.2f", totalProd);
printf("\n----------------------------------------------");

}

printf("\nTotal das Vendas..: %.2f", total);
printf("\nValor da comissao..: %.2f", total*5/100);
printf("\nO Produto %d , tem o preco do produto mais vendido..: %.2f", posicao+1 , vetPreco[posicao]);
printf("\nProduto com o menor preco..: %.2f", menorPreco);
return 0;
}