#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int indice;
    int likes;
} Linha;

void quicksort(Linha vet[], int esq, int dir){
    int pivo = esq, aux, j;
    Linha e;
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
    Linha l, *a;
    a = (Linha*)malloc(45505*sizeof(Linha));
    int i = 0, qtd = 0, *b;
    b = (int*)malloc(45505*sizeof(int));
    

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
        int ind;
        result = fscanf(fp, "%d %d", &l.indice, &l.likes);

        if (result == EOF)
            break;     

        ind = l.indice;
        a[i] = l;
        b[i] = ind;
        i++;
        qtd++;

    }

    quicksort(a, 0, qtd-1);
    fprintf(fc, "Quantidade | Indice\n");

    for(int j = 0; j < qtd; j++){
        if (a[j].likes < 10)
            fprintf(fc, "%d%10s| %d\n", a[j].likes, " ", a[j].indice);
        if (a[j].likes >= 10 && a[j].likes < 100)
            fprintf(fc, "%d%9s| %d\n", a[j].likes, " ", a[j].indice);
        if (a[j].likes >= 100 && a[j].likes < 1000)
            fprintf(fc, "%d%8s| %d\n", a[j].likes, " ", a[j].indice);
        if (a[j].likes >= 1000)
            fprintf(fc, "%d%7s| %d\n", a[j].likes, " ", a[j].indice);
    }

    printf("Arquivo gerado com sucesso!!!\n");

    fclose(fp);
    fclose(fc);
    free(a);
    free(b);
}