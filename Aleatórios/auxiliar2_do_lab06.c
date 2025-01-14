#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    char op;
    struct pilha *prox;
}Pilha;

void transfereTempPos(Pilha **pPos, Pilha **pTemp, Pilha *aux){
    aux = (*pTemp)->prox;
    (*pTemp)->prox = *pPos;
    *pPos = *pTemp;
    *pTemp = aux;
}

void alocaCharNaPilha( Pilha **pilha, Pilha *aux, char op ){
    aux = ( Pilha *) malloc( sizeof( Pilha ) );
    aux -> op = op;  
    aux -> prox = *pilha;
    *pilha = aux;
}

void leOperacao(Pilha **pPos, Pilha **pTemp){
    char op;
    Pilha* aux;

    scanf( "%c", &op );
    while( op != '\n' ){
            if (op == "+" || op == "-"){
                while( ( *pTemp ) ){
                    transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                }
                alocaCharNaPilha( &( *pTemp ), aux, op );
            }
            else if(op == "*" || op == "/"){
                while( ( *pTemp ) && ( (*pTemp) -> op != '+' && (*pTemp) -> op != '-' ) ){        
                    transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                }
                alocaCharNaPilha( &( *pTemp ), aux, op );
            }
           
            else{
                alocaCharNaPilha( &( *pPos ), aux, op );
            }
    scanf( "%c", &op );
    }
    while( *pTemp != NULL){
        transfereTempPos( &( *pPos ), &( *pTemp ), aux );
    }
}


void imprime( Pilha *topo ){
    if( topo ){
        imprime( topo -> prox );
        printf( "%c", topo -> op );
    }   
}

int main()
{
    Pilha *pPos = NULL;
    Pilha *pTemp = NULL;

    printf( "Operacao Infixa: " );
    leOperacao( &pPos, &pTemp );
    printf( "Operacao Posfixa: " );
    imprime( pPos );
    printf( "\n" );


    return 0;
}