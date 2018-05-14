#ifndef i2c_h
#define i2c_h
#include <avr/io.h>
#include <util/twi.h>

void i2c_init(void);
void i2c_start(void);
void i2c_repeatstart(void);
void i2c_stop(void);
void i2c_slaveaddress(unsigned int);
unsigned int i2c_read_ack(void);
unsigned int i2c_read_nack(void);
void i2c_write(unsigned int data);



#endif