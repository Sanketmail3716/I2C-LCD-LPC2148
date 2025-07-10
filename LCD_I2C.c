
#include"LCD_I2C.h"
unsigned char RS,i2c_add;

void LCD_Init(unsigned char I2C_Add) 
{
  i2c_add = I2C_Add;
  LCD_start(0x00);
  Delay(5);

  LCD_CMD(LCD_RETURN_HOME);//0x02
  Delay(5);
  LCD_CMD(0x20 | (LCD_TYPE << 2));
  Delay(5);
  LCD_CMD(LCD_TURN_ON);
  Delay(5);
  LCD_CMD(LCD_CLEAR);
  Delay(5);
  LCD_CMD(LCD_ENTRY_MODE_SET | LCD_RETURN_HOME);
  Delay(5);
}


void LCD_start(unsigned int Data)
{
   i2c_start();
	 i2c_write(i2c_add);
	 i2c_write(Data | LCD_BACKLIGHT );
   i2c_stop();
}

void LCD_Write_4Bit(unsigned char Nibble) 
{
  // Get The RS Value To LSB OF Data  
  Nibble |= RS; // 0b00100000 |0b00000000 =>0b00100000
  LCD_start(Nibble | 0x04);// 0b00100000 | 0b00000100 =>0b00100100
  LCD_start(Nibble & 0xFB);// 0b00100000 & 0b11111011 =>0b00100000
  Delay(5);
}
void LCD_CMD(unsigned char CMD) 
{
  RS = 0; // Command Register Select
  LCD_Write_4Bit(CMD & 0xF0); // 0x28=>0b00101000 & Ob11110000=>0b00100000
  LCD_Write_4Bit((CMD << 4) & 0xF0);// (0x28<<4)=>0b10000000 & Ob11110000=>0b10000000
}

void LCD_Write_Char(char Data)
{
  RS = 1;  // Data Register Select
  LCD_Write_4Bit(Data & 0xF0);
  LCD_Write_4Bit((Data << 4) & 0xF0);
}

void LCD_Write_String(char* Str)
{
    for(int i=0; Str[i]!='\0'; i++)
     LCD_Write_Char(Str[i]); 
}