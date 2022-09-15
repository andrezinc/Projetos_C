#include <stdio.h>
#include <stdlib.h>

int main()
{
    char h,s;
    int a=0,c=0,i,aux1,aux2,aux3,aux4,aux5,aux6,b;
    printf("coloque um numero(6 digitos ou menos digitos):");
    scanf("%i",&b);
    aux6=((b/1)-((b/10)*10));
    aux5=((b/10)-((b/100)*10));
    aux4=((b/100)-((b/1000)*10));
    aux3=((b/1000)-((b/10000)*10));
    aux2=((b/10000)-((b/100000)*10));
    aux1=((b/100000)-((b/1000000)*10));
    int vetorzao[6]= {aux1,aux2,aux3,aux4,aux5,aux6};
    for(i=0; i<=5; i++)
    {
        if(vetorzao[i]%2 == 0)
        {

            a=a+1;
            if(vetorzao[i]==NULL)
            {
                a--;
            }
        }
        else if(vetorzao[i]%2 != 0)
        {
            c=c+1;
            if(vetorzao[i]==NULL)
            {
                c--;
            }
        }
    }

    if(a>1 || a==0){
        h='s';
    }
    else
    if(a<1 && a!=0){
        h=0;
    }
    if(c>1 || c==0){
        s='s';
    }else
    if(c<1 && c!=0 ){
        s=0;
    }
    printf("Seu numero tem %i algarismo%c pares e %i algarismo%c impares",a,h,c,s);
    printf("\n");
    system("pause");
}
