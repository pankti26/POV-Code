/*
 * ds1307.c
 *
 * Created: 29-07-2017 16:58:16
 *  Author: pankti26
 */ 


#include "ds1307.h"


void ds1307_init(void)
{
	i2c_init();
	i2c_start();
	i2c_slaveaddress(0xD0);
	i2c_write(control_address);
	i2c_write(0x00);
	i2c_stop();
}

unsigned int read_sec(void)
{
	unsigned int sec;
	i2c_start();
	i2c_slaveaddress(0xD0);
	i2c_write(sec_address);
	i2c_repeatstart();
	i2c_slaveaddress(0xD1);
	sec = i2c_read_nack();
	/*min = i2c_read_ack();
	*hr = i2c_read_nack();*/
	i2c_stop();
	return(sec);
}

unsigned int read_min(void)
{
	unsigned int min;
	i2c_start();
	i2c_slaveaddress(0xD0);
	i2c_write(min_address);
	i2c_repeatstart();
	i2c_slaveaddress(0xD1);
	min = i2c_read_nack();
	/*min = i2c_read_ack();
	*hr = i2c_read_nack();*/
	i2c_stop();
	return(min);
}

unsigned int read_hr(void)
{
	unsigned int hr;
	i2c_start();
	i2c_slaveaddress(0xD0);
	i2c_write(hr_address);
	i2c_repeatstart();
	i2c_slaveaddress(0xD1);
	hr = i2c_read_nack();
	/*min = i2c_read_ack();
	*hr = i2c_read_nack();*/
	i2c_stop();
	return(hr);
}

void ds1307_readtime(unsigned int* sec,unsigned int* min,unsigned int* hr)
{
	*sec = read_sec();
	*min = read_min();
	*hr = read_hr();
}
void ds1307_writetime(unsigned int ss, unsigned int mm, unsigned int hh)
{
	i2c_start();
	i2c_slaveaddress(0xD0);
	i2c_write(sec_address);
	i2c_write(ss);
	i2c_write(mm);
	i2c_write(hh);
	i2c_stop();
}
