#include<p18f4550.h>  // inclus�o da biblioteca do nosso pic
#include<delays.h>   // inclus�o da biblioteca do delay  
#include<adc.h>     // biblioteca adc p/ realisar as convers�es 


#pragma config  FOSC = INTOSC_EC ,PBADEN = OFF  
// inclus�o das configura��es basicas 

int cont; 
#define rs PORTCbits.RC0  //  instru��o ou informa��o
#define en PORTCbits.RC1 // enable
#define LCD PORTD        //define PORTD leva informa��o p/ LCD
void configura(void);  // declara fun��o configura
void iniciaLcd (void); //declara da fun��o inicia LCD
void escreveLcd_ (rom char *palavra ); //fun��o para escrever no LCD -- palavra
void escreveLcd (int num);            //fun��o para escrever no LCD -- numero 
void byteLcd (char dado, char tipo ); //retorno da fun��o byteLcd tipo/dado
void high_interrupt(void);

#pragma code high_vector=0x08
void interrupt_at_high_vector (void)
{
	_asm GOTO high_interrupt _endasm
}
#pragma code
#pragma interrupt high_interrupt //define que a interrup��o ser� de alta prioridade
void high_interrupt (void)
{
	if (INTCONbits.TMR0IF == 1)
	{ cont++;
	  TMR0L=6;
	  INTCONbits.TMR0IF=0;
	}
}                       
void main ()
{

configura();  //chama fun��o configura
iniciaLcd(); //chama fun��o iniciar LCD
OSCCONbits.IRCF1 = 1;
INTCONbits.PEIE = 1;
INTCONbits.TMR0IE= 1;

INTCONbits.INT0IF = 0;
T0CON= 0b11000001;
TMR0L=6;


while (1)
{unsigned int valor_analog,valor_temp,un,dz; 
int aux,t;
int i;


if(PORTBbits.RB0==0){ aux=0;}
if(PORTBbits.RB1==0){ aux=1;}
if(PORTBbits.RB2==0){ aux=2;}
if(aux==0){
	byteLcd(0x80, 0);
	escreveLcd_("Tartaruga");
	t=2;
	i=6;
}
else if(aux==1){
	byteLcd(0x80, 0);
	escreveLcd_("Galinha  ");
	t=3;	
	i=7;
}
else if(aux==2){
	byteLcd(0x80, 0);
	escreveLcd_("Cogumelos");
	t=2;
	i=3;
}
else {
	byteLcd(0x80, 0);
	escreveLcd_("Er00r");
	
}
ConvertADC();   // convers�o
while(BusyADC());   //espera o fim da convers�o
valor_analog = ReadADC(); // le a convers�o 
valor_temp =5 * valor_analog * 100/ 1024;  //conver��o pra grau celsius
    // 5 = VCC              //100 = varia��o = 100mv   10 bits 
dz = valor_temp / 10;  //fazer ajustes para valores de tens�o e erros internos
un = valor_temp % 10;
byteLcd(0xC0, 0);//segunda linha
escreveLcd(dz);  // dezena 
escreveLcd(un); // unidade
escreveLcd_(" Graus Celsius");

if(dz>t){
PORTBbits.RB4=1;
}	
else if(dz==t && un>(i)){
	PORTBbits.RB4=1;
	Delay10KTCYx(5);
	PORTBbits.RB4=0;
	Delay10KTCYx(5);
	PORTBbits.RB4=1;
	Delay10KTCYx(10);}
else { PORTBbits.RB4=0;}
if(dz==t && un<(i)){
if(cont==1000){
	PORTBbits.RB3 =~PORTBbits.RB3;
	cont=0;
}
}
else if( dz<t ){
if(cont==1000){
	PORTBbits.RB3 =~PORTBbits.RB3;
	cont=0;
}
	}
else {PORTBbits.RB3=0; }
}
}

// fun��o configura
void configura()
{
TRISB = 0b00000111;
TRISD = 0b00000000; // tudo como saida 
TRISC = 0b11111100; // apenas 2como saida 
TRISA = 0b10000000;       // apenas 1 como entrada 


ADCON0=0x01;
ADCON1=0x0B;
ADCON2=0b10110110;
} 

//fun��o que apresenta palavra definida 
void escreveLcd_ (rom char *palavra )
{
while(*palavra)
{
byteLcd(*palavra,1);
palavra++;
}
} 

//fun��o inicia LCD 
void iniciaLcd()
{
char aux;
         /*
        0X38 = 8 bits de dados; formato 5x7; duas linhas de caracteres
        0x0F = display ativo com cursor piscando;
        0x06 = desloca o cursor � direita com a entrada de um novo dado; 
        0x01 = limpa o display e retorna o cursor na primeira posi��o.
*/
char inicio[] = {0x38,0x0C,0X06,0X0}; //vetor de 4 posi��es
for(aux = 0; aux < 4; aux++)
{
/*
chamada da fun��o byteLcd que passa 2par�metros / 0 = significa uma instru��o

*/
byteLcd (inicio [aux], 0); 
}
}
//fun��o que apresenta palavra definida 
void escreveLcd (int palavra)//par�metro(char *palavra) como rom (mem�ria de programa) ponteiro aponta para a pr�xima letra
{
char x;
x = palavra + '0';
byteLcd (x,1);
}


// fun��o de comando do LCD 
void byteLcd (char dado, char tipo)
{
rs = tipo;      // Recebendo a instru��o
LCD = dado;    // Recebendo a posi��o do la�o
en = 1;       // Liga para inorma��o
Delay10KTCYx(5);
en = 0;      // Desliga p�s  informa��o
 
}
