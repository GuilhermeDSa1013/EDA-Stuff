#include<stdio.h>
#include<stdlib.h>

int* CriarVetInt(int quant){
    int *vet = (int*)calloc(quant, sizeof(int));
    return vet;
}

int AdicionarValor(int* vet, int tamanho, int* quant, int valor){
    //Se o vetor estiver cheio
    int i, j;
    if (*quant == tamanho) return 0;

    //Se n tiver nenhum elemento no vetor
    if (*quant == 0){
        vet[0] = valor;
        (*quant)++;
        return 1;
    }

    //Percorrer o vetor aré achar o primeiro > q o valor
    for(i = 0; i < (*quant);i++){
        if(vet[i] > valor)
            break;
    }

    //Descola todos os numeros maiores q o valor para a direita
    for(j = (*quant); j > i; j--)
          vet[j] = vet[j-1];

    vet[i] = valor;
    (*quant)++;
    printf("Quantidade de elementos atuais: %d\n", *quant);
    return 1;
}

int ExcluirValor(int* vet, int tamanho, int* quant, int valor){
    int encontrou = 0; //Sinaliza se o valor está no vetor
    int p, t;

    //Procura o valor no vetor, no final, p fica com ovalor da posição do valor
    for (p = 0; p < (*quant); p++){
        if(vet[p] == valor){
            encontrou = 1;
            break;
        }
    }

    //Se o valor ainda n tiver sido encontrado, é poq ou o vaolr n está no vetor, ou o vetor está vazio
    if(!encontrou) return 0;

    //Move todos os valores para a esquerda, diminuindo a quantidade de elementos, sem excluir de fato o valor
    for(t = p + 1; t < (*quant); t++){
        vet[t - 1] = vet[t];
    }
    (*quant)--;
    printf("Quantidade de elementos atuais: %d\n", *quant);
    return 1;
}

void ImprimirVetValores(int* vet, int tamanho, int quant){
    if (quant == 0)
        printf("Nao ha elementos no vetor.");
    else{
        printf("Vetor: ");
        for (int i = 0; i < tamanho; i++){
            printf("%d ", vet[i]);
        }
    }
}

main(){
    printf("Digite o tamanho do vetor: ");
    int pcapacidade;
    scanf("%d", &pcapacidade);
    int *pvalores = CriarVetInt(pcapacidade);
    int ptamanho = 0, pv, op;
    
    do{
        ImprimirVetValores(pvalores, pcapacidade, ptamanho);
        printf("\n1 - Adicionar\n2 - Excluir\n3 - Sair\nOpcao: ");
        scanf("%d", &op);

        if(op == 1){
            printf("\nElemento a inserir: ");
            scanf("%d", &pv);
            
            if(!AdicionarValor(pvalores, pcapacidade, &ptamanho ,pv))
                printf("\nCapacidade esgotada.\n");
        }

        if(op == 2){
            printf("\nElemento a excluir: ");
            scanf("%d", &pv);
            
            if(!ExcluirValor(pvalores, pcapacidade, &ptamanho ,pv))
                printf("\nVetor vazio ou não existente\n");
        }

    } while(op != 3);

    free(pvalores);
    system("pause");
}