#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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

//Função para ler os primeiros 100 caracteres do comentário de cada linha
void ler_comentario(FILE *fp, char *buffer){
    char car;
    int pqtdelidos;
    pqtdelidos = fscanf(fp, "%*[;]%100s", buffer);
    while(car != '\n'){
        car = fgetc(fp);
        if (car == EOF)
            break;
    }
}

main(){
    FILE *fp, *fc; 
    Linha l, *a, *b;
    //Vetor q conterá as linhas com likes
    a = (Linha*)malloc(62000*sizeof(Linha));
    //Vetor q conterá as linhas com 0 likes
    b = (Linha*)malloc(62000*sizeof(Linha));
    //Indices dos vetores de linha
    int i = 0, k = 0;
    //Variáveis q terão o número de linhas de cada vetor
    int qtd = 0, qtd0 = 0;

    //Variáveis q serão utilizadas para medir o tempo de processamento do QuickSort
    float tempo;
    time_t tIni, tFim;

    //Abrindo arquivo dos dados
    fp = fopen("Dados.csv", "r");
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
        int likes;
        likes = fscanf(fp, "%d", &l.likes); //Lendo o like de cada linha
        
        ler_comentario(fp, l.comment);

        if(likes == EOF){
            break;
        }
        //Adicionando linhas no vetor a
        if(l.likes != 0){
            a[i] = l;
            i++;
            qtd++;  
        }
        //Adicionando linhas no vetor b
        if(l.likes == 0){
            b[k] = l;
            k++;
            qtd0++;
        }
    }
    
    //Aplicando QuickSort
    tIni = time(NULL);
    quicksort(a, 0, qtd-1);
    tFim = time(NULL);

    //Calculando tempo de processamento
    tempo = difftime(tFim, tIni);

    //Gravando informações no arquivo de saída
    fprintf(fc, "Quantidade | Comentario\n");

    //Manter a mesma indentação 
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
       
    //Gravando linhas com 0 likes
    for(int j = 0; j < qtd0; j++){
        fprintf(fc, "%d%10s| %s\n", b[j].likes, " ", b[j].comment);
    }
    
    //Printando outras informações
    printf("Arquivo gerado com sucesso!!!\n");
    printf("Tempo de Processamento do QuickSort: %fs\n", tempo);
    printf("Analise de complexidade do QuickSort: O(N.log(N))");

    //Fechando arquivos
    fclose(fp);
    fclose(fc);

    //Desalocando vetores
    free(a);
    free(b);
}
