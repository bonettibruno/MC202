#include <stdio.h>
#include <string.h>


typedef struct{
  int dia ;
  int mes ;
  int ano ;
} tdata ;

typedef struct{
  int ra ;
  tdata nascimento ;
  char nome[60] ;
} taluno ;

void fazercadastro(taluno *alunox){
      scanf("%d %d %d %d ", alunox->ra, alunox->nascimento.dia, alunox->nascimento.mes, alunox->nascimento.ano);
      fgets(alunox -> nome, 60, stdin);
}

void impressao(taluno *alunox){
  printf("RA: %d\n", alunox->ra);
  printf("Nascimento: %02d/%02d/%d \n", alunox->nascimento.dia, alunox->nascimento.mes, alunox->nascimento.ano);
  printf("Nome: %s\n", alunox->nome);
}



int main(){
  int n, i;
  scanf("%d", &n);

  taluno *ptr_aluno=NULL;

  aluno = (taluno *) malloc(sizeof(taluno)*n);

  for (i=0; i < n; i++){
    fazercadastro(&aluno[i]);
  }
  for (i=0; i < n; i++){
    impressao(&aluno[i]);
  }
//taluno aluno[50], *ptr_aluno1[50];






//  fazercadastro(&aluno[]);
//  impressao(&aluno[]);








/*  for (i=0; i < n; i++) {
      taluno aluno[i], *ptr_aluno[i];
      ptr_aluno[i] = &aluno[i];
      scanf("%d %d %d %d ", &ptr_aluno[i]->ra, &ptr_aluno[i]->nascimento.dia, &ptr_aluno[i]->nascimento.mes, &ptr_aluno1[i]->nascimento.ano);
      fgets(ptr_aluno[i] -> nome, 60, stdin);

      printf("RA: %d\n", ptr_aluno[i]->ra);
      printf("Nascimento: %02d/%02d/%d \n", ptr_aluno[i]->nascimento.dia, ptr_aluno[i]->nascimento.mes, ptr_aluno[i]->nascimento.ano);
      printf("Nome: %s\n", ptr_aluno[i]->nome);

  }
//  ptr_aluno1 = &aluno1;
/*  scanf("%d %d %d %d ", &ptr_aluno1 -> ra, &ptr_aluno1 -> nascimento.dia, &ptr_aluno1 -> nascimento.mes, &ptr_aluno1 -> nascimento.ano);
  fgets(&ptr_aluno1 -> nome, 60, stdin);


  printf("RA: %d\n", ptr_aluno1->ra);
  printf("Nascimento: %02d/%02d/%d \n", ptr_aluno1->nascimento.dia, ptr_aluno1->nascimento.mes, ptr_aluno1->nascimento.ano);
  printf("Nome: %s\n", ptr_aluno1->nome);

*/




  return 0;
}


//vetor[i]->campoAluno
//gcc (nome do arquivo com extensão) -std=c99 -Wall -g -Werror -lm -o (saida)
//vetor de apontadores para cada um dos alunos
//usar o enum para a ordem alfabética
