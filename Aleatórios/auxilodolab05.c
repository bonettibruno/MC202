#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int valor;
    int linha;
    int coluna;
    struct elemento *prox_na_linha;
    struct elemento *prox_na_coluna;
}Elemento;


Elemento* criar_matriz(int n){
    Elemento* matriz;
    matriz = (Elemento*) malloc(sizeof(Elemento));
    matriz->prox_na_linha = matriz;
    matriz->prox_na_coluna = matriz;
    matriz->valor = 0;
    matriz->linha = n;
    matriz->coluna = n;

    Elemento* ultimo1 = matriz;
    for(int i = 0; i < n; i++){
        Elemento* novo1 =  (Elemento*) malloc(sizeof(Elemento));
        novo1->prox_na_coluna = novo1;
        novo1->valor = 0;
        novo1->coluna = i+1;
        novo1->linha = -1;
        novo1->prox_na_linha = ultimo1->prox_na_linha;
        ultimo1->prox_na_linha = novo1;
        ultimo1 = novo1;
        printf("%d\n", i);       
    }
    Elemento* ultimo2 = matriz;
    for(int k = 0; k < n; k++){
        Elemento* novo2 =  (Elemento*) malloc(sizeof(Elemento));
        novo2->prox_na_linha = novo2;
        novo2->valor = 0;
        novo2->coluna = -1;
        novo2->linha = k+1;
        novo2->prox_na_coluna = ultimo2->prox_na_coluna;
        ultimo2->prox_na_coluna = novo2;
        ultimo2 = novo2;
 //       printf("%d\n", k);
    }
    return matriz;
}

void adiciona_elementos(Elemento* matriz, int valor, int linha, int coluna){
    Elemento* auxiliar1;
    Elemento* auxiliar2;
    if(valor != 0){
        Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
        novo->valor = valor;
        novo->coluna = coluna;
        novo->linha = linha;
//pondo na coluna
        auxiliar1 = matriz;
        auxiliar2 = matriz->prox_na_coluna;
        while(auxiliar2->coluna != coluna){
            auxiliar1 = auxiliar2;
            auxiliar2 = auxiliar2->prox_na_coluna;
        }
        if(auxiliar2->prox_na_linha = auxiliar2){
            novo->prox_na_linha = auxiliar2;
            auxiliar1->prox_na_linha = novo;
        } else {
            while(auxiliar2->linha != linha){
                auxiliar1 = auxiliar2;
                auxiliar2 = auxiliar2->prox_na_linha;
            }
        }
            novo->prox_na_linha = auxiliar2;
            auxiliar1->prox_na_linha = novo;
//pondo na linha
        auxiliar1 = matriz;
        auxiliar2 = matriz->prox_na_linha;
        while(auxiliar2->linha != linha){
            auxiliar1 = auxiliar2;
            auxiliar2 = auxiliar2->prox_na_linha;
        }
        if(auxiliar2->prox_na_coluna = auxiliar2){
            novo->prox_na_coluna = auxiliar2;
            auxiliar1->prox_na_coluna = novo;
        } else {
            while(auxiliar2->coluna != coluna){
                auxiliar1 = auxiliar2;
                auxiliar2 = auxiliar2->prox_na_coluna;
            }
            novo->prox_na_coluna = auxiliar2;
            auxiliar1->prox_na_coluna = novo;
        }   
    }
}

int acha_valor(Elemento* matriz, int linha, int coluna, int n){
    Elemento* aux1;
    Elemento* aux2;
    aux1 = matriz;
    aux2 = aux1->prox_na_coluna;
    while (aux2->coluna != coluna){
        aux1 = aux2;
        aux2 = aux1->prox_na_coluna;
    }
    aux1 = aux2;
    aux2 = aux1->prox_na_linha;
    for(int i = 0; i < n; i++){
        aux1 = aux2;
        aux2 = aux1->prox_na_linha;
        if(aux2->linha == linha){
            return aux2->valor;
        }
    }
    return 0;
}


void soma_matrizes(Elemento* matriz1, Elemento* matriz2, Elemento* matriz3, int n){
    int valor_da_3;
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            valor_da_3 = acha_valor(matriz1, i, j, n) + acha_valor(matriz2, i, j, n);
            if(valor_da_3 != 0){
                adiciona_elementos(matriz3, valor_da_3, i, j);
            }
        }
    }
}

void imprime_matriz(Elemento* matriz, int n){
    for(int i = 1; i <= n; i++){
        for (int j = 1; i <= n; j++){
            printf("%d ", acha_valor(matriz, i, j, n));
        }
        printf("\n");
    }
}


int main(){
    Elemento* matriz1;
    Elemento* matriz2;
    Elemento* matriz3;

    int n;
    scanf("%d", &n);

    matriz1 = criar_matriz(n);
    matriz2 = criar_matriz(n);
    matriz3 = criar_matriz(n);

    int linha, coluna, valor;

    scanf("%d %d %d", &linha, &coluna, &valor);
    while(linha != -1 || coluna != -1 || valor != -1){
        adiciona_elementos(matriz1, valor, linha, coluna);
        scanf("%d %d %d", &linha, &coluna, &valor);
    }
    imprime_matriz(matriz1, n);
    scanf("%d %d %d", &linha, &coluna, &valor);
    while(linha != -1 || coluna != -1 || valor != -1){
        adiciona_elementos(matriz2, valor, linha, coluna);
        scanf("%d %d %d", &linha, &coluna, &valor);
    }

    soma_matrizes(matriz1, matriz2, matriz3, n);
    imprime_matriz(matriz3, n);
    return 0;
}


//criar uma funçao que recebe o ponteiro para uma matriz esparsa, recebe linha e coluna, e o valor para ser inserido nessa ccoordenada, (void), verifica se o valor
//diferente de zero

//criar uma segunda funçao que retorna um int, que recebe um pont de uma matriz, as coordenadas e retorna o valor que esta nessa coordenada


//