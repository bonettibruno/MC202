#include <stdio.h>
#include <stdlib.h>

typedef struct no_arvore {
    char letra;
    struct no_arvore *direita;
    struct no_arvore *esquerda;
}NO;

NO* inicializa_no(char letra){
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->letra = letra;
    novo->direita = NULL;
    novo->esquerda = NULL;
    return novo;
}

void imprimir_pos_ordem(NO* no){
    if (no != NULL){
        imprimir_pos_ordem(no->esquerda);
        imprimir_pos_ordem(no->direita);
        printf("%c ", no->letra);
    }
}

void le_entrada (char lista[] , int n) {
	for (int i = 0; i < n ; i++){
	    scanf(" %c", &lista[i]);
    }
}

NO* construir(char inordem[], char preordem[], int comeco, int fim, int *atual_preordem){
    if (comeco > fim) {
        return NULL;
    }

    NO* novo = inicializa_no(preordem[(*atual_preordem)]);
    *atual_preordem = *atual_preordem + 1;

    int i;
    for (i = comeco; i <= fim; i++){
        if (inordem[i] == novo->letra){
            break;
        }
    }
    novo->esquerda = construir(inordem, preordem, comeco, i - 1, atual_preordem);
    novo->direita = construir(inordem, preordem, i + 1, fim, atual_preordem);
    return novo;
}

NO* constroi_arvore(char inordem[], char preordem[], int n){
    int atual_preordem = 0;
    return construir(inordem, preordem, 0, n - 1, &atual_preordem);
}

void libera_arvores(NO* arvore){
    if (arvore != NULL){
        libera_arvores(arvore->esquerda);
        libera_arvores(arvore->direita);
        free(arvore);
    }
}

int main(){

    NO* arvore;
    int quant_nos;
    scanf("%d", &quant_nos);

    char seq_preordem[quant_nos];
    char seq_inordem[quant_nos];

    le_entrada(seq_preordem, quant_nos);
    le_entrada(seq_inordem, quant_nos);

    arvore = constroi_arvore(seq_inordem, seq_preordem, quant_nos);

    imprimir_pos_ordem(arvore);
    printf("\n");
    libera_arvores(arvore);

    return 0;
}
