#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int primo();

void nome_matricula(void){
    char nome[10];
    int matricula;

    setbuf(stdin, 0);

    printf("INFORME SEU NOME: ");
    fgets(nome, 10, stdin);

    nome[strlen(nome)-1] = '\0';

    printf("INFORME SUA MATRICULA: ");
    scanf("%d", &matricula);
    printf("\nSEU NOME E %s\n", nome);
    printf("MATRICULA EM HEXADECIMAL: %X\n", matricula);
}

void media_ponderada(void){
    float n[3], media_p;

    printf("INFORME AS NOTAS (OBS, 3 NOTA TEM PESO 2): \n");
    for(int i = 0; i < 3; i++){
        printf("%d NOTA: ", i+1);
        scanf("%f", &n[i]);
    }
    media_p = (n[0] + n[1] + (n[2]*2))/4;
    printf("\nMEDIA PONDERADA: %.2f\n", media_p);
    if(media_p >= 60){
        printf("APROVADO!\n");
    }else{
        printf("REPROVADO!\n");
    }
}

int media(void){
    float n1, n2;

    printf("PRIMEIRA NOTA: ");
    scanf("%f", &n1);
    printf("SEGUNDA NOTA: ");
    scanf("%f", &n2);

    if(((0 > n1) || (n1 > 10)) || ((0 > n2) || (n2 > 10))){
        printf("NOTA INVALIDA!\n");
    }else{
        printf("MEDIA: %.2f\n", (n1+n2)/2);
    }

    return 0;
}

void bissexto(void){
    unsigned short int b;

    printf("INFORME O ANO: ");
    scanf("%hu", &b);

    if(b % 4 == 0){
        printf("E BISSEXTO!\n");
    }else{
        printf("NAO E BISSEXTO!\n");
    }
}

void raiz(void){
    float a;
    int b;

    printf("INFORME UM NUMERO REAL (INDICE): ");
    scanf("%f", &a);
    printf("INFORME UM NUMERO INTEIRO (RADICANDO): ");
    scanf("%d", &b);
    printf("RAIZ(%.2f, %d) = %e\n", a, b, pow(b, 1/a));
}

void elevado(void){
    float a;
    int b;

    printf("INFORME UM NUMERO REAL: ");
    scanf("%f", &a);
    printf("INFORME UM NUMERO INTEIRO: ");
    scanf("%d", &b);
    printf("%f ELEVADO A %d = %E", a, b, pow(a, b));
}

int sequencia_primo(void){

    int n;

    printf("QUANTIDADE DE VERIFICACOES: ");
    scanf("%d", &n);

    int vetor[n];

    printf("\nINFORME OS VALORES: \n");
    for(int i = 0; i < n; i++){
        printf("%d: ", i+1);
        scanf("%d", &vetor[i]);
    }
    for(int i = 0; i < n; i++){
        if(vetor[i] != 0){
            primo(vetor[i]);
        }
    }

    return 0;
}

int primo(int verifica){
    int dividendo;

    dividendo = verifica / 2;
    while(dividendo > 1){
        if(verifica % dividendo == 0){
            printf("%d NAO E PRIMO!\n", verifica);
            return 0;
        }
        dividendo--;
    }
    printf("%d E PRIMO!\n", verifica);

    return 0;
}

void fatorial(void){
    int fatorial2;

    printf("FATORIAL DE: ");
            scanf("%d", &fatorial2);
            for(int i = (fatorial2 - 1); i > 1; i--){
                fatorial2 = fatorial2 * i;
            }
            printf("RESPOSTA: %d\n", fatorial2);
}

void menu(int caso2){
    int primo2;

    switch(caso2){
        case 0:
            printf("FINALIZANDO...");
            break;
        case 1:
            fatorial();
            break;
        case 2:
            printf("NUMERO DE CONSULTA: ");
            scanf("%d", &primo2);
            primo(primo2);
            break;
        case 3:
            sequencia_primo();
            break;
        case 4:
            elevado();
            break;
        case 5:
            raiz();
            break;
        case 6:
            bissexto();
            break;
        case 7:
            media();
            break;
        case 8:
            media_ponderada();
            break;
        case 9:
            nome_matricula();
            break;
        default:
            printf("\nCASO INVALIDO!\n");
    }
}

int main(void){
    int caso = 1;
    while(caso != 0){
        printf("\n\t>>>MENU<<<\n\n");
        printf("[1] FATORIAL\n");
        printf("[2] PRIMO\n");
        printf("[3] SEQUENCIA PRIMO\n");
        printf("[4] \"A\" ELEVADO A \"B\"\n");
        printf("[5] RAIZ\n");
        printf("[6] BISSEXTO\n");
        printf("[7] MEDIA\n");
        printf("[8] MEDIA PONDERADA\n");
        printf("[9] NOME E MATRICULA\n");
        scanf("%d", &caso);

        menu(caso);
    }
    return 0;
}