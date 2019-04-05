#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
    int NumConta;
    char Cliente[100];
    float Saldo;
    int Senha;
    char Chave;
}contabancaria;

int encerrar_conta(contabancaria * lista_clientes)
{
    int num, sen;
    char chav, conf;

    puts("INFORME O NUMERO DA CONTA: ");
    scanf("%d", &num);

    puts("INSIRA A SENHA: ");
    scanf("%d", &sen);

    fflush(stdin);

    puts("INSIRA A CHAVE: ");
    chav = getchar();

    if(lista_clientes[num].Senha == sen)
    {
        if(lista_clientes[num].Chave == chav)
        {
            fflush(stdin);

            puts("TEM CERTEZA QUE DESEJA EXCLUIR SUA CONTA? [s/n] ");
            conf = getchar();

            if(conf == 's')
            {
                puts("CONTA EXCLUIDA!");
                lista_clientes[num].Senha = 0;
                lista_clientes[num].Chave = 0;
                strcpy(lista_clientes[num].Cliente, "0");
                lista_clientes[num].Saldo = 0;
            }
            else
            {
                puts("PROCESSO CANCELADO!");
            }
        }
    }

    return 0;
}

int saca_valor(contabancaria * lista_clientes)
{
    int num, sen;
    char chav;
    float sac = 0;

    puts("INFORME O NUMERO DA CONTA: ");
    scanf("%d", &num);

    puts("INFORME A SENHA: ");
    scanf("%d", &sen);

    fflush(stdin);

    puts("INFORME A CHAVE: ");
    chav = getchar();

    if(lista_clientes[num].Senha == sen)
    {
       if(lista_clientes[num].Chave == chav)
       {
            puts("INFORME O VALOR DE SAQUE: ");
            scanf("%f", &sac);
            if(sac <= lista_clientes[num].Saldo)
            {
                puts("SAQUE AUTORIZADO!");

                printf("SALDO ANTERIOR: %.2f\n", lista_clientes[num].Saldo);
                lista_clientes[num].Saldo -= sac;
                printf("SALDO ATUAL: %.2f\n", lista_clientes[num].Saldo);
            }
            else
            {
                puts("VOCE NAO TEM SALDO SUFICIENTE!");
            }
       }
       else
       {
           puts("DADOS INVALIDOS!");
       }
    }
    else
    {
        puts("DADOS INVALIDOS!");
    }

    return 0;
}


int deposito_valor(contabancaria * lista_clientes)
{
    int num;
    float adc;
    char name[100];

    puts("INFORME O NUMERO DA CONTA: ");
    scanf("%d", &num);

    puts("INFORME O NOME: ");

    fflush(stdin);
    gets(name);

    if(strcmp(lista_clientes[num].Cliente, name) == 0)
    {
        puts("INFORME O VALOR QUE DESEJA DEPOSITAR: ");
        scanf("%f", &adc);
        lista_clientes[num].Saldo += adc;
        puts("SALDO REALIZADO COM SUCESSO!");
    }
    else
    {
        puts("NOME OU NUMERO DE CONTA INVALIDA!\n");
    }

    return 0;
}

int consulta_saldo(contabancaria * lista_clientes)
{
    int num, sen;

    puts("INFORME O NUMERO DA CONTA: ");
    scanf("%d", &num);

    puts("INFORME A SENHA: ");
    scanf("%d", &sen);

    if(lista_clientes[num].Senha == sen)
    {
        printf("SEU SALDO E %.2f\n", lista_clientes[num].Saldo);
    }else
    {
        puts("SENHA OU NUMERO DE CONTA INVALIDA!");
    }

    return 0;
}

int criar_conta(int i, contabancaria * lista_clientes)
{
    puts("INFORME SEU NOME: ");

    fflush(stdin);

    gets(lista_clientes[i].Cliente);

    puts("CRIE UMA SENHA: ");

    scanf("%d", &lista_clientes[i].Senha);

    printf("NUMERO DA SUA CONTA: %d\n", i);

    lista_clientes[i].NumConta = i;

    srand(time(NULL));

    lista_clientes[i].Chave = (rand() % 25) + 97;

    printf("SUA CHAVE: %c\n", lista_clientes[i].Chave);

    lista_clientes[i].Saldo = 0;

    return 0;
}
void caso(int menu2, contabancaria * lista_clientes, int * i2){

    switch(menu2)
    {
        case 0:
            printf("ENCERRANDO...");
            break;

        case 1:
            criar_conta(*i2, lista_clientes);
            (*i2)++;
            break;

        case 2:
            consulta_saldo(lista_clientes);
            break;

        case 3:
            deposito_valor(lista_clientes);
            break;
        case 4:
            saca_valor(lista_clientes);
            break;

        case 5:
            encerrar_conta(lista_clientes);
            break;

        default:
            puts("OPCAO INVALIDA!");
            break;
    }
}

int main()
{
    int menu, i = 0;

    contabancaria lista_clientes[10];

    while(menu != 0){

        puts("BANCO CATUABA");

        puts("MENU");

        puts("[1] - CRIAR CONTA");
        puts("[2] - CONSULTAR SALDO");
        puts("[3] - DEPOSITAR UM VALOR");
        puts("[4] - SACAR UM VALOR");
        puts("[5] - ENCERRAR CONTA");
        puts("[0] - SAIR");
        scanf("%d", &menu);

        caso(menu, lista_clientes, &i);
    }

    return 0;
}