#include <stdio.h>

int main(){
  int n, x, i;
  scanf("%d", n);
  i = 0
  while (i<n){
    scanf("%d", x);
    i = i + 1;
    if (x / 2 == 0)
      printf("PAR")
    else{
      printf("IMPAR")
    }
  }
}
