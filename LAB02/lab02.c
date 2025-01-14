#include <stdio.h>
#include <string.h>

void le_textos (char lista[], int n) {
	fgets(lista, n, stdin);
}

int ocorre ( char texto [], char padrao [])
{
  int j, i, n = 0, divergencias, tamanho_texto, tamanho_padrao;
	tamanho_texto = strlen(texto);
	tamanho_padrao = strlen(padrao) - 1;
	padrao[tamanho_padrao] = '\0';
	if (tamanho_padrao > tamanho_texto){
		printf("Nenhuma ocorrencia encontrada");
		return 0;
	} else {
  for (i = 0; i <= tamanho_texto - tamanho_padrao ; i++)
	{
		divergencias = 0;
    for (j = 0; j < tamanho_padrao; j++)
		{
			if (texto[i+j] != padrao[j]){
				divergencias = divergencias + 1;
			}
			else if (divergencias >= 2)
				break;
    }
		if (divergencias < 2){
			n  = n + 1;
			if (n>1)
					printf ("\n");
			printf("%03d %03d %03d ", n, i+1, i+tamanho_padrao);
			for (j = 0; j < tamanho_padrao ; j ++){
				printf ("%c", texto[i+j]);
			}
	}
	}
	if (n == 0)
		printf("Nenhuma ocorrencia encontrada");
	return 0;
}
}
int main(){
  char texto[1000], padrao[1000];
  int maximo1, maximo2;
  maximo1 = 501;
  maximo2 = 31;
  le_textos(texto, maximo1);
  le_textos(padrao, maximo2);
	texto[501] = '\0';
	padrao[31] = '\0';
	ocorre(texto, padrao);
	return 0;
}
