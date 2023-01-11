#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int ibge;
    char uf[2];
    char municipio[40];
    char regiao[40];
    int populacao;
    char porte[40];
} Linha;


//SelectionSort
int smallerIndex(Linha vet[], int tam, int ini){
    int min = ini, j;
    for(j=ini+1; j<tam; j++){
        if(vet[min].populacao > vet[j].populacao)
            min = j;
        }
    return min;
}

void selectionSort(Linha vet[], int tam){
    int i, min, aux;
    Linha e;
    for(i=0; i<tam; i++){
        e = vet[i];
        min = smallerIndex(vet, tam, i);
        aux = vet[i].populacao;
        e = vet[i];
        vet[i].populacao = vet[min].populacao;
        vet[i] = vet[min];
        vet[min].populacao = aux;
        vet[min] = e; 
    }
}

//InsertionSort
void insertionSort(Linha list[], int n){
    int i, j;
    int next;
    Linha e;
    for (i=1; i<n; i++) {
        next = list[i].populacao;
        e = list[i];
        for (j=i-1; j>=0 && next<list[j].populacao;j--){
            list[j+1].populacao = list[j].populacao;
            list[j+1] = list[j];
        }
        list[j+1].populacao = next;
        list[j+1] = e;
    }
}

//BubbleSort
void bubbleSort(Linha vet[], int tam){
    int i,j, aux;
    Linha e;
    for(i=tam-1; i>0; i--){
        for(j=0; j < i; j++) //Faz trocas até posição i
            if( vet[j].populacao > vet[j+1].populacao ){
            aux = vet[j].populacao;
            e = vet[j];
            vet[j].populacao = vet[j+1].populacao;
            vet[j] = vet[j+1];
            vet[j+1].populacao = aux;
            vet[j+1] = e;
            }
    }
}

//QuickSort
int separa (Linha v[], int p, int r) {
    int c = v[r].populacao; // pivô
    int t, j = p;
    Linha e;
    for (int k = p; k < r; ++k)
        if (v[k].populacao <= c) {
        t = v[j].populacao;
        e = v[j];
        v[j].populacao = v[k].populacao;
        v[j] = v[k];
        v[k].populacao = t;
        v[k] = e;
        ++j;
        }
    t = v[j].populacao;
    e = v[j];
    v[j].populacao = v[r].populacao;
    v[j] = v[r];
    v[r].populacao = t;
    v[r] = e;
    return j;
}

void quicksort (Linha v[], int p, int r){
    if (p < r) {
        int j = separa (v, p, r);
        quicksort (v, p, j-1);
        quicksort (v, j+1, r);
    }
}

/*
void quicksort(Linha vet[], int esq, int dir){
    int pivo = esq, aux, j;
    Linha e;
    for(int i=esq+1;i<=dir;i++){        
        j = i;                      
        if(vet[j].populacao < vet[pivo].populacao){     
            aux = vet[j].populacao;
            e = vet[j];           
            while(j > pivo){           
                vet[j].populacao = vet[j-1].populacao;
                vet[j] = vet[j-1];
                j--;                    
            }
            vet[j].populacao = aux; 
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
*/



main(){
    FILE *fp, *fc;
    Linha l, *a;
    a = (Linha*)malloc(5570*sizeof(Linha));
    int i = 0, qtd = 0;

    fp = fopen("dados.txt", "r");
    if (fp == NULL){
        puts ("Erro na abertura do arquivo!");
        system("pause");
        exit(0);
    }

    fc = fopen("Arquivo de Saida.txt", "w");
    if (fc == NULL){
        puts ("Erro na abertura do arquivo!");
        system("pause");
        exit(0);
    }

    while(1){
        char result;
        result = fscanf(fp, "%d %s %s %s %d %s", &l.ibge, l.uf, l.municipio, l.regiao, &l.populacao, l.porte);
        if (result == EOF)
            break;
        a[i] = l;
        i++;
        qtd++;      
    }

    //selectionSort(a,5570);
    //insertionSort(a, 5570);
    //bubbleSort(a, 5570);
    //quicksort(a, 0, 5569);
    quicksort(v, 0, 9);


    for (int j = 0; j < qtd; j++){
        fprintf(fc, "%d - %s - %s - %s - %d - %s\n", a[j].ibge, a[j].uf, a[j].municipio, a[j].regiao, a[j].populacao, a[j].porte);
    }

    printf("Arquivo gerado com sucesso!!!\n");

    fclose(fp);
    fclose(fc);;
    free(a);

    

}