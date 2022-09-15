# MPLAB IDE generated this makefile for use with GNU make.
# Project: projeto.mcp
# Date: Tue Dec 03 15:35:56 2019

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

projeto.cof : main.o
	$(LD) /p18F4550 /l"C:\Program Files (x86)\Microchip\mplabc18\v3.47\lib" "main.o" /u_CRUNTIME /u_DEBUG /z__MPLAB_BUILD=1 /z__MPLAB_DEBUG=1 /o"projeto.cof" /M"projeto.map" /W

main.o : main.c ../../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/delays.h ../../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/adc.h main.c ../../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18f4550.h ../../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18cxxx.h ../../../../../../../Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/pconfig.h
	$(CC) -p=18F4550 "main.c" -fo="main.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

clean : 
	$(RM) "main.o" "projeto.cof" "projeto.hex"

