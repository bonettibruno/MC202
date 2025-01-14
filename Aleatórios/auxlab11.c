#include <stdio.h>
#include <stdlib.h>

void printVetor(int lista[], int tamanho){
    for (int i = 0; i < tamanho; i++)
        printf("%d ", lista[i]);
    printf("\n");
}

void leVetor(int lista[], int tamanho){
	int i;
	for (i = 0; i < tamanho ; i++)
		scanf ("%d", &lista[i]);
}

void copiaVetor(int lista1[], int lista2[], int tamanho){
    for(int i = 0; i < tamanho ; i++)
        lista2[i] = lista1[i];
}

void bubbleSort(int *lista, int comeco, int fim){
    for (int a = comeco; a < fim; a++){
        for (int b = comeco; b < fim ; b++){
            if (lista[b] > lista[b+1]){
                int aux = lista[b];
                lista[b] = lista[b+1];
                lista[b+1] = aux;
            }
        }
    }
}

void merge(int *V,int ini,int meio,int fim) {
    int i = ini;
    int j = meio + 1;
    int k = 0;
    int aux[fim - ini + 1];
    
    while ((i <= meio) && (j <= fim)) {
    	if (V[i] <= V[j]) {
            aux[k] = V[i];
            i++;
        }
        else {
            aux[k] = V[j];
            j++;
        }
        k++;
    }

    if (i <= meio)  {
        j = meio;
        while (j >= i) {
            V[fim - meio + j] = V[j];
            j--;
        }
    }

    for (i = 0;i < k;i++) 
        V[ini + i] = aux[i];
    

}

void mergeSort(int *V, int ini, int fim, int x, int tamanho) {
    printVetor(V, tamanho);
    if (ini < fim) {
        if (fim - ini < x){
            bubbleSort(V, ini, fim);
        } else {
        int meio = (ini + fim) / 2;
        if (ini < meio) 
            mergeSort(V,ini,meio, x, tamanho);
        if ((meio + 1) < fim) 
            mergeSort(V,meio + 1,fim, x, tamanho);
        
        merge(V,ini,meio,fim);

        }
    }
}


void troca(int *x,int *y) {
    int aux = *x;
    *x = *y;
    *y = aux;

}

int particao(int *V,int ini,int fim) {
    int pivo = V[ini];
    int i = ini + 1;
    int j = fim;
    
    while (i <= j) {
        while ((i <= j) && (V[i] <= pivo)) 
	        i++;
	    
        while (V[j] > pivo) 
            j--;
        
        if (i < j) {
            troca(&V[i],&V[j]);
            i++;
            j--;
        }
    }
    troca(&V[ini],&V[j]);
    return j;
}


void quickSort(int *V,int ini,int fim, int x, int tamanho) {
    int j;
    if (ini < fim) {
        printVetor(V, tamanho);
        if (fim - ini <= x){
            bubbleSort(V, ini, fim);
        } else {
        j = particao(V,ini,fim);
        if (ini < (j - 1))
            quickSort(V,ini,j - 1, x, tamanho);
        if ((j + 1) < fim) 
            quickSort(V,j + 1,fim, x, tamanho);
        }
    }
}

int main(){
    int tamanho, x;
    scanf("%d", &tamanho);
    int lista[tamanho], lista2[tamanho];
    leVetor(lista, tamanho);
    copiaVetor(lista, lista2, tamanho);
    scanf("%d", &x);

    printf("MERGESORT\n");
    mergeSort(lista, 0, tamanho - 1, x, tamanho);
    printVetor(lista, tamanho);

    printf("QUICKSORT\n");
    quickSort(lista2, 0, tamanho-1, x, tamanho);
    printVetor(lista2, tamanho);

    return 0;
}


//descobrir onde estou errando os printf