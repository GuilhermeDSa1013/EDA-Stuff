#include<stdio.h>
main(){
    FILE *fOriginal, *fCopia;
    char ch;
    fOriginal = fopen("teste.txt", "r");
    
    if (fOriginal == NULL){
        puts ("Nao foi possivel abrir o arquivo!!!");
        exit(0);
    }

    fCopia = fopen("testeCopia.txt", "w");

    if (fCopia == NULL){
        puts ("Nao foi possivel gravar o arquivo!!!");
        exit(0);
    }

    while(1){
        ch = fgetc(fOriginal);
        if (ch == EOF)
            break;
        fputc (ch, fCopia);
    }

    fclose(fOriginal);
    fclose(fCopia);
    return 0;
}