#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a=0;
    while(a!=3)
    {
        system("title Tente descobrir a senha KKK");
        int g=3;
        int aux1,aux2,aux3,aux4,aux5,aux6;
        int v;
        int vetorbvetora[6]={1,9,1,2,2,2};
        int i;
        printf("COLOCA A SENHA AI NAMORAL:");
        scanf("%i",&v);
        aux6=((v/1)-((v/10)*10));
        aux5=((v/10)-((v/100)*10));
        aux4=((v/100)-((v/1000)*10));
        aux3=((v/1000)-((v/10000)*10));
        aux2=((v/10000)-((v/100000)*10));
        aux1=((v/100000)-((v/1000000)*10));
        int vetor[6]= {aux1,aux2,aux3,aux4,aux5,aux6};
        if(vetorbvetora[1]==vetor[1] && vetorbvetora[2]==vetor[2])
            if(vetorbvetora[3]==vetor[3] && vetorbvetora[4]==vetor[4])
                if(vetorbvetora[5]==vetor[5] && vetorbvetora[0]==vetor[0])
                {
                    while(g==3)
                    {
                        printf("\n\n\n\n\n\n\n\n\n                                                    Tenha um bom dia :]");
                        system("color a");
                        system("color b");
                        system("color 4f");
                        system("color 0E");
                        system("cls");
                    }
                }

        a++;
    }
}

