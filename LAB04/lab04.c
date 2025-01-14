#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int id ;
  int num_subprodutos ;
  int vetor_subprodutos[50] ;
  float imposto ;
  float preco_final ;
  float preco_base ;
} tproduto ;

void cadastrando(tproduto *produto){
  int m;
  scanf("%d ", &produto->id);
  scanf("%d ", &produto->num_subprodutos);
  m = produto->num_subprodutos;
  if (produto->num_subprodutos == 0){
    scanf("%f %f", &produto->preco_base, &produto->imposto);
  } else {
    for (int i = 0; i < m; i++){
      scanf("%d ", &produto->vetor_subprodutos[i]);
    }
    scanf("%f", &produto->imposto);
  }
}

float calculapreco(tproduto **produto, int id_desejada, int n){
  int posicao_desejada;
  for (int i = 0; i < n; i++){
    if (produto[i]->id == id_desejada){
      posicao_desejada = i;
    }
  }

  if (produto[posicao_desejada]->num_subprodutos == 0){
    produto[posicao_desejada]->preco_final = produto[posicao_desejada]->preco_base * produto[posicao_desejada]->imposto / 100 + produto[posicao_desejada]->preco_base;
  } else {
    float soma = 0;
    for (int j = 0; j < produto[posicao_desejada]->num_subprodutos; j++)
      soma += calculapreco(produto, produto[posicao_desejada]->vetor_subprodutos[j], n);

    produto[posicao_desejada]->preco_final = soma * produto[posicao_desejada]->imposto / 100 + soma;
  }
  return produto[posicao_desejada]->preco_final;
}


int main(){
  int n, i, id_desejada;
  float precofinal;

  scanf("%d", &n);

  tproduto **produto;
  produto = (tproduto **) malloc(sizeof(tproduto *)*n);

  for (i=0; i < n; i++){
    produto[i] = malloc(sizeof(tproduto));
    cadastrando(produto[i]);
  }

  scanf("%d", &id_desejada);

  precofinal = calculapreco(produto, id_desejada, n);
  printf("%.2f\n", precofinal);

  return 0;
}
