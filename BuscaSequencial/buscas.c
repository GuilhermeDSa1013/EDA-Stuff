#include<stdio.h>
#include<stdlib.h>


//Complexidade O(n)
int buscaSequencialDesordenada(int *V, int n, int chave){
    int p, posic = -1;
    for (p = 0; p < n; p++){
        if(chave == V[p]){
            posic = p;         
        }
    }
    return posic;
}

//Complexidade O(n)
int buscaSequencialOrdenada(int *V, int n, int chave){
    int p = 0, posic = -1;
    while (p < n && chave >= V[p]){
        if (V[p] == chave){
            posic = p;
            break;
        }
        p++;
    }
    return posic;
}

//Complexidade O(log2n)
int buscaBinaria(int *V, int n, int chave){
    int p, inicio, final, meio;
    inicio = 0;
    final = n - 1;
    while(inicio <= final){
        meio = (inicio + final)/2;
        if (chave == V[meio])
            return meio;
        if (chave < V[meio])
            final = meio - 1;//busca nos valores menores
        else
            inicio = meio + 1;//busca nos valores maiores   
    }
    return -1;
}


main(){
    int vet1[5] = {5, 3, 1, 4, 2};
    int pos1 = buscaSequencialDesordenada(vet1, 5, 1);
    printf("%d", pos1);

    int vet2[5] = {1, 2, 3, 4, 5};
    int pos2 = buscaSequencialOrdenada(vet2, 5, 4);
    printf("\n%d", pos2);

    int vet3[5] = {1, 2, 3, 4, 5};
    int pos3 = buscaBinaria(vet3, 5, 5);
    printf("\n%d", pos3);
}