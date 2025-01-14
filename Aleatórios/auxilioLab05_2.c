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
    matriz->linha = 0;
    matriz->coluna = 0;

//criando os cabecas das colunas:
    Elemento* ultimo1;
    ultimo1 = matriz;
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

//criando os cabecas das linhas:
    Elemento* ultimo2;
    ultimo2 = matriz;
    for(int k = 0; k < n; k++){
        Elemento* novo2 =  (Elemento*) malloc(sizeof(Elemento));
        novo2->prox_na_linha = novo2;
        novo2->valor = 0;
        novo2->coluna = -1;
        novo2->linha = k+1;
        novo2->prox_na_coluna = ultimo2->prox_na_coluna;
        ultimo2->prox_na_coluna = novo2;
        ultimo2 = novo2;
        printf("%d\n", k+10);
    }
    printf("saiu");
    return matriz;
}

int acha_valor(Elemento* matriz, int linha, int coluna, int n){
    Elemento* aux1;
    Elemento* aux2;

    aux2 = matriz->prox_na_coluna;
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

void imprime_matriz(Elemento* matriz, int n){
    printf("entrou na imrpime");
    for(int i = 1; i <= n; i++){
        for (int j = 1; i <= n; j++){
            printf("%d ", acha_valor(matriz, i, j, n));
        }
        printf("\n");
    }
}

int main(){
    Elemento* matriz;
    
    int n, t;
    scanf("%d", &n);
    matriz = criar_matriz(n);
    printf("to aqui\n");
    scanf("%d", &t);
    printf("%d", t);
    printf("AGR AQUI\n");
    imprime_matriz(matriz, n);
    return 0;
}