#include"I2C.h"
 
 void i2c_init()
{
	PINSEL0 = PINSEL0 | 0x00000050; /* Configure P0.2 and P0.3 as SCL0 and SDA0 respectively */
	I2C0CONSET = 0x40; /* Enable I2C  */
	I2C0SCLL = 0x32; /* I2C data rate 300Khz and 50% duty cycle */
	I2C0SCLH = 0x32; /* I2C data rate 300Khz and 50% duty cycle */
}

void i2c_start()
{
	I2C0CONSET=0x20;
	while((I2C0CONSET&0x08)==0);
	I2C0CONCLR=0x28;
}

void i2c_write(char data)
{
	I2C0DAT = data; /* Load data to be written into the data register */
	I2C0CONSET = 0x40; /* Enable I2C */
	while( (I2C0CONSET & 0x08) == 0 ); /* Wait till SI = 1 */
	I2C0CONCLR = 0x08;  /* Clear SI bit */

}


unsigned char i2c_read()
{
	I2C0CONSET = 0x44; /* Enable I2C with Acknowledge */
	while( (I2C0CONSET & 0x08) == 0 ); /* Wait till SI = 1 */
	I2C0CONCLR = 0x0C; /* Clear SI and Acknowledge bits */
	return I2C0DAT; /* Return received data */
}

void i2c_stop()
{
	I2C0CONSET = 0x50; /* Set Stop bit for Stop condition */
}