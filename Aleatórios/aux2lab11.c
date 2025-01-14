#include <stdio.h>
#include <stdlib.h>

void printVetor(int lista[], int tamanho){
    for (int i = 0; i < tamanho; i++)
        printf("%d ", lista[i]);
    printf("\n");
}

void leVetor(int lista[], int tamanho){
	for(int i = 0; i < tamanho ; i++)
		scanf ("%d", &lista[i]);
}

void copiaVetor(int lista1[], int lista2[], int tamanho){
    for(int i = 0; i < tamanho ; i++)
        lista2[i] = lista1[i];
}

void troca(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int lista[], int comeco, int fim){
    for (int a = comeco; a < fim; a++){
        for (int b = comeco; b < fim - a - 1 ; b++){
            if (lista[b] > lista[b+1]){
                troca(&lista[b], &lista[b+1]);
            }
        }
    }
}

void merge(int *v , int l , int m , int r, int tamanho) {
    int aux[tamanho];
    int i = l , j = m + 1, k = 0;

    while (i <= m && j <= r)
        if (v[i] <= v[j]) 
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];

        while (i <= m)
            aux [k++] = v[i++];
        while (j <= r)
            aux[k++] = v[j++];

        for (i = l , k = 0; i <= r; i ++ , k ++)
            v[i] = aux[k];
        
}

void mergeSort(int *lista , int l , int r, int tamanho, int x) {
    if (l < r) {
        printVetor(lista, tamanho);
        if (r - l <= x){
           bubbleSort(lista, l, r);
        } else {
            int meio = (l + r ) / 2;
            mergeSort(lista, l , meio, tamanho, x);
            mergeSort(lista, meio + 1, r, tamanho, x);
            merge(lista, l , meio , r, tamanho);
        }
    }
}

void quickSort(int lista[], int primeiro,int ultimo, int tamanho){
    int i, j, pivo, temp;
    printVetor(lista, tamanho);
    if(primeiro < ultimo){
        pivo = primeiro;
        i = primeiro;
        j = ultimo;

    while(i < j){
        while(lista[i] <= lista[pivo] && i < ultimo)
            i++;
        while(lista[j]>lista[pivo])
            j--;
        if(i < j){
            temp = lista[i];
            lista[i] = lista[j];
            lista[j] = temp;
        }
    }

        temp=lista[pivo];
        lista[pivo]=lista[j];
        lista[j]=temp;
        quickSort(lista,primeiro,j-1, tamanho);
        quickSort(lista,j+1,ultimo, tamanho);    
    }
}




int main(){
    int tamanho, x;
    scanf("%d", &tamanho);
    int lista[tamanho], copia_lista[tamanho];
    leVetor(lista, tamanho);
    copiaVetor(lista, copia_lista, tamanho);
    scanf("%d", &x);

    printf("MERGESORT\n");
    mergeSort(lista, 0, tamanho, tamanho, x);
    printVetor(lista, tamanho);

    printf("QUICKSORT\n");
    quickSort(copia_lista, 0, tamanho, tamanho);
    printVetor(copia_lista, tamanho);

    return 0;
}