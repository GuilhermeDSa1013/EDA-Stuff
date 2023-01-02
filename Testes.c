#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char comment[1000];
    int likes;
} Linha;

void quicksort(Linha vet[], int esq, int dir){
    int pivo = esq, aux, j;
    Linha e;
    for(int i=esq+1;i<=dir;i++){        
        j = i;                      
        if(vet[j].likes < vet[pivo].likes){     
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

/*
void quicksortInt(int vet[], int esq, int dir){
    int pivo = esq, aux, j;
    for(int i=esq+1;i<=dir;i++){        
        j = i;                      
        if(vet[j] > vet[pivo]){     
            aux = vet[j];           
            while(j > pivo){         
                vet[j] = vet[j-1];
                j--;        
            }
            vet[j] = aux; 
            pivo++;              
        }
    }
    if(pivo-1 >= esq){              
        quicksortInt(vet,esq,pivo-1);      
    }
    if(pivo+1 <= dir){              
        quicksortInt(vet,pivo+1,dir);      
    }
}
*/

main(){
    FILE *fp, *fc;
    Linha l, a[10];
    int i = 0;
    fp = fopen("teste.txt", "r");

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

        result = fscanf(fp, "%s %d", l.comment, &l.likes);
        a[i] = l;
        if (result == EOF)
            break;
        i++;
    }
    
    quicksort(a, 0, 10);
    fprintf(fc, "Comentario | Quantidade\n");
    for(int j = 0; j < 10; j++){
        fprintf(fc, "%s | %d\n", a[j].comment, a[j].likes);
    }

    printf("Arquivo gerado com sucesso!!!");

    fclose(fp);
    fclose(fc);
    

    /*
    int vetor[10] = {4, 7, 6, 8, 2, 1, 0, 9, 5, 3};
    quicksortInt(vetor, 0, 10);
   
    for(int i = 0; i<10; i++)
        printf("%d ", vetor[i]);
    */
}
