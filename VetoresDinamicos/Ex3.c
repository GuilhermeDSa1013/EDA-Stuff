#include<stdio.h>
#include<stdlib.h>

char* CriarVetChar(int quant){
    char *vet = (char*)calloc(quant, sizeof(char));
    return vet;
}

void ImprimirVetChar(char* vet, int tamanho, int quant){
    for (int i = 0; i < tamanho; i++){
        if (vet[i] != 0)
            quant++;
    }
    if (quant == 0)
        printf("\nNao ha elementos no vetor.");
    else{
        printf("\nVetor: ");
        for (int i = 0; i < tamanho; i++){
            printf("%c ", vet[i]);
        }
    }
    printf("\nQuantidade de elementos: %d", quant);
    printf("\nTamanho do vetor: %d\n", tamanho);
}

void AdicionarChar(char* vet, int tamanho, int quant, char caracter){
    for (int i = 0; i < tamanho; i++){
        if (vet[i] != 0)
            quant++;
    }
    for (int i = 0; i < tamanho; i++){
        if (vet[i] == 0){
            vet[i] = caracter;
            quant++;
            break;
        }
    }
}

void ExcluirChar(char* vet, int tamanho, int quant, char caracter){
    for (int i = 0; i < tamanho; i++){
        if (vet[i] != 0)
            quant++;
    }
    for (int i = 0; i < tamanho; i++){
        if (vet[i] == caracter){
            vet[i] = 0;
            quant--;
            break;
        }
    }
}

main(){
    printf("Digite o tamanho do vetor: ");
    int ptammax, pqtde = 0, op, cA, cE;
    scanf("%d", &ptammax);
    char *pvetcar = CriarVetChar(ptammax);
    
    do{
        ImprimirVetChar(pvetcar, ptammax, pqtde);
        printf("\n1 - Adicionar\n2 - Excluir\n3 - Sair\nOpcao: ");
        scanf("%d", &op);

        if (op == 1){
            printf("\nElemento a inserir: ");
            scanf(" %c", &cA);
            AdicionarChar(pvetcar, ptammax, pqtde, cA);
        }

        if (op == 2){
            printf("\nElemento a excluir: ");
            scanf(" %c", &cE);
            ExcluirChar(pvetcar, ptammax, pqtde, cE);
        }
    } while (op != 3);

    free(pvetcar);
    system("pause");

}