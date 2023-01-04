#include<stdio.h>
#include<stdlib.h>

//Definindo uma Struct que conterá os valores de cada linha do arquivo
typedef struct{
    char comment[2000];
    int likes;
} Linha;

//Código de ordenação QuickSort(Decrescente)
void quicksort(Linha vet[], int esq, int dir){
    int pivo = esq, aux, j;
    Linha e;
    for(int i=esq+1;i<=dir;i++){        
        j = i;                      
        if(vet[j].likes > vet[pivo].likes){     
            aux = vet[j].likes;
            e = vet[j];           
            while(j > pivo){           
                vet[j].likes = vet[j-1].likes;
                vet[j] = vet[j-1];
                j--;                    
            }
            vet[j].likes = aux; 
            vet[j] = e;
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
    FILE *fp, *fc; 
    Linha l, *a;
    a = (Linha*)malloc(62000*sizeof(Linha));
    int i = 0, qtd = 0;

    //Abrindo arquivo dos dados
    fp = fopen("teste.txt", "r");
    if (fp == NULL){
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
        char coment, ch;
        int likes;
        coment = fscanf(fp, "%s", l.comment);
        likes = fscanf(fp, "%d", &l.likes);

        if (likes == EOF)
            break;    

        a[i] = l;
        i++;
        qtd++; 
        
    }
    
    //Aplicando QuickSort
    quicksort(a, 0, qtd-1);

    //Gravando informações no arquivo de saída
    fprintf(fc, "Quantidade | Comentario\n");
    for(int j = 0; j < qtd; j++){
        if (a[j].likes < 10)
            fprintf(fc, "%d%10s| %s\n", a[j].likes, " ", a[j].comment);
        if (a[j].likes >= 10 && a[j].likes < 100)
            fprintf(fc, "%d%9s| %s\n", a[j].likes, " ", a[j].comment);
        if (a[j].likes >= 100 && a[j].likes < 1000)
            fprintf(fc, "%d%8s| %s\n", a[j].likes, " ", a[j].comment);
        if (a[j].likes >= 1000)
            fprintf(fc, "%d%7s| %s\n", a[j].likes, " ", a[j].comment);
    }

    printf("Arquivo gerado com sucesso!!!\n");

    fclose(fp);
    fclose(fc);
    free(a);
}
