#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int conversor(char calculo);
int contador(char calculo);
int uniao(int calculo, int numero);

int k,kl;
k=0;
kl=0;
int main()
{
    char a[50];
    int numeros[50],operac[50],testando[50];
    int l,bn;
    printf("calculo:(final '=')");
    scanf("%s", &a);
    for (l = 0; l < 50; l++)
    {
        numeros[l] = conversor(a[l]); // cada numero dentro da string "a" passa pelo conversor
        operac[l]=contador(a[l]);// cada caracter é analisado dentro da função e é mostrado a posição dos caracteres;
        bn=operac[l];
        testando[l]=uniao(numeros[l],bn);
    }

    for (int i = 0; i < 50; i++)
    {
      // printf("\n numero: %i operac :%i ", numeros[i], operac[i]); // aparece na tela
    }

}

int conversor(char calculo)
{
    int numeros;
    numeros = 0;
    for (int o = 48; o <= 57; o++) // dentro da função se faz a comparação 10 vezes para percorrer no espectro ASCII dos caracters
    {
        if (calculo == (o)) // caso o numero dentro da string for o mesmo numero ele retorna como valor float
        {
            switch (o)
            {
            case 48:
                numeros = 0;
                break;
            case 49:
                numeros = 1;
                break;
            case 50:
                numeros = 2;
                break;
            case 51:
                numeros = 3;
                break;
            case 52:
                numeros = 4;
                break;
            case 53:
                numeros = 5;
                break;
            case 54:
                numeros = 6;
                break;
            case 55:
                numeros = 7;
                break;
            case 56:
                numeros = 8;
                break;
            case 57:
                numeros = 9;
                break;
            default:
                break;
            }
            return numeros; // retorna o numero para o vetor
        }
        
    }
}
int contador(char calculo){
    k++;
    if(calculo=='+'||calculo=='-'||calculo=='/'||calculo=='*'||calculo=='=')
    {     
        return k;
    }
    else return 0;
}

int uniao(int calculo, int numero){
    int vetor[50],a,vetor1[50],b,c,d,e;
    b=0;
    d=0;
    e=0;
    vetor[0]=0;
    a=numero;
    kl++;
    vetor[kl]=calculo;
    printf("entrada: %i",vetor[kl]);
    printf(" a: %i",numero);
    if(numero!=0){
        for(c=(a-1);c>0;c--){
            d++;
            printf("vetordnv:%i c:%i a:%i ",vetor[d],c,(a-1));
            e=(int)(pow(10,(c-1))+0.5);
            printf(" e: %i ",e);
            b=b+(vetor[d]*e);
            printf("b: %i",b);
        }
    }
    
}