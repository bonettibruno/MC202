#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void fazercadastro(taluno *aluno){
    scanf("%d %d %d %d ", &aluno->ra, &aluno->nascimento.dia, &aluno->nascimento.mes, &aluno->nascimento.ano);
    fgets(aluno->nome, 60, stdin);
}

void impressao(taluno *aluno){
  printf("%d %02d %02d %d %s", aluno->ra, aluno->nascimento.dia, aluno->nascimento.mes, aluno->nascimento.ano, aluno->nome);
}

void ordenarRA(taluno **aluno, int n){
  int a, b;
  taluno *aux;

  for (a = 0; a < n; a++){
    for (b = 0; b < n - 1; b++){
      if (aluno[b]->ra > aluno[b+1]->ra){
        aux = aluno[b];
        aluno[b] = aluno[b+1];
        aluno[b+1] = aux;
      }
    }
  }
}

void ordenarData(taluno **aluno, int n){
  int a, b;
  taluno *aux;

  for (a = 0; a < n; a++){
    for (b = 0; b < n - 1; b++){
      if (aluno[b]->nascimento.ano > aluno[b+1]->nascimento.ano){
        aux = aluno[b];
        aluno[b] = aluno[b+1];
        aluno[b+1] = aux;
      }
      else if (aluno[b]->nascimento.ano == aluno[b+1]->nascimento.ano){
        if (aluno[b]->nascimento.mes > aluno[b+1]->nascimento.mes){
          aux = aluno[b];
          aluno[b] = aluno[b+1];
          aluno[b+1] = aux;
        }
        else if (aluno[b]->nascimento.mes == aluno[b+1]->nascimento.mes){
          if (aluno[b]->nascimento.dia < aluno[b+1]->nascimento.dia){
            aux = aluno[b];
            aluno[b] = aluno[b+1];
            aluno[b+1] = aux;
          }
        }
      }
    }
  }
}

void ordenarNome(taluno **aluno, int n){
  int a, b, valor;
  taluno *aux;

  for (a = 0; a < n; a++){
    for (b = 0; b < n - 1; b++){
      valor = strcmp(aluno[b]->nome, aluno[b+1]->nome);
      if (valor > 0){
        aux = aluno[b];
        aluno[b] = aluno[b+1];
        aluno[b+1] = aux;
      }
    }
  }
}

int main(){
  int n, i, l;
  char escolha;

  scanf("%d", &n);

  taluno **aluno;
  aluno = (taluno **) malloc(sizeof(taluno *)*n);

  for (i=0; i < n; i++){
    aluno[i] = malloc(sizeof(taluno));
    fazercadastro(aluno[i]);
  }

  escolha = fgetc(stdin);

  if (escolha == 'R')
    ordenarRA(aluno, n);

  else if (escolha == 'D')
    ordenarData(aluno, n);

  else if (escolha == 'N')
    ordenarNome(aluno, n);

  for (l=0; l < n; l++)
    impressao(aluno[l]);

  for (i=0; i < n; i++)
    free(aluno[i]);

  free(aluno);

  return 0;
}
