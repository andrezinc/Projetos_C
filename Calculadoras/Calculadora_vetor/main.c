#include <stdio.h>
#include <stdlib.h>

float conversor(char calculo){
    float numeros;
    for (int i=0; i<10; i++){
        for(int o=0;o<10;i++){
        if(calculo==(48+o)){
            switch (o)
            {
            case 0:
                numeros=o;
                break;
            case 1:
                numeros=o;
                break;
            case 2:
                numeros=o;
                break;
            case 3:
                numeros=o;
                break;
            case 4:
                numeros=o;
                break;
            case 5:
                numeros=o;
                break;
            case 6:
                numeros=o;
                break;
            case 7:
                numeros=o;
                break; 
            case 8:
                numeros=o;
                break;  
            case 9:
                numeros=o;
                break;                       
            default:
                break;
            }
            }

        }
    }
    return(numeros);
}
int main()
{
    char a[50];
    printf("calculo:");
    scanf("%s",&a);

    float numeros[50];
    for(int l=0; l<10; l++){
        numeros[l]=conversor(a[l]);
    }

    for(int i=0; i<10;i++){
        printf("%.1f",numeros[i]);
    }
}
