#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NO;


NO* insere_nos(NO* raiz, int chave){
    NO* novo ;
    if (raiz == NULL){
        novo = (NO*) malloc(sizeof(NO));
        novo->esquerda = novo->direita = NULL;
        novo->valor = chave;
        return novo;
    }
    if(chave < raiz->valor)
        raiz->esquerda = insere_nos(raiz->esquerda, chave);
    else
        raiz->direita = insere_nos(raiz->direita, chave);
    return raiz;
}


void imprimir_pre_ordem(NO* no){
    if (no != NULL){
        printf("%c ", no->valor);
        imprimir_pre_ordem(no->esquerda);
        imprimir_pre_ordem(no->direita);
    }
}

int main(){
    NO* arvore =  NULL;

    int x = 10;
    int y = 23;
    insere_nos(arvore, x);
    insere_nos(arvore, y);
    printf("inseriu");
    imprimir_pre_ordem(arvore);

    return 0;
}