//
//Universidade de Brasília - UnB
//Faculdade de Engenharias do Gama - FGA
//Estruturas de Dados e Algoritmos - EDA
//Exercício Prático de Listas Encadeadas
//
//PROBLEMA: Unificação das Listas de Cadastros da Secretaria da Fazenda do Distrito Federal
//
//  Tipos.h
//
//  TDAs para programa de Listas de Cadastros
//
//  Created by Nilton Correia da Silva on 01/05/17.
//  Copyright © 2017 Nilton Correia da Silva. All rights reserved.
//

#ifndef Tipos_h
#define Tipos_h

//Dados de cadastros das empresas:

typedef struct Cadastro {
    char CNPJ[15];
    char RazaoSocial[50];
    char Cidade[30];
    char Fone[12];
} TCadastro;

//Nó da lista simplesmente encadeada (Indústria):

typedef struct NoI {
    TCadastro *Dados;
    struct NoI *Prox;
} TNoI;

//Nó da lista duplamente encadeada circular (Comércio):

typedef struct NoC {
    TCadastro *Dados;
    struct NoC *Ant;
    struct NoC *Prox;
} TNoC;

//Nó da lista duplamente encadeada com descritor (Empresas de Serviços):

typedef struct NoS {
    TCadastro *Dados;
    struct NoS *Ant;
    struct NoS *Prox;
} TNoS;

typedef struct DescritorS {
    TNoS *Inicio;
    int Tamanho;
    TNoS *Fim;
} TDescritorS;

//Dados de cadastros da lista unificada:

typedef struct CadastroU {
    char CNPJ[15];
    char RazaoSocial[50];
    char Cidade[30];
    char Fone[12];
    char Tipo;
} TCadastroU;

typedef struct NoU {
    TCadastroU *Dados;
    struct NoU *Ant;
    struct NoU *Prox;
} TNoU;

typedef struct DescritorU {
    TNoU *Inicio;
    int Tamanho;
    TNoU *Fim;
} TDescritorU;


#endif /* Tipos_h */
