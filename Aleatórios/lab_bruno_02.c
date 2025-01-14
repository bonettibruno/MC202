#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int duasvariaveis(int k ,int e)
{

    scanf("%d %d",&k,&e);
    if (k >0)
     return conjuntoDesculpas(k,e);
    else
    return 0;
}

int conjuntoDesculpas(int k,int e){
    // Variaveis
    char palavrachave[20];
    char desculpas[100];
    int countlinha = 2;
    
    while (countlinha <= k+2) {
        setbuf(stdin,0);
        fgets(palavrachave,20,stdin);
        palavrachave[strlen(palavrachave)-1] = '\0';
        printf("\n%s",palavrachave); 
        countlinha++;      
    }
    int countlinha1 = k + 2;
    while (countlinha1 <= k+e+1){
        setbuf(stdin,0);
        fgets(desculpas,100,stdin);
        desculpas[strlen(desculpas)-1] = '\0';
        printf("\n%s",desculpas); 
        countlinha1++;      
    }
    return duasvariaveis(k,e);
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    if(a >0)
        conjuntoDesculpas(a,b);
return 0;
}
 /*
                t=strlen(desculpas);
                for(i = 0; i < t; i++) 
                {
                //Passa de maiusculo para minusculo
                desculpas[i] = tolower(desculpas[i]); 
                printf("\n%s",desculpas);
                }*/