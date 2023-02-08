#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Struct de cada Nó da árvore
typedef struct NoA{
    int linha;
    char chave[50];
    struct NoA *E;
    struct NoA *D;
} NoA;

//Função para inserir Nó na árvore
NoA *InserirNo(NoA *A, int linha, char chave[50]){
    if(A == NULL){ //Apenas seta os valores caso o Nó da árvore esteja vazio
        NoA *aux = malloc(sizeof(NoA));
        aux->linha = linha;
        strcpy(aux->chave, chave);
        aux->E = NULL;
        aux->D = NULL;
        return aux;
    }else{
        if(strcmp(chave, A->chave) == -1) //usa o strcmp para decidir o que é menor ou maior
            A->E = InserirNo(A->E, linha, chave); //menores na ordem alfabética vão para esquerda
        else
            A->D = InserirNo(A->D, linha, chave); //maiores na ordem alfabética vão para direita
        return A;
    }
}

//Função que imprime a árvore apenas para visualizá-la
void imprimirArvore(FILE *arquivo, NoA *A){
    if(A){
        //Primeiro vai toda pra esquerda
        imprimirArvore(arquivo, A->E);
        //Quando volta, acessa o Nó
        if(A->linha < 10)
            fprintf(arquivo, "Linha: %d  |Chave: %s\n", A->linha, A->chave);
        if(A->linha >= 10 && A->linha < 100)
            fprintf(arquivo, "Linha: %d |Chave: %s\n", A->linha, A->chave);
        if(A->linha >= 100 && A->linha <= 1000)
            fprintf(arquivo, "Linha: %d|Chave: %s\n", A->linha, A->chave);
        //Depois vai pra direita
        imprimirArvore(arquivo, A->D);
    }
}

//Função que desaloca cada nó da árvore
void FreeArvore(NoA *A){
    if (A != NULL){
        FreeArvore(A->E); //Vai indo pra esquerda, quando o Filho a esquerda foi NULL, desaloco o nó
        FreeArvore(A->D); //Depois pra direita
        free(A);
    }  
}

//Função que carrega o arquivo
NoA *CarregarArquivo(FILE *arquivo, long int *vet){
    char claim_uid[25], cord_uid[25], title[100000], doi[100], numerical_claims[100000], publish_time[20], authors[100000], journal[1000], country[1000], institution[1000];
    int linha;
    char *chave; 
    char ch;
    int indPos = 1;  
    NoA *arvore = NULL;
    
    while (1){
        vet[indPos] = ftell(arquivo);
        //Essa função é responsável por dizer a posição do cursor no arquivo em bytes
        //Servirá para mover o cursor para a linha desejada na função fseek mais pra frente
        
        //Leio os dados
        fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
                        &linha, claim_uid, cord_uid, title, doi, numerical_claims, publish_time, authors, journal, country, institution);
        
        //Pra quando chegar no final do arquivo
        ch = fgetc(arquivo);
        if(ch == EOF){
            break;
        }
        
        chave = strcat(country, publish_time); //Concatenando os campos que serão a chave
        arvore = InserirNo(arvore, linha, chave); //Inserindo Nó

        indPos++;
    }
    
    return arvore;
}

char claim_uid[25], cord_uid[25], title[10000], doi[100], numerical_claims[10000], publish_time[20], authors[20000], journal[1000], country[1000], institution[1000];
void EmitirRelatorio(FILE *arquivo, FILE *arquivo2, NoA *A, long int *vet){
    int linha;
    if(A->E != NULL)
        EmitirRelatorio(arquivo, arquivo2, A->E, vet); //Primeiro vou para tudo pra esquerda

    //Quando voltar, venho acessando o Nó
    fseek(arquivo, vet[A->linha], SEEK_SET);
    //Uso do vetor posição, nele contem o número de byte de cada linha
    //Exemplo de como está o vetor: [6750309, 0, 455, 1026, 1781, 2161, 2835, 3477, 4205, 4995 ...]
    
    //Lendo a linha
    fscanf(arquivo, "%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
                        &linha, claim_uid, cord_uid, title, doi, numerical_claims, publish_time, authors, journal, country, institution);
    
    //Printando no Arquivo de Relatório
    
    fprintf(arquivo2, "Linha %d |claim_uid: %s |cord_uid: %s |title: %s |doi: %s |numerical_claims: %s |publish_time: %s |authors: %s |journal: %s |country: %s |institution: %s\n", 
                        linha, claim_uid, cord_uid, title, doi, numerical_claims, publish_time, authors, journal, country, institution);
    
    if(A->D != NULL)
        EmitirRelatorio(arquivo, arquivo2, A->D, vet); //Depois vou pra direita
    
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
    long int vetBytesLinha[1000];
    NoA *arvore = NULL; //Criando árvore vazia

    //MENU
    while(opcao != 3){
        printf("\n1 - Carregar Arquivo de Dados");
        printf("\n2 - Emitir Relatorio");
        printf("\n3 - Sair\n\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\nInforme o nome do arquivo: ");
                scanf("%s", nomeArq);
                
                //Abrindo o arquivo que o usuário digitar
                arquivo = fopen(nomeArq, "r");
                if(arquivo == NULL){
                    printf("Ocorreu um erro na abertura do arquivo, tente novamente\n\n");
                    break;
                }
                
                arvore = CarregarArquivo(arquivo, vetBytesLinha); //Carregando Arquivo
                printf("Arquivo carregado com Sucesso\n");

                break;
            case 2:
                if(arquivo == NULL){
                    printf("\nArquivo Vazio!!!\n\n");
                    break;
                }

                imprimirArvore(ArvBin, arvore); //Imprimindo o Arquivo 'Arvore Binaria'
                printf("\nArquivo 'Arvore Binaria' feito com sucesso\n");

                EmitirRelatorio(arquivo, Relatorio, arvore, vetBytesLinha); //Imprimindo o Arquivo 'Relatorio'
                printf("Arquivo 'Relatorio' feito com sucesso\n");
                printf("\n");
                
                break;
            case 3:
                //Fechando os arquivos
                fclose(arquivo);
                fclose(ArvBin);
                fclose(Relatorio);
                //Desalocando toda a árvore
                FreeArvore(arvore); 
                printf("\nDesalocacao feita.");
        }
    }
}