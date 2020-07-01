#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Variáveis a serem utilizadas
int SKU[100], estoque[100], i = -1, j, busca, posicao = -1, running, carrinhoPDT, carrinhoQTD, item[100];
char opera, name[100];
float price[100], precototal;

//Display da página de compras
void display()
{
    printf("GEEKPOWER - LOJA\n\n");
    printf("1. Minecraft - R$ 120.00\n");
    printf("2. WARFRAME - R$ 10.00\n");
    printf("3. PES2020 - R$ 199.99\n");
    printf("4. XBOX ONE S - R$ 1999.99\n");
    printf("5. Playstation 4 - R$ 2199.99\n");
    printf("6. Nintendo Switch - R$ 2699.99\n");
}

//Cadastro de Produtos
void cadastrar() //Função cadastrar.
{
    printf("\nCADASTRO DE PRODUTOS GEEKSTORE\nPara cadastrar um produto novo, é necessário ter as seguintes informações:\nSKU\nNome do produto\nNúmero de unidades em estoque\nPreço base unitário\nDeseja cadastrar um novo produto? Digite S para sim, N para não: ");
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
            printf("\nDESCRIÇÃO: ");
            scanf("%s", &name[i]);
            printf("\nSKU: ");
            scanf("%d", &SKU[i]);
            printf("\nUNIDADES EM ESTOQUE: ");
            scanf("%d", &estoque[i]);
            printf("\nVALOR BASE DO PRODUTO: ");
            scanf("%f", &price[i]);
            printf("\n--------------------------------------------\n");
            printf("Deseja fazer mais um cadastro? Digite S para sim, ou N para voltar: ");
            scanf("%s", &opera);
        }
        else if (strcmp(&opera, "N") //Caso seja N ou n, ele sai.
                 || (strcmp(&opera, "n")))
        {
            return;
        }
    }
}

// Consulta de Produtos
void consultar() //Função consultar.
{
    printf("\nCONSULTA DE PRODUTOS GEEKSTORE\nPara consultar informações sobre um produto específico, é necessário possuir o SKU atrelado a este. Deseja consultar algum produto? Digite S para sim, N para não: ");
    scanf("%s", &opera);
    while (strcmp(&opera, "S") == 0 || (strcmp(&opera, "s") == 0)) //Enquanto for S ou s a resposta de "quer continuar?", o código continuará repetindo a partir daqui
    {
        while (strcmp(&opera, "S") != 0 && (strcmp(&opera, "s") != 0) && (strcmp(&opera, "n") != 0) && (strcmp(&opera, "N") != 0))
        { //Enquanto o usuário não digitar S, s, n ou N,
            printf("\n Comando inválido. Deseja fazer uma nova consulta? S/N: ");
            scanf("%s", &opera); // ele repete "Comando inválido" e pede pra reinserir.
        }
        if (strcmp(&opera, "S") == 0 || (strcmp(&opera, "s") == 0)) //Caso seja S ou s, ele pede o código SKU a ser pesquisado.
        {
            printf("\nDigite o código SKU a ser consultado: ");
            scanf("%d", &busca);
            for (j = 0; j <= 100; j++) //Ele busca de 1 a 100 nas posições por um SKU igual ao fornecido,
            {
                if (SKU[j] == busca)
                {
                    posicao = j; //e caso encontre, ele armazena a posição deste
                }
            }
            //Resultado da busca
            if (posicao == -1) //Faz um check pra ver se ela foi preenchida/encontrada, caso não tenha sido modificado o valor de "posição", ou seja, não tenha sido encontrado SKU equivalente, ela será -1 e retornará "produto está indisponível".
            {
                printf("\nEste produto não se encontra disponível. ");
                printf("Deseja fazer mais uma consulta? Digite S para sim, N para não: ");
                scanf("%s", &opera);
            }
            else
            { //Com essa posição, ele acha a descrição, número de unidades e preço.
                printf("\nDescrição do produto: %s", &name[posicao]);
                printf("\nUnidades em estoque: %d", estoque[posicao]);
                printf("\nPreço base: %.2f\n", price[posicao]);
                printf("Deseja fazer mais uma consulta? Digite S para sim, N para não: ");
                scanf("%s", &opera);
            }
        }
        else if (strcmp(&opera, "N") //Caso seja N ou n, ele sai.
                 || (strcmp(&opera, "n")))
        {
            return;
        };
    }
}

// Carrinho da Loja
void carrinho()
{
    printf("\nCARRINHO GEEKSTORE\nPara adicionar ao carrinho, você deve ter em mente o código SKU do produto e a quantidade a ser adicionada.\n Deseja adicionar um produto novo ao carrinho? S para sim, N para não: ");
    scanf("%s", &opera);
    while (strcmp(&opera, "S") == 0 || (strcmp(&opera, "s") == 0)) //Enquanto for S ou s a resposta de "quer continuar?", o código continuará repetindo a partir daqui
    {
        while (strcmp(&opera, "S") != 0 && (strcmp(&opera, "s") != 0) && (strcmp(&opera, "n") != 0) && (strcmp(&opera, "N") != 0))
        { //Enquanto o usuário não digitar S, s, n ou N,
            printf("\n Comando inválido. Deseja inserir outro item no carrinho? S/N: ");
            scanf("%s", &opera); // ele repete "Comando inválido" e pede pra reinserir.
        }
        if (strcmp(&opera, "S") == 0 || (strcmp(&opera, "s") == 0)) //Caso seja S ou s, ele pede as informações e armazena na posição atual de i (que é iniciada em -1, mas já é pré-incrementada para 0 na primeira execução)
        {
            printf("\nCÓDIGO SKU: ");
            scanf("%d", &carrinhoPDT[item]);
            printf("\nQUANTIDADE DO PRODUTO: ");
            scanf("%d", &carrinhoQTD[item]);
            for (j = 0; j < 100; j++)
            {
                if (SKU[j] == carrinhoPDT[item])
                {
                    posicao = j;
                }
            }
            printf("\n---------------------------------------------------------\n");
            printf("VALOR TOTAL DO CARRINHO: %.2f", (price[posicao] * carrinhoQTD[item]));
            printf("\nDeseja adicionar outro produto ao carrinho? S para sim, N para finalizar a compra: ");
            scanf("%s", &opera);
        }
        else if (strcmp(&opera, "N") //Caso seja N ou n, ele sai.
                 || (strcmp(&opera, "n")))
        {
            return;
        }
    }
}

int main(void)
{

    printf("Este programa consiste numa frente de e-commerce para uma loja digital de foco em jogos eletrônicos.\nAqui será demonstrado o controle de estoque: adicionando produtos novos na loja, checando o estoque existente, e o protótipo de um carrinho virtual para executar compras no ambiente digital.\nDigite 1 para abrir a loja e ver a lista de produtos já cadastrados.\nDigite 2 para cadastrar um produto novo.\nDigite 3 para consultar um produto no estoque.\nDigite 4 para abrir o carrinho atual.\nDigite 5 para sair.\n ");
    scanf("%d", &running);
    while (running != 5)
    {
        if (running == 1)
        {
            display();
            printf("\nDeseja:\n(1) abrir o menu de produtos, \n(2) cadastrar um novo produto, \n(3) consultar o estoque, \n(4) abrir o carrinho, \n(5) ou sair?\n");
            scanf("%d", &running);
        }
        else if (running == 2)
        {
            cadastrar();
            printf("\nDeseja:\n(1) abrir o menu de produtos, \n(2) cadastrar um novo produto, \n(3) consultar o estoque, \n(4) abrir o carrinho, \n(5) ou sair?\n");
            scanf("%d", &running);
        }
        else if (running == 3)
        {
            consultar();
            printf("\nDeseja:\n(1) abrir o menu de produtos, \n(2) cadastrar um novo produto, \n(3) consultar o estoque, \n(4) abrir o carrinho, \n(5) ou sair?\n");
            scanf("%d", &running);
        }
        else if (running == 4)
        {
            carrinho();
            printf("\nDeseja:\n(1) abrir o menu de produtos, \n(2) cadastrar um novo produto, \n(3) consultar o estoque, \n(4) abrir o carrinho, \n(5) ou sair?\n");
            scanf("%d", &running);
        }
        else
        {
            running = 0;
            printf("\nDeseja:\n(1) abrir o menu de produtos, \n(2) cadastrar um novo produto, \n(3) consultar o estoque, \n(4) abrir o carrinho, \n(5) ou sair?\n");
            scanf("%d", &running);
        }
    }
    return 0;
}