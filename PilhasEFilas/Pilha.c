#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    char caracter;
    struct No *proximo;
}No;

typedef struct Pilha{
    No *topo;
}Pilha;

void inicializarPilha(Pilha *p){
    p->topo = NULL;
}

void empilhar(char ch, Pilha *p){
    No *aux = (No*)malloc(sizeof(No));
    aux->caracter = ch; 
    aux->proximo = p->topo;
    p->topo = aux;
}

char desempilha(Pilha *p){
    No* aux = p->topo;
    char ch;
    p->topo = aux->proximo;
    aux->proximo = NULL;
    ch = aux->caracter;
    free(aux);
    return ch;
}

void imprimirPilha(Pilha *p){
    No *aux = p->topo;
    while (aux != NULL){
        printf("%c ", aux->caracter);
        aux = aux->proximo;
    }
    printf("\n");
}

int pilhaVazia(Pilha *p){
    if (p->topo == NULL){
        return 1;
    }else{
        return 0;
    }
}

int forma_par(char f, char d){
    switch(f){
        case ')':
            if(d == '(')
                return 1; // bem formada
            else
                return 0; // mal formada
            break;
        case ']':
            if(d == '[')
                return 1; // bem formada
            else
                return 0; // mal formada
            break;
        case '}':
            if(d == '{')
                return 1; // bem formada
            else
                return 0; // mal formada
            break;
    }
}

int identifica_formacao(char x[]){
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    inicializarPilha(pilha);
    int i = 0, ok = 0;
    char par;
    while (x[i] != '\0'){
        if (x[i] == '('){
            empilhar('(', pilha);
        }
        if (x[i] == ')'){
            par = desempilha(pilha);
            ok = forma_par(')', par);
        }
        if (x[i] == '['){
            empilhar('[', pilha);
        }
        if (x[i] == ']'){
            par = desempilha(pilha);
            ok = forma_par(']', par);
        }
        if (x[i] == '{'){
            empilhar('{', pilha);
        }
        if (x[i] == '}'){
            par = desempilha(pilha);
            ok = forma_par('}', par);
        }
        i++;
    } if (pilhaVazia(pilha) == 0){
        ok = 0;
    }
    return ok;
}

int main(){
    char exp[50];

    printf("Digite um expressao: ");
    scanf("%49[^\n]", exp);
    printf("\nExpressao: %s\n", exp);
    int resultado = identifica_formacao(exp);
    switch (resultado){
    case 0:
        printf("Resultado: %d, expressao mal formada", resultado);
        break;
    case 1:
        printf("Resultado: %d, expressao bem formada", resultado);
        break;
    }
}
