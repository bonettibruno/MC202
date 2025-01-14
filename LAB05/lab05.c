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
    }
    return matriz;
}

void adiciona_elementos(Elemento* matriz, int valor, int linha, int coluna){
    if(valor != 0){
        Elemento* auxiliar1;
        Elemento* auxiliar2;
        Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
        novo->valor = valor;
        novo->coluna = coluna;
        novo->linha = linha;

        auxiliar1 = matriz->prox_na_linha;
        while(auxiliar1->coluna != coluna){
            auxiliar1 = auxiliar1->prox_na_linha;
        }
        if(auxiliar1->prox_na_coluna == auxiliar1){
            novo->prox_na_coluna = auxiliar1;
            auxiliar1->prox_na_coluna = novo;
        }else{
            auxiliar2 = auxiliar1;
            while(auxiliar2->prox_na_coluna != auxiliar1 && auxiliar2->prox_na_coluna->linha < linha){
                auxiliar2 = auxiliar2->prox_na_coluna;
            }
            novo->prox_na_coluna = auxiliar2->prox_na_coluna;
            auxiliar2->prox_na_coluna = novo;
        }

        auxiliar1 = matriz->prox_na_coluna;
        while(auxiliar1->linha != linha){
            auxiliar1 = auxiliar1->prox_na_coluna;
        }
        if(auxiliar1->prox_na_linha == auxiliar1){
            novo->prox_na_linha = auxiliar1;
            auxiliar1->prox_na_linha = novo;
        }else{
            auxiliar2 = auxiliar1;
            while(auxiliar2->prox_na_linha != auxiliar1 && auxiliar2->prox_na_linha->linha < linha){
                auxiliar2 = auxiliar2->prox_na_linha;
            }
            novo->prox_na_linha = auxiliar2->prox_na_linha;
            auxiliar2->prox_na_linha = novo;
        }
    }
}

int acha_valor(Elemento* matriz, int linha, int coluna){
    Elemento* aux1;
    Elemento* aux2;

    aux1 = matriz->prox_na_coluna;
    while(aux1->linha != linha){
        aux1 = aux1->prox_na_coluna;
    }
    aux2 = aux1->prox_na_linha;
    while(aux2 != aux1){
        if(aux2->coluna == coluna){
            return aux2->valor;
        }
        aux2 = aux2->prox_na_linha;
    }
    return 0;
}

void soma_matrizes(Elemento* matriz1, Elemento* matriz2, Elemento* matriz3, int n){
    int valor_da_3;
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            valor_da_3 = acha_valor(matriz1, i, j) + acha_valor(matriz2, i, j);
            if(valor_da_3 != 0){
                adiciona_elementos(matriz3, valor_da_3, i, j);
            }
        }
    }
}

void imprime_matriz(Elemento* matriz, int n){
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            printf("%d ", acha_valor(matriz, i, j));
        }
        printf("\n");
    }
}

void destroi_linha(Elemento* matriz, int linha){
    Elemento* aux1;
    Elemento* aux2;

    aux2 = matriz->prox_na_coluna;
    while(aux2->linha != linha){
        aux1 = aux2;
        aux2 = aux1->prox_na_coluna;
    }

    aux1 = aux2->prox_na_linha;
    while(aux1->valor != 0){
        aux2 = aux1;
        aux1 = aux2->prox_na_linha;
        free(aux2);
    }
}

void destruir(Elemento* matriz, int n){
    Elemento* aux1;
    Elemento* aux2;
    for(int i = 1; i <= n; i++){
        destroi_linha(matriz, i);
    }

    aux2 = matriz;
    aux1 = aux2->prox_na_coluna;
    for(int i = 0; i < n; i++){
        aux2 = aux1->prox_na_coluna;
        free(aux1);
        aux1 = aux2;
    }
    
    aux2 = matriz;
    aux1 = aux2->prox_na_linha;
    for(int i = 0; i < n; i++){
        aux2 = aux1->prox_na_linha;
        free(aux1);
        aux1 = aux2;
    }
    free(matriz);
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

    scanf("%d %d %d", &linha, &coluna, &valor);
    while(linha != -1 || coluna != -1 || valor != -1){
        adiciona_elementos(matriz2, valor, linha, coluna);
        scanf("%d %d %d", &linha, &coluna, &valor);
    }

    soma_matrizes(matriz1, matriz2, matriz3, n);
    imprime_matriz(matriz3, n);

    destruir(matriz1, n);
    destruir(matriz2, n);
    destruir(matriz3, n);

    return 0;
}