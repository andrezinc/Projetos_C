#include <stdio.h>
#include <stdlib.h>


float soma(float x, float y);
float sub(float x, float y);
float divisao(float x, float y);
float multip(float x, float y);

int main()
{
    
    float a,b;
    char c;
    
    printf("Faça algumas das operações entre dois numeros ( * ,/ ,- ,+ ): ");
    scanf("%f%c%f",&a,&c,&b);

    
    switch (c)
    {
    case '+':
        
        printf("%.2f",soma(a,b));
        break;
    case '-':
        
        printf("%.2f",sub(a,b));
        break;
    case '/':
        
        printf("%.2f",divisao(a,b));
        break;
    case '*':
        
        printf("%.2f",multip(a,b));
        break;

    default:
        printf("Desculpe não entendi :/ ");
        break;
    }

}
float soma(float x,float y){
    return(x+y);
}
float sub(float x,float y){
    return(x-y);
}
float divisao(float x,float y){
    return(x/y);
}
float multip(float x,float y){
    return(x*y);
}
