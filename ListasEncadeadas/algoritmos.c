#include<stdio.h>
#include<stdlib.h>

typedef struct TNo{
    int numero;
    TNo *prox;
}TNo;

typedef struct TLista{
    TNo *primeiro;
    int qtd;
    TNo *ultimo;
}TLista;

//Ver se a lista está vazia
bool listaVazia(TNo *pLista){
    if (pLista == NULL)
        return true;
    else
        return false;
}

//Inclusão na Cabeça O(1)
TNo *IncluiCabeca(TNo *pLista, int pValor){
    TNo *pNovo;
    pNovo = (TNo*)malloc(sizeof(TNo));
    pNovo->numero = pValor;
    pNovo->prox = pLista;
    pLista = pNovo;
    return pLista;
}

//Inclusão na Calda O(n)
TNo *IncluiCalda(TNo *pLista, int pValor){
    TNo *pNovoNo, *pAux;
    pNovoNo = (TNo *) malloc(sizeof(TNo));
    pNovoNo->Numero = pValor;
    pNovoNo->Prox = NULL;
    pAux = pLista;
    while (pAux->Prox != NULL)
        pAux = pAux->Prox;
    pAux->Prox = pNovoNo;
    return pLista;
}

//Inclusão antes de uma chave O(n)
TNo *IncluiAntes(TNo *pLista, int pChave, int pValor){
    TNo *pNovoNo, *pAux;
    pNovoNo = (TNo *) malloc(sizeof(TNo));
    pNovoNo->Numero = pValor;
    pAux = pLista;
    while (pAux->Prox->Valor != pChave)
        pAux = pAux->Prox;
    pNovoNo->Prox = pAux->Prox;
    pAux->Prox = pNovoNo;
    return pLista;
}

//Exclusão na Cabeça O(1)
TNo *ExcluiCabeca(TNo *pLista){
    TNo *pAux;
    pAux = pLista;
    pLista = pLista->Prox;
    free(pAux);
    return pLista;
}

//Exclusão na Calda O(n)
TNo *ExcluiCalda(TNo *pLista){
    TNo *pAux;
    pAux = pLista;
    while (pAux->Prox->Prox != NULL)
        pAux = pAux->Prox;
    free(pAux->Prox);
    pAux->Prox = NULL;
    return pLista;
}

//Exclusão de uma Chave O(n)
TNo *ExcluiChave(TNo *pLista, int pChave){
    TNo *pAnt, *pPost;
    pAnt = pLista;
    while (pAnt->Prox->Numero != pChave)
        pAnt = pAnt->Prox;
    pPost = pAnt->Prox->Prox;
    free(pAnt->Prox);
    pAnt->Prox = pPost ;
    return pLista;
}