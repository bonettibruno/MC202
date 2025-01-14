#include <stdio.h>
#include <stdlib.h>

typedef struct fp{
    int *valor, n, tamanho;
} fp ;

fp* cria_heap(int tam){
    fp novo;
    novo = (fp*) malloc (sizeof (fp));
    novo->valor = int numeros[100];
    novo->n = 0;
    novo->tamanho = tam;
    return novo;
}

void insere(fp* heap, int valor){

}

int main(){
    fp* cria_heap(int tamanho);
    void insere(fp *heap, int valor);
    int extrai_maximo(fp *heap);
    void escreve(fp *heap);
    return 0;
}

