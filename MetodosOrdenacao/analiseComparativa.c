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
        vet[i].populacao = vet[min].populacao;
        vet[min].populacao = aux;
        e = vet[min];
    }
}

//InsertionSort
void insertionSort(int list[], int n){
    int i, j;
    int next;
    for (i=1; i<n; i++) {
        next= list[i];
        for (j=i-1; j>=0&&next<list[j];j--)
            list[j+1] = list[j];
        list[j+1] = next;
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
            vet[j].populacao = vet[j+1].populacao;
            vet[j+1].populacao = aux;
            vet[j+1] = e;
            }
    }
}

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

    fc = fopen("Arquivo de saida.txt", "w");
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

    bubbleSort(a, 5570);
    for (int j = 0; j < qtd; j++){
        fprintf(fc, "%d - %s - %s - %s - %d - %s\n", a[j].ibge, a[j].uf, a[j].municipio, a[j].regiao, a[j].populacao, a[j].porte);
    }

    printf("Arquivo gerado com sucesso!!!\n");

    fclose(fp);
    fclose(fc);
    free(a);

    

}