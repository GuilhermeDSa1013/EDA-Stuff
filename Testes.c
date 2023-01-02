#include<stdio.h>
#include<stdlib.h>

//Definindo uma Struct que conterá os valores de cada linha do arquivo
typedef struct{
    char comment[1000];
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
    Linha l, a[1088];
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
        char result;
        result = fscanf(fp, "%s %d", l.comment, &l.likes);
        a[i] = l;
        if (result == EOF)
            break;
        i++;
        qtd++;
    }
    
    //Aplicando QuickSort
    quicksort(a, 0, qtd-1);

    //Gravando informações no arquivo de saída
    fprintf(fc, "Comentario | Quantidade\n");
    for(int j = 0; j < qtd; j++){
        fprintf(fc, "%s | %d\n", a[j].comment, a[j].likes);
    }

    printf("Arquivo gerado com sucesso!!!\n");

    fclose(fp);
    fclose(fc);
}
