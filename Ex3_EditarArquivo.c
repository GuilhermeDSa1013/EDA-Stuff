#include<stdio.h>
main(){
    FILE *fp;
    char s[80];
    /*Para escrever um arquivo do zero, usar "w"
    Para adicionar novas linhas em um arquivo já escrito, usar "a"*/
    
    fp = fopen("Poem.txt", "w");

    if(fp == NULL){
        printf("Unable to open file.\n");
        system("pause");
        exit(0);
    }

    printf("\nEscreva algumas linhas de texto.\n");

    while( strlen(gets(s)) > 0){
        fputs(s, fp);
        fputs("\n", fp);
    }

    fclose(fp);
    system("pause");
}