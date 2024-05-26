#include <LPC21xx.h>
#include "types.h"
#include "uart.h"

#define FOSC 12000000
#define CCLK 5*FOSC
#define PCLK CCLK/4
#define PREINT_VAL ((PCLK/32768)-1)
#define PREFRAC_VAL (PCLK - ((PREINT_VAL + 1) * 32768))


void initRTC(void){
	PREINT=PREINT_VAL;
  PREFRAC=PREFRAC_VAL;
	CCR=0x01; //timer started
}


void setTime(u32 hr, u32 min, u32 sec, u32 dow, u32 dom, u32 month, u32 year){
	CCR=0x02;
	
	if(sec<=59) SEC=sec;
	else strUART("Incorrect seconds\r\n");

	if(min<=59) MIN=min;
	else strUART("Incorrect minutes\r\n");

	if(hr<=23) HOUR=hr;
	else strUART("Incorrect hour\r\n");

	if(1<=dom && dom<=31) DOM=dom;
	else strUART("Incorrect date\r\n");

	if(dow<=6) DOW=dow;
	else strUART("Incorrect day of week\r\n");

	if(1<=month && month<=12) MONTH=month;
	else strUART("Incorrect Month\r\n");

	if(year<=4096) YEAR=year;
	else strUART("Incorrect year\r\n");
	
	CCR=0x01;
}

void setSecond(u32 sec){
	CCR=0x02;
	SEC=sec;
	CCR=0x01;
}

void setMinute(u32 min){
	CCR=0x02;
	MIN=min;
	CCR=0x01;
}

void setHour(u32 hr){
	CCR=0x02;
	HOUR=hr;
	CCR=0x01;
}

void setDOW(u32 dow){
	CCR=0x02;
	DOW=dow;
	CCR=0x01;
}

void setDOM(u32 dom){
	CCR=0x02;
	DOM=dom;
	CCR=0x01;
}

void setMonth(u32 mon){
	CCR=0x02;
	MONTH=mon;
	CCR=0x01;
}

void setYear(u32 year){
	CCR=0x02;
	YEAR=year;
	CCR=0x01;
}



