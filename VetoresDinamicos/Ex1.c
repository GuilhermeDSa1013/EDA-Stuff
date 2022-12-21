#include<stdio.h>
#include<stdlib.h>

int* CriaVetInt(int quant){
    int *vet = (int*)calloc(quant, sizeof(int));
    return vet;
}

float* CriaVetFloat(int quant){
    float *vet = (float*)malloc(quant * sizeof(float));
    return vet;
}

main(){

    int quant, opcao, *V1, escolha;
    float *V2;
    
    printf("Digite a quantidade de elementos do seu vetor: ");
    scanf("%d", &quant);
    printf("Digite o tipo do vetor, Inteiro (1) ou Float (2) ou saia (3): ");
    scanf("%d", &opcao);
    
    switch (opcao)
    {
    case 1:
        V1 = CriaVetInt(quant);
        printf("Digite os valores do vetor: ");
        for (int i = 0; i < quant; i++)
            scanf("%d", &V1[i]);
        printf("Vetor: ");
        for (int i = 0; i < quant; i++)
            printf("%d ", V1[i]);
        free(V1);
        break;
    case 2:
        V2 = CriaVetFloat(quant);
        printf("Digite os valores do vetor: ");
        for (int i = 0; i < quant; i++)
            scanf("%f", &V2[i]);
        printf("Vetor: ");
        for (int i = 0; i < quant; i++)
            printf("%.2f ", V2[i]);
        free(V2);
        break;
    case 3:
        escolha = 2;
        break;
    default:
        printf("Escolha uma opcao valida!\n");
        break;
    }
}
