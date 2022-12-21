#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char nome[100];
    int idade;
} Pessoa;

main(){
    printf(sizeof(Pessoa));
    
}