#include<stdio.h>
#include<stdlib.h>

int* CriarVetInt(int quant){
    int *vet = (int*)calloc(quant, sizeof(int));
    return vet;
}

int EIgual(int *pveta, int *pvetb, int ptama, int ptamb){
    int igual = 0;
    //numero de elementos diferentes
    if (ptama != ptamb)
        return igual;
    
    for (int i = 0; i < ptama; i++){
        if (pveta[i] == pvetb[i])
            igual = 1;
        else
            igual = 0;
    } return igual;
} 

main(){
    printf("Digite o tamanho do primeiro vetor: ");
    int ptama;
    scanf("%d", &ptama);
    int *vA = CriarVetInt(ptama);
    
    printf("Digite o tamanho do segundo vetor: ");
    int ptamb;
    scanf("%d", &ptamb);
    int *vB = CriarVetInt(ptamb);

    vA[0] = 2;
    vA[1] = 1;

    vB[0] = 1;
    vB[1] = 2;

    if(!EIgual(vA, vB, ptama, ptamb))
        printf("Falso, sao diferentes.");
    else
        printf("Verdadeiro, sao iguais.");

    free(vA);
    free(vB);
}