main(){
    int cont, N, soma;

    scanf("%d",&N);
    soma = 0;

    for (cont = 0; cont < N; cont++){
        int numero;
        scanf("%d",&numero);
        soma = soma + numero;
    }
    
    printf("%d", soma);
}