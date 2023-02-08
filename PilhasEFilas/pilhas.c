#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int valor;
    No *prox;
}No;

typedef struct Pilha{
    No *topo;
    int tam;
}Pilha;

void criarPilhaVazia(Pilha *p){
    p->topo = NULL;
    p->tam = 0;
}

void empilhar(Pilha *p, int valor){
    No *novo = malloc(sizeof(No));
    
    if(novo){
        novo->valor = valor;
        novo->prox = p->topo;
        p->topo = novo;
        p->tam++;
    }
    else
        printf("\nErro ao alocar memoria ...\n")
}

No *desempilhar(Pilha *p){
    if(p->topo){
        No *remover = p->topo;
        p->topo = remover->prox;
        p->tam--;
        return remover;
    }else
        printf("\nPilha Vazia\n");
    return NULL;
}

void imprimirPilha(Pilha *p){
    No *aux = p->topo;
    printf("\n-------------------PILHA tam: %d--------------------\n", p->tam);
    while(aux){
        printf("%d - ", aux->valor);
        aux = aux->prox;
    }
    printf("\n----------------------FIM PILHA---------------------\n", p->tam);

}
main(){
    Pilha *p;
    No* remover;
    int opcao;
    

    criarPilhaVazia(p);

    do{
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", opcao);
        

        switch (opcao){
        case 1:
            empilhar(p);
            break;
        case 2:
            remover = desempilhar(p);
            if(remover){
                printf("\nElemento Removido com Sucesso!\n");
                printf("Valor: %d\n", remover->valor);

                free(remover);
            }
        case 3:
            imprimirPilha(p);
        default:
            if(opcao != 0)
                printf("\nOpcao Invalida!\n");   
        }
    } while(opcao != 0);

}