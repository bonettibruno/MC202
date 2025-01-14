# include <stdio.h>
# include <stdlib.h>

typedef struct elemento{
  char op;
  struct elemento *prox;
}Elemento;

typedef struct {
  Elemento* topo;
}PILHA;

void inicializa_pilha(PILHA* pilha){
  pilha->topo = NULL;
}

void empilha_itens (PILHA* pilha, char p){
  Elemento* auxiliar1;
  Elemento* auxiliar2;

  auxiliar2 = (Elemento*) malloc(sizeof(Elemento));
  auxiliar2->op = p;

  auxiliar1 = pilha->topo;
  pilha->topo = auxiliar2;
  auxiliar2->prox = auxiliar1;
}

void le_entrada(PILHA* exp_posfixa, PILHA* operadores_temporarios){
  char p;
  PILHA* auxiliar;
  scanf("%c", &p);
  while (p != "\n"){
    if (p == "+" || p == "-"){
      if (operadores_temporarios->topo == NULL){
        empilha_itens(operadores_temporarios, p);
      }
      if (operadores_temporarios->topo->op == "+" || operadores_temporarios->topo->op == "-"){
        desempilha_itens(operadores_temporarios, p);
        
      }
      empilha_itens(exp_posfixa, p);
    }
    else if (p == "*" || p == "/"){
      while (exp_posfixa->topo == "+" || exp_posfixa->topo == "-"){


      }
    
    }
    else {
      empilha_itens(pilha, p);
    }
    scanf("%c", &p);
  }
}

int main(){
  PILHA* exp_posfixa;
  PILHA* operadores_temporarios;

  inicializa_pilha(exp_posfixa);
  inicializa_pilha(operadores_temporarios);

  le_entrada(pilha, operadores_temporarios);

  
  return 0;
}

//ver se tem que fazer a struct pilha, ver como transformar char em float
//https://www.includehelp.com/c/infix-to-postfix-conversion-using-stack-with-c-program.aspx
//http://www.each.usp.br/digiampietri/ed/aula09.pdf
//http://www.vision.ime.usp.br/~pmiranda/mac122_2s14/aulas/aula13/aula13.html
//https://panda.ime.usp.br/pythonds/static/pythonds_pt/03-EDBasicos/09-ExpressoesInfixaPrefixaPosfixa.html
//https://www.vivaolinux.com.br/script/Infixa-para-Posfixa-em-C
//https://www.youtube.com/watch?v=SZQbR1VOICw
