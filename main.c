/*
 * main.c    ATmega32    F_CPU = 8000000 Hz
 * 
 * Created on: 2020-08-05
 *     Author: admin
*/                            
#include <avr/io.h>
#include "hd44780.h"
#include "ds18b20.h"                                       
#include <stdlib.h>
#include <stdio.h>                        
     
                           
int main (void){                                                          
    char bufor[8];
    float temperatura;                                            
    LCD_Initalize();                                 
                                                                
    while(1){                                                                           
        LCD_GoTo(4,0);                                                                        
        LCD_WriteText("DS18B20:           ");                         
        temperatura=ds18b20_gettemp();        
        sprintf(bufor,"Temp=%1.1f", temperatura);        
        LCD_GoTo(0,1);                            
        LCD_WriteText(bufor);                                                  
    }                                                           
}            