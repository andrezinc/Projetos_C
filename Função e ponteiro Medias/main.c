#include <stdio.h>
#include <stdlib.h>
float Media(float *v, int t)
{ int i;
float Soma;
Soma= 0;
for (i = 0; i < t; i++)
Soma= Soma + v[i];
return (Soma/t); }
float DesvioMedio(float *v, int t) { int i;
float *d; // verifique esta etrutura
float Med;
Med = Media(v, t);
for (i = 0; i < t; i++)
d[i] = abs(v[i] - Med);
return(Media(d, t)); }

int ArmazenaNotas(float *v)
{ int i;
i=0;
printf("Digite as notas (-1 para encerrar)");
scanf("%f",&*v);
while (v[i]!= -1)
{ i = i+1;
scanf("%f", &v[i]); }
return (i); }
/*Função para determinar a média de uma
relação de números*/

int main() { int i, Quant, NotasBoas;
float *p, Med,a;
Quant = ArmazenaNotas(p);
Med = Media(p, Quant);
a=DesvioMedio(p, Quant);
NotasBoas = 0;
for (i = 0; i < Quant; i = i + 1)
if (p[i] > Med)
NotasBoas = NotasBoas + 1;
printf("Media das notas: %f \n", Med);
printf("Notas maiores que a media: %d",NotasBoas);
printf("Desvio medio %f",a); }
