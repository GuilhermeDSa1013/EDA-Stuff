#include<stdio.h>
main(){
    FILE *fp;
    char ch;
    int numeroDeCaracteres;
    int numeroDeEspacos;
    int numeroDeTabs;
    int numeroDeLinhas;

    fp = fopen("teste.txt", "r");

    if(fp == NULL){
        printf("Unable to open file.\n");
        system("pause");
        exit(0);
    }

    numeroDeCaracteres = 0;
    numeroDeEspacos = 0;
    numeroDeTabs = 0;
    numeroDeLinhas = 0;

    while(1){
        ch = fgetc(fp);
        if (ch == EOF)
            break;

        if (ch == ' ')
            numeroDeEspacos++;
        if (ch == '\n')
            numeroDeLinhas++;
        if (ch == '\t')
            numeroDeTabs++;
        
        numeroDeCaracteres++;
        
        printf("%c", ch);
    }
    numeroDeLinhas++;
    fclose(fp);
    printf("\nNesse texto tem %d caractere(s).\nTendo %d espaco(s), %d tab(s) e %d linha(s).", numeroDeCaracteres, numeroDeEspacos, numeroDeTabs, numeroDeLinhas);
}