#include<lpc214X.h>  


void i2c_init();
void i2c_start();
void i2c_write(char data);
unsigned char i2c_read();
void i2c_stop();
