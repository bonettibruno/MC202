#include <stdio.h>
int main() {
char palavra[81], inversa[81];
int tam, i;
printf("Digite uma palavra: ");
scanf("%s", palavra);
for (tam = 0; palavra[tam]; tam++);
for (i = 0; i < tam; i++)
inversa[tam - i - 1] = palavra[i];
inversa[tam] = '\0';
printf("Inversa: %s\n", inversa);
return 0;
}
