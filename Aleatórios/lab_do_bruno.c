#include <stdio.h>
#include <stdlib.h>

int main(){
    // Definir entradas
    int i,j,m,n,s;

    // Ler os valores m,n e s;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d",&s);

    // Criando a matriz
    int matriz[n][m];
    // Lendo valores para matriz
    for(i = 0;i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &matriz[i][j]);
        }}
    if (n == 1){
        for (int x = 0; x < m; x++){
            if(matriz[0][x] == s){
                printf("submatriz 1 x 1 em [1,%d]\n", x+1);
                
                return 0;
        }   }
    printf("nao ha'\n");
    } else 
    {
        // Tamanho da matriz 
        int m_size = sizeof(matriz) / sizeof(matriz[0]);

        // Criando novas variaveis para submatriz e auxiliares
        int sub_m_size;
        int i2, j2,count;

        // Utilizando tamanho de matriz e submatriz como parâmetros para os laços for
        // Nesse for igualamos o tamanho da submatriz com o da matriz e diminui ate tamanho 2
        int soma_submatriz;
        for(sub_m_size = m_size; sub_m_size >= 1; sub_m_size--) 
        {
            // Utilizamos count como parâmetro de limite máximo do tamanho da matriz.
            //Assim imprimindo 2x2,3x3,4x4...
            count = m_size - sub_m_size + 1;
            for (i2 = 0; i2 < count; i2++) 
            {
                for (j2 = 0; j2 < count; j2++) 
                {
                    soma_submatriz = 0;
                    for (i = 0; i < sub_m_size; i++) {
                        for (j = 0; j < sub_m_size; j++) { 
                        //  printf("%d ", matriz[i+i2][j+j2]);
                            soma_submatriz += matriz[i+i2][j+j2];
                        }
                        //printf("\n");
                    }
                    //printf("\n");
                    //printf("%d \n", soma_submatriz);
                    // Se a soma da submatriz for igual a s ,vai printar primeiro elemento da menor submatriz
                    if(soma_submatriz == s){
                        printf("submatriz %d x %d em [%d,%d]\n",i,j,i2+1,j2+1);
                        return 0;
                    }
                }   
            }
        }
    }
        // Se não tiver nenhum soma de submatriz igual a s,vai printar nao ha'
        printf("nao ha'\n");
}