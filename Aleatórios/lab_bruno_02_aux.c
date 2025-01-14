#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void le_pchaves(int num_pchaves, char lista_pchaves[]){
    for(int i = 0; i < num_pchaves; i++){
        char pchave[20];
        fgets(pchave, 20, stdin);
        lista_pchaves[i] = pchave;
    }
}





int main(){
    int num_pchaves, num_frases;
    scanf("%d %d",&num_pchaves, &num_frases);
    
    char lista_pchaves[20];
    le_pchaves(num_pchaves, lista_pchaves);

}