#include<p18f4550.h>  // inclusão da biblioteca do nosso pic
#include<delays.h>   // inclusão da biblioteca do delay  
#include<adc.h>     // biblioteca adc p/ realisar as conversões 


#pragma config  FOSC = INTOSC_EC ,PBADEN = OFF  
// inclusão das configurações basicas 

int cont; 
#define rs PORTCbits.RC0  //  instrução ou informação
#define en PORTCbits.RC1 // enable
#define LCD PORTD        //define PORTD leva informação p/ LCD
void configura(void);  // declara função configura
void iniciaLcd (void); //declara da função inicia LCD
void escreveLcd_ (rom char *palavra ); //função para escrever no LCD -- palavra
void escreveLcd (int num);            //função para escrever no LCD -- numero 
void byteLcd (char dado, char tipo ); //retorno da função byteLcd tipo/dado
void high_interrupt(void);

#pragma code high_vector=0x08
void interrupt_at_high_vector (void)
{
	_asm GOTO high_interrupt _endasm
}
#pragma code
#pragma interrupt high_interrupt //define que a interrupção será de alta prioridade
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

configura();  //chama função configura
iniciaLcd(); //chama função iniciar LCD
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
ConvertADC();   // conversão
while(BusyADC());   //espera o fim da conversão
valor_analog = ReadADC(); // le a conversão 
valor_temp =5 * valor_analog * 100/ 1024;  //converção pra grau celsius
    // 5 = VCC              //100 = variação = 100mv   10 bits 
dz = valor_temp / 10;  //fazer ajustes para valores de tensão e erros internos
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

// função configura
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

//função que apresenta palavra definida 
void escreveLcd_ (rom char *palavra )
{
while(*palavra)
{
byteLcd(*palavra,1);
palavra++;
}
} 

//função inicia LCD 
void iniciaLcd()
{
char aux;
         /*
        0X38 = 8 bits de dados; formato 5x7; duas linhas de caracteres
        0x0F = display ativo com cursor piscando;
        0x06 = desloca o cursor à direita com a entrada de um novo dado; 
        0x01 = limpa o display e retorna o cursor na primeira posição.
*/
char inicio[] = {0x38,0x0C,0X06,0X0}; //vetor de 4 posições
for(aux = 0; aux < 4; aux++)
{
/*
chamada da função byteLcd que passa 2parâmetros / 0 = significa uma instrução

*/
byteLcd (inicio [aux], 0); 
}
}
//função que apresenta palavra definida 
void escreveLcd (int palavra)//parâmetro(char *palavra) como rom (memória de programa) ponteiro aponta para a próxima letra
{
char x;
x = palavra + '0';
byteLcd (x,1);
}


// função de comando do LCD 
void byteLcd (char dado, char tipo)
{
rs = tipo;      // Recebendo a instrução
LCD = dado;    // Recebendo a posição do laço
en = 1;       // Liga para inormação
Delay10KTCYx(5);
en = 0;      // Desliga pós  informação
 
}
