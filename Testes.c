#include<stdio.h>
#include<stdlib.h>

//Definindo uma Struct que conterá os valores de cada linha do arquivo
typedef struct{
    char comment[101];
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
    Linha l, *a, *b;
    a = (Linha*)malloc(62000*sizeof(Linha));
    int i = 0, k = 0, qtd = 0, qtd0 = 0;
    b = (Linha*)malloc(62000*sizeof(Linha));

    //Abrindo arquivo dos dados
    fp = fopen("teste2.txt", "r");
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
        char coment;
        int likes;
        likes = fscanf(fp, "%d", &l.likes);
        coment = fscanf(fp, "%100s", l.comment);

        if (coment == EOF)
            break;    
        if(l.likes != 0){
            a[i] = l;
            i++;
            qtd++;  
        }
        
        if(l.likes == 0){
            b[k] = l;
            k++;
            qtd0++;
        }
        
    }
    
    //Aplicando QuickSort
    quicksort(a, 0, qtd-1);

    //Gravando informações no arquivo de saída
    fprintf(fc, "Quantidade | Comentario\n");
    for(int j = 0; j < qtd; j++){
        if (a[j].likes < 10)
            fprintf(fc, "%d%10s| %s\n", a[j].likes, " ", a[j].comment);   
        if (a[j].likes < 100 && a[j].likes >= 10)
            fprintf(fc, "%d%9s| %s\n", a[j].likes, " ", a[j].comment);   
        if (a[j].likes < 1000 && a[j].likes >= 100)
            fprintf(fc, "%d%8s| %s\n", a[j].likes, " ", a[j].comment);   
        if (a[j].likes > 1000)
            fprintf(fc, "%d%7s| %s\n", a[j].likes, " ", a[j].comment);
    }
       
    
    for(int z = 0; z < qtd0; z++){
        fprintf(fc, "%d%11s| %s\n", b[z].likes, " ", b[z].comment);
    }
    
    printf("Arquivo gerado com sucesso!!!\n");

    fclose(fp);
    fclose(fc);
    free(a);
    free(b);
}
