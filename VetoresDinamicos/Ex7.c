#include<stdio.h>
#include<stdlib.h>

float* CriarVetFloat(int quant){
    int *vet = (float*)calloc(quant, sizeof(float));
    return vet;
}

void AdicionarValor(float* vet, int tamanho, int quant, int valor){
    for (int i = 0; i < tamanho; i++){
        if (vet[i] != 0)
            quant++;
    }
    for (int i = 0; i < tamanho; i++){
        if (vet[i] == 0){
            vet[i] = valor;
            quant++;
            break;
        }
    }
}
void ImprimirVetValores(float* vet, int tamanho, int quant){
    for (int i = 0; i < tamanho; i++){
        if (vet[i] != 0)
            quant++;
    }
    if (quant == 0)
        printf("\nNao ha elementos no vetor.");
    else{
        printf("\nVetor: ");
        for (int i = 0; i < tamanho; i++){
            printf("%.2f ", vet[i]);
        }
    }
}
float Serie(float* vet, int final){
    float soma = 0.0, den;
    int num, i;
    for(i = 1; i <= final; i++){
        num = i;
        den = vet[i - 1];
        soma = soma + (float)num/den;
    }
    printf("Valor da serie: %.2f\n", soma);
}

void Termos(float* vet, int final){
    float den;
    int num, i, termos = 0;
    for(i = 1; i <= final; i++){
        num = i;
        den = vet[i - 1];
        if (num < den){
            printf("%d < %.2f\n", num, den);
            termos++;
        }
    }
    printf("Termos da serie, em que o numerador e menor que o denominador: %d\n", termos);
}

main(){
    printf("Informe o valor de n: ");
    int n;
    scanf("%d", &n);
    float *v = CriarVetFloat(n);
    int quant = 0, op, valor;

    do{
        ImprimirVetValores(v, n, quant);
        printf("\n1 - Adcionar elemento\n2 - Calcular e exibir o valor da Serie\n3 - Calcular e exibir quantos termos da serie tem numerador menor que o denominador\n4 - Sair\n");
        scanf("%d", &op);

        if (op == 1){
            printf("\nDigite o valor a inserir: ");
            scanf("%d", &valor);
            AdicionarValor(v, n, quant, valor);
        }

        if (op == 2){
            Serie(v, n);
        }

        if (op == 3){
            Termos(v, n);
        }
    } while (op != 4);

    system("pause");

    
}