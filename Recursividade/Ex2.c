#include<stdio.h>

//Função recursiva que retorne a soma dos elementos de um vetor
long int SomaVet(int a[], int qtde){
    if (qtde == 0)
        return 0;
    else
        return(a[qtde - 1] + SomaVet(a, qtde - 1));
}

//Função recursiva que verifique se duas strings são iguais
int StringIgual(char a[], char b[]){
    if (a[0] == '\0' && b[0] == '\0')
        return 1;
    if (a[0] == b[0])
        return (StringIgual(&a[1], &b[1]));
    else
        return 0;
}

//Função recursiva para calcular o n-ésimo termo de Fibonacci
int Fibonacci(int n){
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n > 1)
        return(Fibonacci(n - 1) + Fibonacci(n - 2));
}

main(){

    /*
    //Teste da função SomaVet
    int vet[] = {1, 2, 3};
    printf("Soma: %d", SomaVet(vet, 3));
    */

    /*
    //Teste da função StringIgual
    printf("Digite a primeira frase: ");
    char a[100];
    scanf("%s", a);
    printf("Digite a segunda frase: ");
    char b[100];
    scanf("%s", b);
    if (StringIgual(a, b))
        printf("Sao iguais");
    else
        printf("Sao diferentes");
    */

    /*
    //Teste da função Fibonacci
    printf("Digite o n-enesimo termo que quer encontrar: ");
    int termo;
    scanf("%d", &termo);
    printf("Termo de posicao %d na sequencia de Fibonacci: %d", termo, Fibonacci(termo));
    */
}

