#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char nome [100];
    int idade;
    float altura;
} Pessoa;

//Printar informações da pessoa
void ImprimirDados(Pessoa P){
    printf("Nome: %s.\nIdade: %d.\nAltura: %.2f.\n", P.nome, P.idade, P.altura);
}

//Setar nova Pessoa através de uma função
void SetPessoa(Pessoa *P, char nome[100], int idade, float altura){
    strcpy((*P).nome, nome); //forma para atribuir valores de String
    P->idade = idade;
    P->altura = altura;
}

main(){
    Pessoa P1, P2, P3;
    Pessoa Grupo[4];

    strcpy(P1.nome, "Guilherme de Sá");
    P1.idade = 19;
    P1.altura = 1.80;

    strcpy(Grupo[4].nome, "Ana Karoliny");
    Grupo[4].idade = 20;
    Grupo[4].altura = 1.60;

    P2 = Grupo[4];
    Grupo[0] = P1;

    SetPessoa(&P3, "Tayane Maria", 20, 1.52);

    ImprimirDados(P1);
    ImprimirDados(P2);
    ImprimirDados(P3);
}
