#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int indice;
    int likes;
} LinhaInd;

typedef struct{
    char coment[101];
    int likes;
} Linha;

void ImprimirLinha(Linha vetL[], int vetI[], FILE *f, int qtd){
    for(int i = 0; i < qtd; i++){
        if (vetL[vetI[i]-1].likes < 10)
            fprintf(f, "%d%10s | %s\n", vetL[vetI[i]-1].likes, " ", vetL[vetI[i]-1].coment);   
        if (vetL[vetI[i]-1].likes < 100 && vetL[vetI[i]-1].likes >= 10)
            fprintf(f, "%d%9s | %s\n", vetL[vetI[i]-1].likes, " ", vetL[vetI[i]-1].coment);   
        if (vetL[vetI[i]-1].likes < 1000 && vetL[vetI[i]-1].likes >= 100)
            fprintf(f, "%d%8s | %s\n", vetL[vetI[i]-1].likes, " ", vetL[vetI[i]-1].coment);   
        if (vetL[vetI[i]-1].likes > 1000)
            fprintf(f, "%d%7s | %s\n", vetL[vetI[i]-1].likes, " ", vetL[vetI[i]-1].coment);   
    }
}
void quicksort(LinhaInd vet[], int esq, int dir){
    int pivo = esq, aux, j;
    LinhaInd e;
    for(int i=esq+1;i<=dir;i++){        
        j = i;                      
        if(vet[j].likes > vet[pivo].likes){     
            aux = vet[j].likes;
            e.indice = vet[j].indice;           
            while(j > pivo){           
                vet[j].likes = vet[j-1].likes;
                vet[j].indice = vet[j-1].indice;
                j--;                    
            }
            vet[j].likes = aux; 
            vet[j].indice = e.indice;
            pivo++;                    
        }
    }
    if(pivo-1 >= esq){              
        quicksort(vet,esq,pivo-1);      
    }
    if(pivo+1 <= dir){              
        quicksort(vet,pivo+1,dir);      
    }
}

main(){
    FILE *fp, *fc, *fs; 
    LinhaInd l, *a;
    a = (LinhaInd*)malloc(62000*sizeof(LinhaInd));
    int i = 0, qtd = 0, h = 0, *b;
    b = (int*)malloc(62000*sizeof(int));
    Linha k, *c;
    c = (Linha*)malloc(62000*sizeof(Linha));
    

    //Abrindo arquivo dos dados
    fp = fopen("teste.txt", "r");
    if (fp == NULL){
        puts ("Erro na abertura do arquivo!");
        system("pause");
        exit(0);
    }

    fs = fopen("teste2.txt", "r");
    if (fs == NULL){
        puts ("Erro na abertura do arquivo!");
        system("pause");
        exit(0);
    }

    //Criando arquivo de saída
    fc = fopen("Arquivo de saida.txt", "w");
    if (fc == NULL){
        puts ("Erro na abertura do arquivo!");
        system("pause");
        exit(0);
    }
    
    //Percorrendo o arquivo
    while(1){
        char result;
        result = fscanf(fp, "%d %d", &l.indice, &l.likes);
        
        if (result == EOF)
            break;
        if(l.likes != 0){
            a[i] = l;
            i++;
            qtd++;
        }     
        
    }
    while(1){
        char coment;
        int likes;
        coment = fscanf(fs, "%100s", k.coment);
        likes = fscanf(fs, "%d", &k.likes);
        
        if (likes == EOF)
            break;
        c[h] = k;
        h++;
        
    }

    quicksort(a, 0, qtd-1);

    for (int j = 0; j < qtd; j++)
        b[j] = a[j].indice;

    fprintf(fc," Quantidade | Comentario\n");
    ImprimirLinha(c, b, fc, qtd);
    
    printf("Arquivo gerado com sucesso!!!\n");

    fclose(fp);
    fclose(fc);
    fclose(fs);
    free(a);
    free(b);
    free(c);

}