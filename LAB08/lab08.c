#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NO;

NO* insere_nos(NO* raiz, int chave){
    NO* novo;
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

NO* acha_o_menor(NO* no){
    if(no == NULL)
        return NULL;
    else if(no->esquerda != NULL)
        return acha_o_menor(no->esquerda);
    return no;
}

NO* remove_nos(NO* raiz, int num){
    if(raiz == NULL)
        return NULL;
    if(num > raiz->valor){
        raiz->direita = remove_nos(raiz->direita, num);
    } else if(num < raiz->valor){
        raiz->esquerda = remove_nos(raiz->esquerda, num);
    } else {
        if(raiz->esquerda == NULL && raiz->direita == NULL){
            free(raiz);
            return NULL;
        } else if (raiz->esquerda == NULL || raiz->direita == NULL) {
            NO* temporario;
            if(raiz->esquerda == NULL)
                temporario = raiz->direita;
            else
                temporario = raiz->esquerda;
            free(raiz);
            return temporario;
        } else {
            NO* temporario = acha_o_menor(raiz->direita);
            raiz->valor = temporario->valor;
            raiz->direita = remove_nos(raiz->direita, temporario->valor);
        }
    }
    return raiz;
}

void libera_arvores(NO* arvore){
    if (arvore != NULL){
        libera_arvores(arvore->esquerda);
        libera_arvores(arvore->direita);
        free(arvore);
    }
}

void imprimir_pre_ordem(NO* no){
    if (no != NULL){
        printf("%d ", no->valor);
        imprimir_pre_ordem(no->esquerda);
        imprimir_pre_ordem(no->direita);
    }
}

void imprimir_in_ordem(NO* no){
    if (no != NULL){
        imprimir_in_ordem(no->esquerda);
        printf("%d ", no->valor);
        imprimir_in_ordem(no->direita);
    }
}

void imprimir_pos_ordem(NO* no){
    if (no != NULL){
        imprimir_pos_ordem(no->esquerda);
        imprimir_pos_ordem(no->direita);
        printf("%d ", no->valor);
    }
}

int main(){
    NO* arvore = NULL;

    char caractere;
    int valor;

    scanf("%c", &caractere);
    while(caractere != 'F'){
        scanf(" %d\n", &valor);
        if(caractere == 'I'){
            arvore = insere_nos(arvore, valor);
        } else {
            arvore = remove_nos(arvore, valor);
        }
        scanf("%c", &caractere);
    }

    if(arvore != NULL){
        imprimir_pre_ordem(arvore);
        printf("\n");
        imprimir_in_ordem(arvore);
        printf("\n");
        imprimir_pos_ordem(arvore);
        printf("\n");
    } else {
        printf("ARVORE RESULTANTE VAZIA\n");
    }
    
    libera_arvores(arvore);

    return 0;
}
