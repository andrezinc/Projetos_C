#include <stdio.h>
#include <stdlib.h>

int main()
{
    int w;
    w=1;
    while(w!=0)
    {
        int a,i,r,v,g,h,j;
        char vetor[77]="JaneiroFevereiroMarcoAbrilMaioJunhoJulhoAgostoSetembroOutubroNovembroDezembro";
        printf("\nDigite o numero do mes:");
        scanf("%i",&i);
            if(i==12)
            {
                for(h=0;h<8;h++){
                v=h+69;
                printf("%c",vetor[v]);
            }}
            if(i==11)
            {
                for(h=0;h<8;h++){
                v=h+61;
                printf("%c",vetor[v]);
                }
            }
            if(i==10)
            {
                for(h=0;h<7;h++){
                v=h+54;
                printf("%c",vetor[v]);
                }
            }
            if(i==9)
            {
               for(h=0;h<8;h++){
                v=h+46;
                printf("%c",vetor[v]);

            }}
            if(i==8)
            {
            for(h=0;h<6;h++){
                v=h+40;
                printf("%c",vetor[v]);

                }}
            if(i==7)
            {
                for(h=0; h<5; h++){
                v=h+35 ;
                printf("%c",vetor[v]);

            }}
            if(i==6)
            {
                for(h=0; h<5; h++){
                v=h+30;
                printf("%c",vetor[v]);
            }}
            if(i==5)
            {
                for(h=0; h<4; h++){
                v=h+26;
                printf("%c",vetor[v]);
            }}
            if(i==4)
            {
                for(h=0; h<5; h++){
                v=h+21;
                printf("%c",vetor[v]);
            }}
            if(i==3)
            {
                for(h=0; h<3; h++){
                v=h+16;
                printf("%c",vetor[v]);
                if(h==2){
                    printf("%co",135);
                }
}            }
            if(i==2)
            {
                for(h=0; h<9; h++)
                {
                    v=h+7;
                    printf("%c",vetor[v]);
                }

            }
            if(i==1)
            {
                for(h=0; h<7; h++)
                {
                    v=h;
                    printf("%c",vetor[v]);
                }
            }


        }

    }


