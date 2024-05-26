#include <LPC21XX.h>
#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "delay.h"

#include "rtc.h"
#include "i2c.h"
#include "uart.h"
#include "eeprom.h"
#include "dotMatrix.h"

#define ADR 0x50
#define DLY 50 // ms
#define MAX 250

#define ANO 8
#define DATA 16


/*u8 opt, mode='0';
u8 str1[5], str2[MAX];*/

u8 opt='3', mode='0', inp, flag=0;
u8 str1[5]="HELL", str2[MAX]="Bhavesh Kale";

u8 time[5], date[40];
u8 day[7][4]={"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

u32 strLen(u8 *str);
u8 chkInput(u8 *str);
void displayMode(void);
void uartMode(void);
void saveToEEPROM(void);
void readFromEEPROM(void);

int main(){
	initI2C();
	initRTC();
	initUART(9600);
	initDOTMAT(ANO, DATA);
	
	//saveToEEPROM();
	readFromEEPROM();
	
	while(1){
		while(mode=='0'){
			displayMode();
		}
		while(mode=='1'){
			uartMode();
		}
	}
}


void displayMode(void){
	switch(opt){
		case '1': // Display 4 char string
						strDOTMAT(str1, DLY);
						break;

		case '2': // Display 4 char string with blinking
						strDOTMAT(str1, DLY);
						strDOTMAT("    ", DLY);
						break;

		case '3': // Display string with scrolling
						scrollDOTMAT(str2, DLY);
						delay_ms(DLY);
						break;

		case '4': // Display time in format of "MMSS"
						sprintf(time, "%02d%02d\0", MIN, SEC);
						strDOTMAT(time, DLY);
						break;

		case '5': // Display time, date, day in format of "TIME:HH:MM:SS DATE:DD/MM/YYYY DAY:DAY"
						sprintf(date, "TIME:%02d:%02d:%02d DATE:%02d/%02d/%04d DAY:%s\0", 
																	HOUR, MIN, SEC, DOM, MONTH, YEAR, day[DOW]);
						scrollDOTMAT(date, DLY);
						delay_ms(DLY);
						break;
		}
}


void uartMode(void){
	u8 ch='\0', i=0;
	u8 new[23]="SS MM HH DD MM YYYY WW";
	
	strUART("1 - Display Fixed String\r\n");
	strUART("2 - Display Fixed Blinking String\r\n");
	strUART("3 - Display Scrolling String\r\n");
	strUART("4 - Time Display 'MMSS'\r\n");
	strUART("5 - Display Scrolling Time & Date\r\n");
	strUART("6 - Edit Fixed String\r\n");
	strUART("7 - Edit Scrollable String (MAX 250 CHARACTRES)\r\n");
	strUART("8 - Edit Time & Date\r\n");
	strUART("9 - Exit\r\n");
	
	strUART("Enter your Choise : ");
	while(flag==0);
	ch = inp;
	flag=0;
	
	strUART("\r\n");
	
	if(('1'<=ch && ch<='5') || ch=='9'){
		mode='0';		
		if('1'<=ch && ch<='5'){
			opt=ch;
			saveToEEPROM();
		}
	}
	else if(ch=='6'){
		i=0;
		strUART("Enter the 4 char string : ");
		while(i<4){
			while(flag==0);
			str1[i++]=inp;
			flag=0;
		}
		str1[4]='\0';
		strUART("\r\nString Updated\r\n\r\n");
		saveToEEPROM();
	}
	else if(ch=='7'){
		i=0;
		strUART("Enter the string and at end press 'enter': ");
		do{
			while(flag==0);
			ch=inp;
			flag=0;
			
			str2[i++]=ch;
			
			if(ch==0x0D){
				while(flag==0);
				ch=inp;
				flag=0;
				
				break;
			}
		} while(i<250);
		str2[--i]='\0';
		strUART("\r\nString Updated\r\n\r\n");
		saveToEEPROM();
	}
	else if(ch=='8'){
		strUART("Enter new time & date in below given format only\r\n");
		strUART("'HH MM SS WW DD MM YYYY' : ");
		while(i<22){
			while(flag==0);
			new[i++]=inp;
			flag=0;
		}
		new[22]='\0';

		
		if(chkInput(new)){
			setTime(atoi(new+0), atoi(new+3), atoi(new+6), atoi(new+9), atoi(new+12), atoi(new+15), atoi(new+18));
			strUART("\r\nDate & Time Updated\r\n\r\n");
		}
		else{
			strUART("\r\nincorrect input\r\n");
			strUART("Date & Time Not Updated\r\n\r\n");
		}
	}
	else{
		strUART("Wrong Choise\r\n\r\n");
	}
}


u32 strLen(u8 *str){
	u32 len=0;
	while(*str++) len++;
	return len;
}


u8 chkInput(u8 *str){
	u8 i=0;
	while(*str){
		if(i==2 || i==5 || i==8 || i==11 || i==14 || i==17){
			if(*str!=' ')
				return 0;
		}
		
		else{
			if(*str<48 && 57<*str)
					return 0;
		}
		
		str++;
		i++;
	}
	
	return 1;
}

void saveToEEPROM(void){
		u16 len=0;
		u8 page=64, flag=0, i=0, Adr=0x07;

        byteWriteEEPROM_I2C(ADR, 0x00, opt);
        pageWriteEEPROM_I2C(ADR, 0x01, str1, 4);
        len=strLen(str2);
        byteWriteEEPROM_I2C(ADR, 0x05, (len>>8)&0xFF);
		byteWriteEEPROM_I2C(ADR, 0x06, len&0xFF);
        pageWriteEEPROM_I2C(ADR, 0x07, str2, len);

		while(i<len){
			if(flag==0){
				pageWriteEEPROM_I2C(ADR, Adr+i, str2+i, ((len-i<page)?len-i:page));
				i+=page-7;
				flag=1;
			}
			else{
				pageWriteEEPROM_I2C(ADR, Adr, str2+i, ((len-i<page)?len-i:page));
				i+=page;
			}
		}
			
}

void readFromEEPROM(void){
        u16 len=0;

        opt=randReadEEPROM_I2C(ADR, 0x00);
        seqReadEEPROM_I2C(ADR, 0x01, str1, 4);
        str1[4]='\0';

        len|=(randReadEEPROM_I2C(ADR, 0x05)<<8);
		len|=randReadEEPROM_I2C(ADR, 0x06);

        seqReadEEPROM_I2C(ADR, 0x07, str2, len);
        str2[len]='\0';
}

