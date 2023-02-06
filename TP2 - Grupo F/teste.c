#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NoA{
    int valor;
    struct NoA *E;
    struct NoA *D;
} NoA;

NoA *InserirNo(NoA *A, int num){
    if(A == NULL){
        NoA *aux = malloc(sizeof(NoA));
        aux->valor = num;
        aux->E = NULL;
        aux->D = NULL;
        return aux;
    }else{
        if(num < A->valor)
            A->E = InserirNo(A->E, num);
        else
            A->D - InserirNo(A->D, num);
        return A;
    }
}

void imprimirArvore(NoA *A){
    if(A){
        printf("%d ", A->valor);
        imprimirArvore(A->E);
        imprimirArvore(A->D);
    }
}
 
main(){
    char p1[50] = {"USA 2020-02-07"};
    char p2[50] = {"USA 2020-08-08"};

    printf("%d", strcmp(p1,p2));
}
