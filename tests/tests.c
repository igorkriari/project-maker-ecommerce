#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variáveis a serem utilizadas
int SKU[100], estoque[100], i = -1, j, busca, posicao = -1, running, carrinhoPDT[100], carrinhoQTD[100], item = 0;
char opera;
char name[100];
float price[100];

//Função cadastrar.
void cadastrar() 
{
    printf("\n>> CADASTRO DE PRODUTOS <<<\nPara cadastrar um produto novo, é necessário ter as seguintes informações:\nSKU\nNome do produto\nNúmero de unidades em estoque\nPreço base unitário\nDeseja cadastrar um novo produto? [S/N]: ");
    scanf("%s", &opera);
    while (strcmp(&opera, "S") == 0 || (strcmp(&opera, "s") == 0)) //Enquanto for S ou s a resposta de "quer continuar?", o código continuará repetindo a partir daqui
    {
        while (strcmp(&opera, "S") != 0 && (strcmp(&opera, "s") != 0) && (strcmp(&opera, "n") != 0) && (strcmp(&opera, "N") != 0))
        { //Enquanto o usuário não digitar S, s, n ou N,
            printf("\n Comando inválido. Deseja inserir outro cadastro? S/N: ");
            scanf("%s", &opera); // ele repete "Comando inválido" e pede pra reinserir.
        }
        if (strcmp(&opera, "S") == 0 || (strcmp(&opera, "s") == 0)) //Caso seja S ou s, ele pede as informações e armazena na posição atual de i (que é iniciada em -1, mas já é pré-incrementada para 0 na primeira execução)
        {
            i++;
            printf("\n--------------------------------------------\n");
            printf("\nSKU: ");
            scanf("%d", &SKU[i]);
            printf("\nDESCRIÇÃO: ");
            gets(name);
            printf("\nUNIDADES EM ESTOQUE: ");
            scanf("%d", &estoque[i]);
            printf("\nVALOR BASE DO PRODUTO: ");
            scanf("%f", &price[i]);
            printf("\n--------------------------------------------\n");
            printf("Deseja fazer mais um cadastro?");
            scanf("%s", &opera);
        }
        else if (strcmp(&opera, "N") //Caso seja N ou n, ele sai.
                 || (strcmp(&opera, "n")))
        {
            return;
        }
    }
}
//carrinho
void carrinho()
{
    printf("\nCARRINHO GEEKSTORE\nPara adicionar ao carrinho, digite o código SKU referente ao produto e a quantidade do produto a ser adicionada.");
    printf("\nCÓDIGO SKU: ");
    scanf("%d", &carrinhoPDT[item]);
    printf("\nQUANTIDADE DO PRODUTO: ");
    scanf("%d", &carrinhoQTD[item]);
    for (i = 0; i < 100; i++)
    {
        if (SKU[i] == carrinhoPDT[item])
        {
            posicao = i;
        }
    }

    printf("\n Valor de posicao %d", posicao);
    printf("\n---------------------------------------------------------");
    printf("Total do Produto..: %.2f", price[posicao] * carrinhoQTD[item]);

    return;
}

int main()
{
    cadastrar();
    carrinho();
}