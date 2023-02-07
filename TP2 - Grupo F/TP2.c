#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NoA{
    int linha;
    char chave[50];
    struct NoA *E;
    struct NoA *D;
} NoA;

typedef struct Registro{
    int linha;
    char dados[2000];
}Registro;

NoA *InserirNo(NoA *A, int linha, char chave[50]){
    if(A == NULL){
        NoA *aux = malloc(sizeof(NoA));
        aux->linha = linha;
        strcpy(aux->chave, chave);
        aux->E = NULL;
        aux->D = NULL;
        return aux;
    }else{
        if(strcmp(chave, A->chave) == -1)
            A->E = InserirNo(A->E, linha, chave);
        else
            A->D = InserirNo(A->D, linha, chave);
        return A;
    }
}

void ler_dados(FILE *fp, char *buffer){
    char ch;
    int pqtdelidos;
    pqtdelidos = fscanf(fp, "%*[;]%s", buffer);
    while(ch != '\n'){
        ch = fgetc(fp);
        if (ch == EOF)
            break;
    }
}

Registro *criarListaDados(FILE *arquivo, Registro *vet){
    int indVet = 0;
    Registro l;
    while(1){
        int linha;
        linha = fscanf(arquivo, "%d", &l.linha);
        ler_dados(arquivo, l.dados);
        
        if(linha == EOF){
            break;
        }

        vet[indVet] = l;
        indVet++;
    }
    return vet;
}

void imprimirArvore(FILE *arquivo, NoA *A){
    if(A){
        imprimirArvore(arquivo, A->E);
        if(A->linha < 10)
            fprintf(arquivo, "Linha: %d |Chave: %s\n", A->linha, A->chave);
        if(A->linha > 10)
            fprintf(arquivo, "Linha: %d|Chave: %s\n", A->linha, A->chave);
        imprimirArvore(arquivo, A->D);
    }
}

void FreeArvore(NoA *A){
    if (A != NULL){
        FreeArvore(A->E);
        FreeArvore(A->D);
        free(A);
    }  
}

int contar_linhas(FILE *fp){
    int qtdLinhas = 0;
    char ch;
    while (1){
        ch = fgetc(fp);
        if (ch == EOF)
            break;
        if (ch == '\n')
            qtdLinhas++;
    }
    rewind(fp); //Retorna o ponteiro para o início do arquivo
    return qtdLinhas;
}

NoA *CarregarCampos(FILE *arquivo){
    char claim_uid[25], cord_uid[25], title[2000], doi[100], numerical_claims[2000], publish_time[20], authors[2000], journal[500], country[50], institution[300];
    int linha;
    char *chave;    
    NoA *arvore = NULL;
    int qtdLinhas = contar_linhas(arquivo);
    
    for(int i = 0; i < qtdLinhas; i++){
        fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", &linha, claim_uid, cord_uid, title, doi, numerical_claims, publish_time, authors, journal, country, institution);
        chave = strcat(country, publish_time);
        arvore = InserirNo(arvore, linha, chave);
    }

    rewind(arquivo);

    return arvore;
}

int ordem[35], i = 0;
int *EmitirOrdemAcessoArvore(NoA *A){
    if(A){
        EmitirOrdemAcessoArvore(A->E);
        ordem[i] = A->linha;
        i++;
        EmitirOrdemAcessoArvore(A->D);
    }
    return ordem;
}



main(){
    FILE *arquivo = NULL;
    FILE *ArvBin, *Relatorio;

    //Criando arquivos de saída
    ArvBin = fopen("Arvore Binaria.txt", "w");
    if (ArvBin == NULL){
        puts ("Erro na abertura do arquivo!");
        system("pause");
        exit(0);
    }

    Relatorio = fopen("Relatorio.txt", "w");
    if (Relatorio == NULL){
        puts ("Erro na abertura do arquivo!");
        system("pause");
        exit(0);
    }

    int opcao;
    char nomeArq[50];
    NoA *arvore = NULL;
    Registro *vet;
    vet = (Registro*)malloc(35*sizeof(Registro));


    while(opcao != 3){
        printf("\n1 - Carregar Arquivo de Dados");
        printf("\n2 - Emitir Relatorio");
        printf("\n3 - Sair\n\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\nInforme o nome do arquivo: ");
                scanf("%s", nomeArq);
                
                arquivo = fopen(nomeArq, "r");
                if(arquivo == NULL){
                    printf("Ocorreu um erro na abertura do arquivo, tente novamente\n\n");
                    break;
                }

                int qtdlinha = contar_linhas(arquivo);
                arvore = CarregarCampos(arquivo);
                printf("Arquivo carregado com Sucesso\n");
                vet = criarListaDados(arquivo, vet);

                break;
            case 2:
                if(arquivo == NULL){
                    printf("\nArquivo Vazio!!!\n\n");
                    break;
                }

                imprimirArvore(ArvBin, arvore);
                printf("\nArquivo 'Arvore Binaria' feito com sucesso\n");

                EmitirOrdemAcessoArvore(arvore);

                fprintf(Relatorio, "Linha | claim_uid | cord_uid | title | doi | numerical_claims | publish_time | authors | journal | country | institution \n");
                for(int i = 0; i < qtdlinha; i++){
                    if(vet[ordem[i]-1].linha < 10)
                        fprintf(Relatorio, "Linha: %d  |Dados: %s\n", vet[ordem[i]-1].linha, vet[ordem[i]-1].dados);
                    if(vet[ordem[i]-1].linha > 10)
                        fprintf(Relatorio, "Linha: %d |Dados: %s\n", vet[ordem[i]-1].linha, vet[ordem[i]-1].dados);
                }
                printf("Arquivo 'Relatorio' feito com sucesso\n");
                printf("\n");
                
                
                break;
            case 3:
                fclose(arquivo);
                fclose(ArvBin);
                fclose(Relatorio);
                free(vet);
                FreeArvore(arvore);
                printf("\nDesalocacao feita.");
        }
    }
}