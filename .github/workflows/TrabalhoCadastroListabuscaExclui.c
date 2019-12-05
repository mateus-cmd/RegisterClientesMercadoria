#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[100];
    char rg[100];
    char cpf[100];
    char telefone[100];
    char endereco[100];
} Tcliente;

typedef struct
{
    char codigo[100];
    float valorunitario;
    char tipounidade[100];
    char quantidadeEstoque[100];
} Tmercadoria;
typedef struct
{
    char id[10];
    char idMercadoria[100];
    char idCliente[100];
    int quantidade;
} Tvenda;

void RecebevalorCliente(Tcliente *cliente, int *plista       );

void exibeDados(Tcliente *cliente,int *pqtcliente            );

void Cadastrar_Mercadoria(Tmercadoria *Mer, int *PMercadoria );

void Listar_mercadoria(Tmercadoria *Mer,int *PMercadoria     );

void BuscarCliente(Tcliente *cliente,int *Quanticliente );

void Buscarmercadoria(Tmercadoria *mercadoria, int *Quantimercadoria);

void Vender(Tcliente *cliente, Tmercadoria *mercadoria,int *contagem,int *contagemMercadoria,int *contagemCliente,int *contagemVenda);

char menu();


int main()
{
    Tcliente lista[1000];
    Tmercadoria Mlista[1000];
    Tvenda Venda[1000];
    char op;
    int qtcliente=0,PMercadoria=0,vendas=0,cont=0;

    while(1)

    {
        op=menu();
        switch(op)
        {
        case '1':
            RecebevalorCliente(lista,&qtcliente);

            break;
        case '2':
            exibeDados(lista,& qtcliente);
            break;
        case '3':
            Cadastrar_Mercadoria(Mlista,&PMercadoria);

            break;
        case '4':
            Listar_mercadoria (Mlista,&PMercadoria);
            break;
        case '5' :
            BuscarCliente(lista,&qtcliente);
            break;
        case '6':
            Buscarmercadoria(Mlista, &PMercadoria);
            break;
        case '7':
            Vender(lista, Mlista,&cont,&vendas,&qtcliente,&PMercadoria);
            break;

        default:

            printf ("Voce digitou uma opcao invalida!");
            fflush(stdin);
        }
        getchar();

    }
}


void RecebevalorCliente(Tcliente *cliente, int *plista)
{
    system("cls");

    fflush(stdin);
    printf("Digite Nome Do cliente      \n");
    scanf("%[^\n]s",(cliente+*plista)->nome); //O endereço indicado pelo ponteiro armazenará o valor digitado

    fflush(stdin);
    printf("Digite o CPF do cliente     \n");
    scanf("%[^\n]s",&(cliente+*plista)->cpf);

    fflush(stdin);
    printf("Digite o Endereco           \n");
    scanf("%[^\n]s",(cliente+*plista)->endereco); //O endereço indicado pelo ponteiro armazenará o valor digitado

    fflush(stdin);
    printf("Digite o RG                 \n");
    scanf("%[^\n]s",(cliente+*plista)->rg);

    fflush(stdin);
    printf("Digite o telefone           \n");
    scanf("%[^\n]s",(cliente+*plista)->telefone);

    *plista=*plista+1;
}

void exibeDados(Tcliente *cliente,int *pqtcliente)
{
    int cont;

    system("cls");
    printf("_________________________     LISTAGEM DE DADOS     __________________________\n\n\n");

    for (cont=0; cont<*pqtcliente; cont++)
    {

        printf("\n\nNome  : %s \n ",(cliente+cont)->nome     );
        printf("CPF       : %s \n ",(cliente+cont)->cpf      );
        printf("Endereco  : %s \n ",(cliente+cont)->endereco );
        printf("RG        : %s \n ",(cliente+cont)->rg       );
        printf("Telefone  : %s \n ",(cliente+cont)->telefone );
    }
    fflush(stdin);
    getchar();
}



void Cadastrar_Mercadoria(Tmercadoria *Mer, int *PMercadoria)
{
    system("cls");
    printf("\n\n_________ Cadastrar mercadoria______________________\n" );              // Cadastrar mercadorias

    fflush(stdin);
    printf("\n|  Digite o codigo da mercadoria                :   ");
    scanf("%[^\n]s",(Mer + *PMercadoria)->codigo);

    fflush(stdin);
    printf("\n|  Digite o valor unitario da mercadoria        :   ");
    scanf("%f",&(Mer + *PMercadoria)->valorunitario);

    fflush(stdin);
    printf("\n|  Informe o tipo da mercadoria                 :   ");
    scanf("%[^\n]s",(Mer + *PMercadoria)->tipounidade);

    fflush(stdin);
    printf("\n|  Informe a quantidade de mercadoria           :   ");
    scanf("%[^\n]s",(Mer + *PMercadoria)->quantidadeEstoque);

    *PMercadoria=*PMercadoria+1;

}
void Listar_mercadoria(Tmercadoria *Mer,int *PMercadoria)
{
    system("cls");

    int cont;
    for (cont=0; cont<*PMercadoria; cont++)
    {
        printf("__________Listar Mercadoria ______________");
        printf("\n| Cadastro de numero           %d                           ",cont+1);
        printf("\n| Codigo:            %s                           ",(Mer + cont)->codigo            );  //lista nome
        printf("\n| Valor Unitario:    %s                           ",(Mer + cont)->valorunitario     ); //lista rg
        printf("\n| Tipo:              %s                           ",(Mer + cont)->tipounidade       ); // lista Cpf
        printf("\n| Quantidade:        %s                           ",(Mer + cont)->quantidadeEstoque );  //lista rua
        printf("\n|________________________________________________\n");
    }
    fflush(stdin);
    getchar();
}
char menu()
{
    system("cls");

    printf("______________________        Menu                __________\n\n\n");
    printf("___1__________________   Cadastrar Cliente        __________\n\n\n");
    printf("___2__________________   Listar Cliente           __________\n\n\n");
    printf("___3__________________   Cadastrar Mercadoria     __________\n\n\n");
    printf("___4__________________   Listar Mercadoria        __________\n\n\n");
    printf("___5__________________   Buscar Cliente           __________\n\n\n");
    printf("___6__________________   Buscar Mercadoria        __________\n\n\n");
    printf("___7__________________      Vender                __________\n\n\n");
    fflush(stdin);
    return (getchar());
}

void BuscarCliente(Tcliente *cliente, int *Quanticliente)

{
    system("cls");
    int cont,encontrados=0;
    char qtCliente[100];
    printf(" Digite o nome  ser pesquisado ? ");
    scanf("%s",qtCliente);

    for (cont=0; cont<*Quanticliente; cont++)
    {
        if(strcmp(qtCliente, (cliente+cont)->cpf )==0)
        {
            printf("Nome      : %s \n ",(cliente+cont)->nome     );
            printf("Cpf       : %s \n ",(cliente+cont)->cpf );
            printf("Endereco  : %s \n ",(cliente+cont)->endereco );
            printf("RG        : %s \n ",(cliente+cont)->rg       );
            printf("Telefone  : %s \n ",(cliente+cont)->telefone );
            encontrados++;

        }
        fflush(stdin);
        getchar();
    }
    if(encontrados==0)
    {

        printf(" Nome nao existe !!!!! ");
        getchar();
    }


}
void Buscarmercadoria(Tmercadoria *mercadoria, int *Quantimercadoria)
{
    system("cls");
    int cont,encontrados=0;
    char qtmercadoria[100];
    printf(" Digite o nome  ser pesquisado ? ");
    scanf("%s",qtmercadoria);

    for (cont=0; cont<*Quantimercadoria; cont++)
    {
        if(strcmp(qtmercadoria, (mercadoria+cont)->codigo )==0)
        {
            printf("\n| Cadastro de numero           %d                           ",cont);
            printf("\n| Codigo:            %s                           ",(mercadoria + cont)->codigo            );  //lista nome
            printf("\n| Valor Unitario:    %s                           ",(mercadoria + cont)->valorunitario     ); //lista rg
            printf("\n| Tipo:              %s                           ",(mercadoria + cont)->tipounidade       ); // lista Cpf
            printf("\n| Quantidade:        %s                           ",(mercadoria + cont)->quantidadeEstoque );
            encontrados++;

        }
        fflush(stdin);
        getchar();
    }
    if(encontrados==0)
    {

        printf(" Nome nao existe !!!!! ");
        getchar();
    }
}

void Vender(Tcliente *cliente,  Tmercadoria *mercadoria,int *contagem,int *contagemMercadoria,int *contagemCliente,int *contagemVenda)
{
    Tvenda venda[1000];
    char Mercad[1000];
    char client[1000];
    int quant;
    int idmercadoria=0;
    int encontrados=0;
    system("cls");
    char mer[100],cli[100]="";
    int cont;


    while ( !strcmp(cli,"sair") )
    {
        fflush(stdin);
        printf("\n Digite o nome do cliente        ");
        scanf("%s",cli);

        for (cont=0; cont<*contagemCliente; cont++)
        {
            if(strcmp(cli, (cliente+cont)->cpf )==0)
            {
                (venda)->idCliente==(cliente+cont)->cpf;
                strcpy(cli,"sair");
                break;
            }
            else
            {

                printf(" Nome nao existe !!!!! ");
                getchar();
            }
        }
    }




    fflush(stdin);
    printf("\n Digite o nome da mercadoria     ");
    scanf("%s",mer);
    while ( !strcmp(mer,"sair"))
    {
        for (idmercadoria=0; idmercadoria<*contagemMercadoria; idmercadoria++)
        {

            if (strcmp(mer, (mercadoria+cont)->codigo==0))
            {

                venda->idMercadoria==(mercadoria+idmercadoria)->codigo;
                venda->quantidade==(mercadoria+idmercadoria)->quantidadeEstoque;

                printf(" Nome da Mercadoria    : %s",(venda+cont)->idMercadoria);
                printf(" Quantidade Em Estoque : %f",(venda +cont )->quantidade);

            }
            else
            {

                printf(" Nome nao existe !!!!! ");
                getchar();
            }
        }
    }

    fflush(stdin);
    getchar();
}






