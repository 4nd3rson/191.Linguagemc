#include <stdio.h>
#include <stdlib.h>

int str_len(char *string1){
    int i = 0;

    while(string1[i] != '\0') i++;

    return i;
}

int str_cmp(char *string1, char *string2){
    int i = 0;
    while(string1[i] == string2[i] && string1[i] != '\0') i++;
    return (string1[i] - string2[i]) ? 0 : 1;
}

char * str_cat(char *string1, char *string2){
    int i, size = str_len(string1);

    for(i = 0; string2[i] != '\0'; i++)
        string1[size + i] = string2[i];
    string1[size + i] = '\0';

    return string1;
}

void str_cpy(char *string1, char *string2){
    int i;

    for(i = 0; string2[i] != '\0'; i++)
        string1[i] = string2[i];
    string1[i] = '\0';
}

int main()
{
    char teste[30], teste2[] = "Hello world!";

    str_cpy(teste, "Hello world!");
    printf("%s\n", teste);
    printf("%d\n", str_len(teste));
    printf("%s\n", str_cat(teste, teste2));
    printf("%d\n", str_cmp(teste, teste2));

    return 0;
}