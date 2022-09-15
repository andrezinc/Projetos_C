#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int vetorCcruzado2[2];
    int vetorCcruzado[2];
    int vetorCreto[2];
    int vetorA[2];
    int vetorB[2];
    for(i=0;i<2;i++){
    printf("\ncoloque os valores da coluna A%i:",i+1);
    scanf("%i",&vetorA[i]);
}
    for(i=0;i<2;i++){
        printf("\ncoloque os valores da coluna B%i:",i+1);
        scanf("%i",&vetorB[i]);
    }
    for(i=0;i<2;i++){
        vetorCreto[i]=(vetorB[i]+vetorA[i]);
        printf("A soma do linha %i do vetor A com a linha %i do vetor B %c %i\n",i+1,i+1,130,vetorCreto[i]);
        if(i==1){
        vetorCcruzado[i]=(vetorB[i]+vetorA[i-1]);
        printf("A soma cruzada da linha %i do vetor A com a linha %i do vetor B %c %i\n",i,i+1,130,vetorCcruzado[i]);
        }
        if(i==0){
            vetorCcruzado2[i]=(vetorB[i]+vetorA[i+1]);
            printf("A soma cruzada da linha %i do vetor A com a linha %i do vetor B %c %i\n",i+2,i+1,130,vetorCcruzado2[i]);

        }
    }
    system("pause");
}
