/**
	Código retirado do material entitulado "MC-202 Curso de C - Parte 1", do professor Rafael C. S. Schouery.
*/

#include <stdio.h>

void le_vetor (int lista[] , int n) {
	int i;

	for (i = 0; i < n ; i++)
		scanf ("%d", &lista[i]);
}

void imprime_positivos (int lista[] , int n) {
	int i;

	printf ("\nOs número positivos são: \n");
	for (i = 0; i < n; i++)
		if (lista[i] > 0)
			printf ("%d\n", lista[i]);
}

int main () {
	int lista [10];

	le_vetor(lista, 10);
	imprime_positivos(lista, 10);

	return 0;
}
