#include <stdio.h>
//essa função le a primeira linha de entrada
void le_num1 (float lista[] , int n) {
	int i;
	for (i = 0; i < n ; i++)
		scanf ("%f", &lista[i]);
}
//essa função le a segunda linha de entrada
void le_operador (char lista[] , int n) {
	int i;
	for (i = 0; i < n ; i++)
		scanf(" %c", &lista[i]);
}
//essa função le a terceira linha de entrada
void le_num2 (float lista[] , int n) {
	int i;
	for (i = 0; i < n ; i++)
		scanf ("%f", &lista[i]);
}
//essa função realiza a operação matematica e imprime
void matematicaeprinta (float num1[], char operador[], float num2[], int n) {
	int i;
	float resultado;
	for (i = 0; i < n ; i++){
		if (operador[i] == '+')
		{
			resultado = num1[i] + num2[i];
			printf("%.4f + %.4f = %.4f\n", num1[i], num2[i], resultado);
		}
		else if (operador[i] == '-')
		{
			resultado = num1[i] - num2[i];
			printf("%.4f - %.4f = %.4f\n", num1[i], num2[i], resultado);
		}
		else if (operador[i] == '/')
		{
			resultado = num1[i] / num2[i];
			printf("%.4f / %.4f = %.4f\n", num1[i], num2[i], resultado);
		}
		else if (operador[i] == '*')
		{
			resultado = num1[i] * num2[i];
			printf("%.4f * %.4f = %.4f\n", num1[i], num2[i], resultado);
		}
	}
}
//função main que junta as outras funções
int main () {
	int n;
	float lista1[100000], lista3[100000];
	char lista2[100000];
	scanf("%d", &n);
	le_num1(lista1, n);
	le_operador(lista2, n);
	le_num2(lista3, n);
	matematicaeprinta(lista1, lista2, lista3, n);


	return 0;
}
