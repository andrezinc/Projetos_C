#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y,v,i,b,g[10];
    for(i=0; i<10; i++)
    {
        printf("Digite o %i%c numero: ",i+1,167);
        scanf("%i",&g[i]);
    }
    y=0;
    while(y==0)
    { y=1;
        for(b=0; b<9; b++)
        {
            if(g[b]>g[b+1])
            {
                v=g[b];
                g[b]=g[b+1];
                g[b+1]=v;
                y=0;
            }
        }

    }
    for(b=0;b<=9;b++){
        printf("%i,",g[b]);
    }
    printf("Fim.");
    scanf("%i",&b);





}
