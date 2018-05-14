/*
 * POV.cpp
 *
 * Created: 26-07-2017 20:54:34
 * Author : DEVAL
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "ds1307.h"
#include "i2c.h"
#include "USART_128.h"
#define rpm 600			//setting the RPM of motor

int main(void)
{
	DDRD=0xFF;
	unsigned int i,sec,min,hr,u,v,w,x,y,z;
    float D=(60.0*1000000)/(rpm*360.0);				//Time taken to move by 1 degree in microseconds
	ds1307_init();
	USART_Init(51,1);
	//_delay_ms(5000);
    while (1) 
    {
		ds1307_readtime(&sec, &min, &hr);				//Reading the time from RTC
		sec = ((sec & 0x70)>>4)*10 + (sec & 0x0F);				
		min = ((min & 0x70)>>4)*10 + (min & 0x0F);
		hr = ((hr & 0x70)>>4)*10 + (hr & 0x0F);
		
		USART_TransmitNumber(sec,1);
		USART_TransmitNumber(min,1);
		USART_TransmitNumber(hr,1);
		_delay_ms(10);
		
		//PORTD=0b00000001;
		//_delay_us(6.0*D);
		u=hr/10;			//Ten's of Hour
		v=hr%10;			//Unit's of Hour
		w=min/10;			//Ten's of Minute
		x=min%10;			//Unit's of Minute
		y=sec/10;			//Ten's of Second
		z=sec%10;			//Unit's of Second
		/*PORTD=0xFF;
		_delay_us(6.0*D);
		PORTD=0b00000011;
		for(i=0;i<10;i++)
		_delay_us(6.0*D);
		PORTD=0b00000001;
		for(i=0;i<355;i++)
		_delay_us(6.0*D);*/
		/*PORTD=0x00;
		for(i=0;i<60;i++)
		_delay_us(6.0*D);
		PORTD=0xFF;
		for(i=0;i<60;i++)
		_delay_us(6.0*D);
		PORTD=0x00;
		for(i=0;i<60;i++)
		_delay_us(6.0*D);
		PORTD=0xFF;
		for(i=0;i<60;i++)
		_delay_us(6.0*D);
		PORTD=0x00;
		for(i=0;i<60;i++)
		_delay_us(6.0*D);
		PORTD=0xFF;
		for(i=0;i<60;i++)
		_delay_us(6.0*D);*/
		
		switch(w)			//Display Ten's of Minute
		{
			case 0:
				PORTD=0xFF;
				_delay_us(6.0*D);
				PORTD=(1<<0|1<<1|1<<7);
				for(i=0;i<3;i++)
				_delay_us(6.0*D);
				PORTD=0xFF;
				_delay_us(6.0*D);
				PORTD=0b00000001;
				_delay_us(6.0*D);
				break;
			case 1:
				PORTD=0xFF;
				_delay_us(6.0*D);
				PORTD=0b00000001;
				for(i=0;i<5;i++)
				_delay_us(6.0*D);
				break;
			case 2:
				PORTD=0b10011111;
				_delay_us(6.0*D);
				PORTD=0b10010011;
				for(i=0;i<3;i++)
				_delay_us(6.0*D);
				PORTD=0b11110011;
				_delay_us(6.0*D);
				PORTD=0b00000001;
				_delay_us(6.0*D);
				break;
			case 3:
				PORTD=0xFF;
				_delay_us(6.0*D);
				PORTD=0b10010011;
				for(i=0;i<4;i++)
				_delay_us(6.0*D);
				PORTD=1<<0;
				_delay_us(6.0*D);
				PORTD=0b00000001;
				_delay_us(6.0*D);
				break;
			case 4:
				PORTD=0xFF;
				_delay_us(6.0*D);
				PORTD=1<<0|1<<4;
				for(i=0;i<3;i++)
				_delay_us(6.0*D);
				PORTD=0b00011111;
				_delay_us(6.0*D);
				PORTD=0b00000001;
				_delay_us(6.0*D);
				break;
			case 5:
				PORTD=0b11110011;
				_delay_us(6.0*D);
				PORTD=0b10010011;
				for(i=0;i<3;i++)
				_delay_us(6.0*D);
				PORTD=0b10011111;
				_delay_us(6.0*D);
				PORTD=0b00000001;
				_delay_us(6.0*D);
				break;
			case 6:
				PORTD=0b11110011;
				_delay_us(6.0*D);
				PORTD=0b10010011;
				for(i=0;i<3;i++)
				_delay_us(6.0*D);
				PORTD=0xFF;
				_delay_us(6.0*D);
				PORTD=0b00000001;
				_delay_us(6.0*D);
				break;
			case 7:
				PORTD=0xFF;
				_delay_us(6.0*D);
				PORTD=1<<0|1<<1;
				for(i=0;i<4;i++)
				_delay_us(6.0*D);
				PORTD=0b00000001;
				_delay_us(6.0*D);
				break;
			case 8:
				PORTD=0xFF;
				_delay_us(6.0*D);
				PORTD=0b10010011;
				for(i=0;i<3;i++)
				_delay_us(6.0*D);
				PORTD=0xFF;
				_delay_us(6.0*D);
				PORTD=0b00000001;
				_delay_us(6.0*D);
				break;
			case 9:
				PORTD=0xFF;
				_delay_us(6.0*D);
				PORTD=0b10010011;
				for(i=0;i<3;i++)
				_delay_us(6.0*D);
				PORTD=0b10011111;
				_delay_us(6.0*D);
				PORTD=0b00000001;
				_delay_us(6.0*D);
				break;
		}
		_delay_us(6.0*D);
		PORTD=1<<2|1<<6;			//Display Colon
		_delay_us(6.0*D);
		PORTD=0b00000001;
		_delay_us(6.0*D);
		switch(v)			//Display Unit's of Hour
		{
			case 0:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=(1<<0|1<<1|1<<7);
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 1:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			for(i=0;i<5;i++)
			_delay_us(6.0*D);
			break;
			case 2:
			PORTD=0b10011111;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b11110011;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 3:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<4;i++)
			_delay_us(6.0*D);
			PORTD=1<<0;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 4:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=1<<0|1<<4;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b00011111;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 5:
			PORTD=0b11110011;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b10011111;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 6:
			PORTD=0b11110011;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 7:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=1<<0|1<<1;
			for(i=0;i<4;i++)
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 8:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 9:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b10011111;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
		}
		switch(u)			//Display Ten's of Hour
		{
			case 0:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=(1<<0|1<<1|1<<7);
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 1:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			for(i=0;i<5;i++)
			_delay_us(6.0*D);
			break;
			case 2:
			PORTD=0b10011111;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b11110011;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 3:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<4;i++)
			_delay_us(6.0*D);
			PORTD=1<<0;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 4:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=1<<0|1<<4;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b00011111;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 5:
			PORTD=0b11110011;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b10011111;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 6:
			PORTD=0b11110011;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 7:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=1<<0|1<<1;
			for(i=0;i<4;i++)
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 8:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 9:
			PORTD=0xFF;
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b10011111;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
		}
		for(i=0;i<120;i++)			//Leaving Blank Space
		_delay_us(D);
		switch(z)			//Display Unit's of Second
		{
			case 0:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=(1<<0|1<<1|1<<7);
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 1:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			for(i=0;i<5;i++)
			_delay_us(6.0*D);
			break;
			case 2:
			PORTD=0b10011111;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b11110011;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 3:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<4;i++)
			_delay_us(6.0*D);
			PORTD=1<<0;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 4:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=1<<0|1<<4;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b00011111;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 5:
			PORTD=0b11110011;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b10011111;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 6:
			PORTD=0b11110011;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 7:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=1<<0|1<<1;
			for(i=0;i<4;i++)
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 8:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 9:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b10011111;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
		}
		switch(y)			//Display Ten's of Second
		{
			case 0:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=(1<<0|1<<1|1<<7);
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 1:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			for(i=0;i<5;i++)
			_delay_us(6.0*D);
			break;
			case 2:
			PORTD=0b10011111;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b11110011;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 3:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<4;i++)
			_delay_us(6.0*D);
			PORTD=1<<0;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 4:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=1<<0|1<<4;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b00011111;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 5:
			PORTD=0b11110011;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b10011111;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 6:
			PORTD=0b11110011;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 7:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=1<<0|1<<1;
			for(i=0;i<4;i++)
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 8:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
			case 9:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b10011111;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			_delay_us(6.0*D);
			break;
		}
		PORTD=1<<2|1<<6;			//Display Colon
		_delay_us(6.0*D);
		PORTD=0b00000001;
		_delay_us(6.0*D);
		switch(x)			//Display Unit's of Minute
		{
			case 0:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=(1<<0|1<<1|1<<7);
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0xFF;
			_delay_us(6.0*D);
			break;
			case 1:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b00000001;
			for(i=0;i<4;i++)
			_delay_us(6.0*D);
			break;
			case 2:
			PORTD=0b10011111;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b11110011;
			_delay_us(6.0*D);
			break;
			case 3:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<4;i++)
			_delay_us(6.0*D);
			PORTD=1<<0;
			_delay_us(6.0*D);
			break;
			case 4:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=1<<0|1<<4;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b00011111;
			_delay_us(6.0*D);
			break;
			case 5:
			PORTD=0b11110011;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b10011111;
			_delay_us(6.0*D);
			break;
			case 6:
			PORTD=0b11110011;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0xFF;
			_delay_us(6.0*D);
			break;
			case 7:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=1<<0|1<<1;
			for(i=0;i<4;i++)
			_delay_us(6.0*D);
			break;
			case 8:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0xFF;
			_delay_us(6.0*D);
			break;
			case 9:
			PORTD=0xFF;
			_delay_us(6.0*D);
			PORTD=0b10010011;
			for(i=0;i<3;i++)
			_delay_us(6.0*D);
			PORTD=0b10011111;
			_delay_us(6.0*D);
			break;
		}
    }
	
	return 0;
}

