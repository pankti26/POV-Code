/*
 * i2c.c
 *
 * Created: 27-07-2017 20:04:58
 *  Author: pankti26
 */ 
#include "i2c.h"

void i2c_init()
{
	TWSR = 0x00;
	TWBR=32;
}
void i2c_start(void)
{
	TWCR = (1<<TWINT | 1<<TWSTA | 1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != 0x08)
	{
		//ERROR
	}
}

void i2c_slaveaddress(unsigned int address)
{
	if(address==0xD0)
	{
		TWDR= 0xD0;
		TWCR = (1<<TWINT) | (1<<TWEN);
		while (!(TWCR & (1<<TWINT)));
		if ((TWSR & 0xF8) != 0x18)
		{
			//ERROR
		}
	}
	else if(address==0xD1)
	{
		TWDR= 0xD1;
		TWCR = (1<<TWINT) | (1<<TWEN);
		while (!(TWCR & (1<<TWINT)));
		if ((TWSR & 0xF8) != 0x40)
		{
			//ERROR
		}
		
	}
	
}


void i2c_write(unsigned int data)
{
	TWDR=data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != 0x28)
	{
		//ERROR
	}
}

unsigned int i2c_read_ack(void)
{
	unsigned int data;
	data = TWDR;
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != 0x50)
	{
		//ERROR
	}
	return(data);
}

unsigned int i2c_read_nack(void)
{
	unsigned int data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != 0x58)
	{
		//ERROR
	}
	data = TWDR;
	return(data);
}

void i2c_stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void i2c_repeatstart(void)
{
	TWCR |= 1<<TWINT | 1<<TWSTA | 1<<TWEN;
	while(!(TWCR & (1<<TWINT)));
	if ((TWSR & 0xF8) != 0x10)
	{
		//ERROR
	}
}