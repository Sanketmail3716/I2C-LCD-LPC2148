
#include<lpc214X.h>  


#define LCD_BACKLIGHT          0x08
#define LCD_NOBACKLIGHT        0x00
#define LCD_CLEAR              0x01
#define LCD_RETURN_HOME        0x02
#define LCD_ENTRY_MODE_SET     0x04
#define LCD_TURN_ON            0x0C
#define LCD_TURN_OFF           0x08
#define LCD_TYPE               2  


void LCD_Init(unsigned char I2C_Add) ;
void LCD_Write_String(char* Str);
void LCD_CMD(unsigned char CMD);
void LCD_Write_Char(char Data);
void LCD_start(unsigned int Data);
void LCD_Write_4Bit(unsigned char Nibble) ;
void LCD_Write_String(char* Str);