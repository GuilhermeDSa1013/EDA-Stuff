#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char nomeArquivo[40];
    char nomeArcVoc[40];
    char txt[50] = ".txt";
    char voc[50] = "_Vocabulo.txt";

    printf("Digite o nome de um arquivo:\n");
    scanf("%s", nomeArquivo);

    for(int i = 0; i < 40 ;i++){
        nomeArcVoc[i] = nomeArquivo[i];
    }

    FILE *fOriginal, *fCopia, *fVoc;
    char ch, word[100], *c;

    strcat(nomeArquivo, txt);
    fOriginal = fopen(nomeArquivo, "r");
    if (fOriginal == NULL){
        puts ("Nao foi possivel abrir o arquivo!!!");
        exit(0);
    }

    fCopia = fopen("copia.txt", "w");
    if (fCopia == NULL){
        puts ("Nao foi possivel gravar o arquivo!!!");
        exit(0);
    }

    strcat(nomeArcVoc, voc);
    fVoc = fopen(nomeArcVoc, "w");
    if (fVoc == NULL){
        puts ("Nao foi possivel gravar o arquivo!!!");
        exit(0);
    }

    while(fscanf(fOriginal, "%s", word) != NULL){
        int tamWord = strlen(word);
        ch = fgetc(fOriginal);
        if (tamWord > 4){
                fputs(word, fCopia);
                fputs("\n", fCopia);
        }
        if (ch == EOF)
            break;  
    }

    fclose(fOriginal);
    fclose(fCopia);
    fclose(fVoc);
    return 0;
}
