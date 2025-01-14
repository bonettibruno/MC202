#include <stdio.h>


int soma(int x, int y) {
  if (y == 0){
  return x;
  } else {
  return soma(++x, --y);
  }
}

int main(){
  int a, b, resultado;
  scanf("%d", &a);
  scanf("%d", &b);
  resultado = soma(a, b);
  printf("%d", resultado);
  return 0;
}
