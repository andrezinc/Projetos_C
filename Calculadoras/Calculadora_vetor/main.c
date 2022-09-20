#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int conversor(char calculo);
int contador(char calculo);
int uniao(int calculo, int numero);
int operacoes(int uniao, char x, char *p, int d);

int k, kl, km, ke, d, operadoropera;
ke = 0;
operadoropera = 0;
d = 0;
k = 0;
km = 0;
kl = 0;
int main()
{
    char a[50], *ponteiro;
    int numeros[50], operac[50], testando[50], resultado;
    int l, bn;
    printf("coloque os numeros seguidos das seguintes operacoes:(+(soma),-(subtra),*(mult),/(divisao)) coloque no final '=')");
    scanf("%s", &a);
    ponteiro = &a;
    for (l = 0; l < 50; l++)
    {
        numeros[l] = conversor(a[l]); // cada numero dentro da string "a" passa pelo conversor
        operac[l] = contador(a[l]);   // cada caracter é analisado dentro da função e é mostrado a posição dos caracteres;
        bn = operac[l];
        testando[l] = uniao(numeros[l], bn);

        //
    }

    for (int i = 0; i < 50; i++)
    {
        resultado = operacoes(testando[i], a[i], ponteiro, operac[i]);
        // printf("resultado:%i",resultado);
        //  printf("\n numero: %i operac :%i ", numeros[i], operac[i]); // aparece na tela
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
int contador(char calculo)
{
    k++;
    if (calculo == '+' || calculo == '-' || calculo == '/' || calculo == '*' || calculo == '=')
    {
        return k;
    }
    else
        return 0;
}

int uniao(int calculo, int numero)
{
    int vetor[50], a, vetor1[50], b, c, e, f;
    b = 0;
    e = 0;
    vetor[0] = 0;
    vetor1[0] = 0;
    a = numero;
    kl++;
    vetor[kl] = calculo;
    if (kl != 0 && kl == a)
    {
        ke++;
        vetor1[ke] = a;
        km = +vetor1[ke] - vetor1[ke - 1];
        // printf(" km: %i a:%i numero:%i ", km, a, numero);
        if (ke > 1)
        {
            d++;
        }
    }
    if (numero != 0)
    {
        for (c = (km - 1); c > 0; c--)
        {
            d++;
            e = (int)(pow(10, (c - 1)) + 0.5);
            b = b + (vetor[d] * e);
            // printf("vetor[d]:%i", vetor[d]);
        }
        // printf("b: %i ", b);
        return b;
    }
    else
        return 0;
}
int operacoes(int uniao, char x, char *p, int d)
{

    int vetor[50], resultado, l[50], aux;
    resultado = 0;
    char a;
    a = x;
    if (uniao != 0)
    {
        operadoropera++;
        vetor[operadoropera] = uniao;
        l[operadoropera] = (d - 1);
        aux = l[operadoropera - 1];
        if (operadoropera > 1 && p[aux] == 43)
        {
            vetor[operadoropera] = vetor[operadoropera - 1] + vetor[operadoropera];
            printf("resultado [%i]: %i ", operadoropera - 1, vetor[operadoropera]);
        }
        else if (operadoropera > 1 && p[aux] == 45)
        {
            vetor[operadoropera] = vetor[operadoropera - 1] - vetor[operadoropera];
            printf("resultado [%i]: %i ", operadoropera - 1, vetor[operadoropera]);
        }
        else if (operadoropera > 1 && p[aux] == 47)
        {
            vetor[operadoropera] = vetor[operadoropera - 1] / vetor[operadoropera];
            printf("resultado [%i]: %i ", operadoropera - 1, vetor[operadoropera]);
        }
        else if (operadoropera > 1 && p[aux] == 42)
        {
            vetor[operadoropera] = vetor[operadoropera - 1] * vetor[operadoropera];
            printf("resultado [%i]: %i ", operadoropera - 1, vetor[operadoropera]);
        }
    }
}