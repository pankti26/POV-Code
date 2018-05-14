#ifndef ds1307_h
#define ds1307_h
#include "i2c.h"
#include <avr/io.h>
#include <util/twi.h>

#define sec_address 0x00
#define min_address 0x01
#define hr_address 0x02
#define control_address 0x07


void ds1307_init(void);
unsigned int read_sec(void);
unsigned int read_min(void);
unsigned int read_hr(void);
void ds1307_readtime(unsigned int* sec,unsigned int* min,unsigned int* hr);
void ds1307_writetime(unsigned int ss, unsigned int mm, unsigned int hh);


#endif