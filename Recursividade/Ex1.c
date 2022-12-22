#include<stdio.h>

//Função recursiva para calcular o valor de uma base x elevada a um expoente y. 
int Potencia(int x, int y){
    if (y == 0)
        return 1;
    else 
        return(x * Potencia(x, y-1));
}

//Função recursiva que retorna o tamanho de um string, tamstring(char s[]) .
int TamString(char s[]){
    if (s[0] == '\0' && s[0] != ' ')
        return 0;
    else
        return (1 + TamString(&s[1]));
}

//Função recursiva que conta o número de ocorrências de um determinado caracter, caract(char c, char s[])
int Caract(char c, char s[]){
    if (s[0] == '\0')
        return 0;
    if (s[0] == c)
        return (1 + Caract(c, &s[1]));
    else
        return (Caract(c, &s[1]));
}

//Função recursiva que produza o reverso de um string, reverse(char s[])
void Reverse(char s[]){
    if (s[0] != '\0')
        Reverse(&s[1]);
        printf("%c", s[0]);
}

main(){
    /*
    //Teste função Potencia
    int x, y;
    printf("Base: ");
    scanf("%d", &x);
    printf("Expoente: ");
    scanf("%d", &y);
    printf("Resultado: %d", Potencia(x, y));
    */

    /*
    //Teste função TamString
    char frase[100];
    printf("Frase: ");
    scanf("%s", frase);
    printf("Tamanho da frase: %d", TamString(frase));
    */

    /*
    //Teste da função Caract
    char ch;
    char palavra[100];
    printf("Palavra: ");
    scanf("%s", palavra);
    printf("Letra: ");
    scanf(" %c", &ch);
    printf("Ocorrencia(s) da letra '%c' na palavra '%s': %d", ch, palavra, Caract(ch, palavra));
    */

    /*
    //Teste da função Reverse
    char palavra[100];
    printf("Palavra: ");
    scanf("%s", palavra);
    Reverse(palavra);
    */
}