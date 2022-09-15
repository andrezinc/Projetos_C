#include <stdio.h>
#include <stdlib.h>
float aba(int hg)
{
    int h,g;
    float notas[hg];
    h=notas[0];
    int i;
    for(i=0;hg>i;i++){
    printf("coloque as notas:");
    scanf("%f",&notas[i]);
    }
    printf("A quantidade de notas %c %i\n",130,hg);
    for(i=0;hg>i;i++){
    if(notas[i]>=7){
        printf("A nota %.2f %c maior(ou igual kkk) que sete\n",notas[i],130);
    }
    }
    for(i=0;hg>i;i++){
    if(notas[i]<7){

        printf("A nota %.2f %c menor que sete\n",notas[i],130);
    }
    }

}
int main()
{
    system("title Coloque as nota ai KKK");

    int a;
    printf("coloque a quantidade de notas que voc%c quer:",136);
    scanf("%i",&a);
    aba(a);
    printf("\n");
    scanf("%i");
}
