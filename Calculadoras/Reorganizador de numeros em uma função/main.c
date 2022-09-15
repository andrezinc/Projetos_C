#include <stdio.h>
#include <stdlib.h>
#define i 10
int main()
{
    system("title mostra o maior e o menor ;-; KKK");
    int g;
    int a[i]= {-4,5,120,-530,2,6,10,4,5,6};
    int h=a[0];
    for(g=0; g<i; g++)
        if(a[g]>h)
            h=a[g];
    printf("%i e",h);
    for(g=0; g<i; g++)
        if(a[g]< h)
            h=a[g];
    printf("%i",h);

}
