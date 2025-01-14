#include <stdio.h>
#include <stdlib.h>

int main(){
    // Definir entradas
    int m,n,s;

    // Ler os valores m,n e s;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&s);

    // Criando a matriz
    int matriz[n][m];
    // Lendo valores para matriz
    for(int i = 0;i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    // Tamanho da matriz 
    int m_size = sizeof(matriz) / sizeof(matriz[0]);

    // Criando novas variaveis para submatriz e auxiliares

    if (n == 1){
        for (int i = 0; i < m; i++){
            if(matriz[0][i] == s){
                printf("submatriz 1 x 1 em [1,%d]\n", i + 1);
                return 0;
            }
            
        }
    printf("nao ha'\n");
    } else {
    // Utilizando tamanho de matriz e submatriz como parâmetros para os laços for
    // Nesse for igualamos o tamanho da submatriz com o da matriz e diminui ate tamanho 2
        int soma_submatriz;
        for(int sub_m_size = 0; sub_m_size <= m_size; sub_m_size++) {
            int count = m_size - sub_m_size + 1;
            for (int i2 = 0; i2 < count; i2++) {
                for (int j2 = 0; j2 < count; j2++) {
                    soma_submatriz = 0;
                    for (int i = 0; i <= sub_m_size; i++) {
                        for (int j = 0; j <= sub_m_size; j++) { 
                            soma_submatriz += matriz[i+i2][j+j2];
                        }
                    }
                    if(soma_submatriz == s){
                        printf("submatriz %d x %d em [%d,%d]\n",sub_m_size + 1,sub_m_size + 1,i2+1,j2+1);
                        return 0;
                    }
                }     
            }
        }
        printf("nao ha'\n");
    }
}
