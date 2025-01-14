#include <stdio.h>

void le_vetor (int lista[] , int n) {
	int i;

	for (i = 0; i < n ; i++)
		scanf ("%d", &lista[i]);
}

void imprime_vetor (int lista[] , int n) {
	int i;

	for (i = 0; i < n ; i++)
		printf ("%d", lista[i]);
}

int main () {
	int n, lista [n];
	scanf("%d", &n);
	le_vetor(lista, n);
  imprime_vetor(lista, n);

}
