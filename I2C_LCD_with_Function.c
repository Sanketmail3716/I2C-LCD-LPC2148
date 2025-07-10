#include<lpc214X.h>           
#include"LCD_I2C.h"
#include"I2C.h" 



void Delay(unsigned int );          


void main (void)
{ PINSEL0|=0x00000000;
	PINSEL1|=0x00000000;
	PINSEL2|=0x00000000;
  i2c_init();
  LCD_Init(0x4E);
	LCD_Write_String("Hello, Sanket");
    while(1)                
    {
				 
					  
			
		}
}

void Delay(unsigned int time)
{
    int j;
    int i;
    for(i=0;i<time;i++)
    {
        for(j=0;j<60000;j++)
        {
        }
    }
}


 

