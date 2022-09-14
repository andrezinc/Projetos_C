#include <stdio.h>
#include <stdlib.h>

float conversor(char calculo);

int main()
{
    char a[50];
    printf("calculo:");
    scanf("%s", &a);

    float numeros[50];
    for (int l = 0; l < 50; l++)
    {
        numeros[l] = conversor(a[l]);
    }

    for (int i = 0; i < 50; i++)
    {
        printf(" %.1f ", numeros[i]);
    }
}

float conversor(char calculo)
{
    float numeros;

    numeros = 0;

    for (int o = 48; o <= 57; o++)
    {
        if (calculo == (o))
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
            return numeros;
        }
    }
}