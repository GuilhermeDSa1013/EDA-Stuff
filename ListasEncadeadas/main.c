//
//Universidade de Brasília - UnB
//Faculdade de Engenharias do Gama - FGA
//Estruturas de Dados e Algoritmos - EDA
//Exercício Prático de Listas Encadeadas
//
//PROBLEMA: Unificação das Listas de Cadastros da Secretaria da Fazenda do Distrito Federal
//
//  main.c
//
//  Created by Nilton Correia da Silva on 01/05/17.
//  Copyright © 2017 Nilton Correia da Silva. All rights reserved.
//
//Aluno:
//Matrícula:
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tipos.h"

//Criar lista Industria a partir do arquivo Industria.txt
TNoI *CriaListaIndustria()
{
    FILE* parq;
    TCadastro pregaux;
    TNoI *plista, *pnovono;
//Montando lista das Industrias:
    
    parq = fopen("Industria.txt", "r");
    if(parq==NULL)
        return NULL;
    
    plista = NULL;
    while(fscanf(parq,"%s %s %s %s", pregaux.CNPJ, pregaux.RazaoSocial, pregaux.Cidade, pregaux.Fone)>0) {
        pnovono = (TNoI *)malloc(sizeof(TNoI));
        pnovono->Dados = (TCadastro *)malloc(sizeof(TCadastro));
        strcpy(pnovono->Dados->CNPJ, pregaux.CNPJ);
        strcpy(pnovono->Dados->RazaoSocial, pregaux.RazaoSocial);
        strcpy(pnovono->Dados->Cidade, pregaux.Cidade);
        strcpy(pnovono->Dados->Fone, pregaux.Fone);
        pnovono->Prox = plista;
        plista = pnovono;
    }

    return plista;
}

//Listar Conteúdo da lista Industria:
void ImprimeIndustria(TNoI *LInd){
    TNoI *plista = LInd;
    printf("                     LISTA DE INDUSTRIAS\n");
    printf("CNPJ            Razao Social                Cidade      Telefone\n");
    while(plista != NULL) {
        printf("%s\t%s\t%s\t%s\n", plista->Dados->CNPJ, plista->Dados->RazaoSocial, plista->Dados->Cidade, plista->Dados->Fone);
        plista = plista->Prox;
    }
}



//Criar lista Comercio a partir do arquivo Comercio.txt
TNoC *CriaListaComercio()
{
    FILE* parq;
    TCadastro pregaux;
    TNoC *plista, *pnovono;
//Montando lista dos Comércios:
    
    parq = fopen("Comercio.txt", "r");
    if(parq==NULL)
        return NULL;
    
    plista = NULL;
    while(fscanf(parq,"%s %s %s %s", pregaux.CNPJ, pregaux.RazaoSocial, pregaux.Cidade, pregaux.Fone)>0) {
        pnovono = (TNoC *)malloc(sizeof(TNoC));
        pnovono->Dados = (TCadastro *)malloc(sizeof(TCadastro));
        strcpy(pnovono->Dados->CNPJ, pregaux.CNPJ);
        strcpy(pnovono->Dados->RazaoSocial, pregaux.RazaoSocial);
        strcpy(pnovono->Dados->Cidade, pregaux.Cidade);
        strcpy(pnovono->Dados->Fone, pregaux.Fone);
        pnovono->Prox = plista;
        plista = pnovono;
    }

    return plista;
}

//Listar Conteúdo da lista Comercio:
void ImprimeComercio(TNoC *LCom){
    TNoC *plista = LCom;
    printf("                     LISTA DE INDUSTRIAS\n");
    printf("CNPJ            Razao Social                Cidade      Telefone\n");
    while(plista != NULL) {
        printf("%s\t%s\t%s\t%s\n", plista->Dados->CNPJ, plista->Dados->RazaoSocial, plista->Dados->Cidade, plista->Dados->Fone);
        plista = plista->Prox;
    }
}

/*
//Criar lista Servico (atualizando o parâmetro por referência pLSer) a partir do arquivo Servico.txt
//Deve retornar 1 caso tenha sucesso. 0 caso contrário
int CriaListaServico(TDescritorS *pLSer)
{
    //Complete o código...
    
    
    
    //######################
}

//Listar Conteúdo da lista Servico:
void ImprimeServico(TDescritorS *pdescritor){
    //Complete o código...
    
    
    //######################
}
 



//Criar lista Unificada (atualizando o parâmetro por referência pUnica) a partir das listas Industria, Comercio e Servico
void CriaListaUnificada(TNoI *pInd, TNoC *pCom, TDescritorS *pServ, TDescritorU *pUnica)
{
    //Complete o código...
    
    
    
    //######################
    
}

*/


//Listar Conteúdo da lista Unificada:
void ImprimeUnificada(TDescritorU *pListaUnica){
    TNoU *plista = pListaUnica->Inicio;
    printf("                     LISTA UNIFICADA\n");
    printf("Tipo    CNPJ            Razao Social                Cidade      Telefone\n");
    while(plista != NULL) {
        printf("%c:\t\t%s\t%s\t%s\t%s\n", plista->Dados->Tipo, plista->Dados->CNPJ, plista->Dados->RazaoSocial, plista->Dados->Cidade, plista->Dados->Fone);
        plista = plista->Prox;
    }
}

//Listar Conteúdo da lista Unificada da calda para a cabeça:
void ImprimeUnificadaInvertida(TDescritorU *pListaUnica){
    TNoU *plista = pListaUnica->Fim;
    printf("                     LISTA UNIFICADA INVERTIDA\n");
    printf("Tipo    CNPJ            Razao Social                Cidade      Telefone\n");
    while(plista != NULL) {
        printf("%c:\t\t%s\t%s\t%s\t%s\n", plista->Dados->Tipo, plista->Dados->CNPJ, plista->Dados->RazaoSocial, plista->Dados->Cidade, plista->Dados->Fone);
        plista = plista->Ant;
    }
}



/*

//Listar Conteúdo da lista Unificada:
void ImprimeUnificada(TDescritorU *pdescritor){
    //Complete o código...
    
    
    //######################
}
 
 
 //Desalocar todas as listas:
void DesalocaListas(TNoI *pInd, TNoC *pCom, TDescritorS *pServ, TDescritorU *pUnica){
 //Complete o código...
 
 
 //######################
 }
 

*/


int main() {
    int continuar=1;
//Listas de entrada
    // Declaração
    TNoI *LIndustria;
    TNoC *LComercio;
    TDescritorS LServico;
    //Inicialização - listas vazias:
    LIndustria = NULL;
    LComercio = NULL;
    LServico.Fim = NULL;
    LServico.Inicio = NULL;
    LServico.Tamanho = 0;
//Lista Unificada
    // Declaração
    TDescritorU LUnica;
    //Inicialização - lista vazia:
    LUnica.Fim = NULL;
    LUnica.Inicio = NULL;
    LUnica.Tamanho = 0;
    
    
    do
    {
        printf("\n\tSecretaria da Fazenda do Distrito Federal");
        printf("\n\tSistema de Unificacao de Cadastro de Contribuintes\n\n");
        printf("1. Carregar Dados de Entrada\n");
        printf("2. Gerar Lista Unificada\n");
        printf("3. Relatorio: Industrias\n");
        printf("4. Relatorio: Comercios\n");
        printf("5. Relatorio: Servicos\n");
        printf("6. Relatorio: Lista Unificada\n");
        printf("7. Relatorio: Lista Unificada Invertida\n");
        printf("0. Sair\n");
        
        scanf("%d", &continuar);
       // system("cls || clear");
        
        switch(continuar)
        {
            case 1:
                if((LIndustria = CriaListaIndustria()))
                    printf("Lista de Industria montada!\n");
                else{
                    printf("Erro na criacao da Lista de Industria!\n");
                    break;
                }

                if((LComercio = CriaListaComercio()))
                    printf("Lista de Comercio montada!\n");
                else{
                    printf("Erro na criacao da Lista de Comercio!\n");
                    break;
                }

                
/* RETIRE O COMENTÁRIO QUANDO CODIFICAR A FUNÇÃO ABAIXO:
                if(CriaListaServico(&LServico))
                    printf("Lista de Servico montada!\n");
                else{
                    printf("Erro na criacao da Lista de Servico!\n");
                }
*/
                break;
                
/* RETIRE O COMENTÁRIO QUANDO CODIFICAR A FUNÇÃO ABAIXO:
            case 2:
                CriaListaUnificada(LIndustria, LComercio, &LServico, &LUnica);
                printf("Lista Unificada montada!\n");
                break;
*/
               
            case 3:
                ImprimeIndustria(LIndustria);
                break;
                

            case 4:
                ImprimeComercio(LComercio);
                break;


                
/* RETIRE O COMENTÁRIO QUANDO CODIFICAR A FUNÇÃO ABAIXO:
            case 5:
                ImprimeServico(&LServico);
                break;
*/
                
            case 6:
                ImprimeUnificada(&LUnica);
                break;
                
            case 7:
                ImprimeUnificadaInvertida(&LUnica);
                break;
                
/* RETIRE O COMENTÁRIO QUANDO CODIFICAR A FUNÇÃO ABAIXO:
            case 0:
                DesalocaListas(LIndustria, LComercio, &LServico, &LUnica);
                break;
*/
                
            default:
                printf("Digite uma opcao valida\n");
        }
    } while(continuar);
    
    return 0;
}
