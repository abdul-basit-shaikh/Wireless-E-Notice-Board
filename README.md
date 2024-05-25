# Wireless-E-Notice-Board
The main aim of the project is to display user defined message on dot matrix led display which represents the wireless E-Notice board by using Bluetooth technology.

HARDWRAE REQUIREMENTS:
 LPC2148
 4 - 8x8 DOT MATRIX DISPLAYS
 74HC573 (LATCH)
 74HC164 (SHIFT REGISTER)
 AT24C256 (EEPROM)
 HC-05 BLUETOOTH MODULE
 DB-9 CABLE/USB-UART CONVERTER

![image](https://github.com/abdul-basit-shaikh/Wireless-E-Notice-Board/assets/170273266/47882223-37fc-47eb-a993-7f1a5ce7404a)

SOFTWARE REQUIREMENTS:
	KEIL C Compiler
	PROGRAMMING IN EMBEDDED C
	Flash Magic

CONNECTIONS TO BE USED: 
DOT MATRIX DISPLAY: 
Dot matrix display connections are established with the help of two different IC’S. Those are 74HC164 (8-bit serial-in, parallel-out shift register) & 74HC573 (Octal D-type transparent latch).
74HC164: (below mention connections are for 4 dot matrix displays)

FOR DISPLAY1: 
	DSA (74HC164)		-	P0.8 
	CP (74HC164)		-	P0.9
	Q0 (74HC164)		-	COL1 (DOT MATRIX DISPLAY)
	Q1 (74HC164)		-	COL2 (DOT MATRIX DISPLAY)
	Q2 (74HC164)		-	COL3 (DOT MATRIX DISPLAY)
	Q3 (74HC164)		-	COL4 (DOT MATRIX DISPLAY)
	Q4 (74HC164)		-	COL5 (DOT MATRIX DISPLAY)
	Q5 (74HC164)		-	COL6 (DOT MATRIX DISPLAY)
	Q6 (74HC164)		-	COL7 (DOT MATRIX DISPLAY) 	
  Q7 (74HC164)		-	COL8 (DOT MATRIX DISPLAY)


FOR DISPLAY2: 
	DSA (74HC164)		-	P0.10
	CP (74HC164)		-	P0.11
  Q0 (74HC164)		-	COL1 (DOT MATRIX DISPLAY)
	Q1 (74HC164)		-	COL2 (DOT MATRIX DISPLAY)
	Q2 (74HC164)		-	COL3 (DOT MATRIX DISPLAY)
	Q3 (74HC164)		-	COL4 (DOT MATRIX DISPLAY)
	Q4 (74HC164)		-	COL5 (DOT MATRIX DISPLAY)
	Q5 (74HC164)		-	COL6 (DOT MATRIX DISPLAY)
	Q6 (74HC164)		-	COL7 (DOT MATRIX DISPLAY) 	
  Q7 (74HC164)		-	COL8 (DOT MATRIX DISPLAY)


FOR DISPLAY3: 
	DSA (74HC164)		-	P0.12
	CP (74HC164)		-	P0.13
  Q0 (74HC164)		-	COL1 (DOT MATRIX DISPLAY)
	Q1 (74HC164)		-	COL2 (DOT MATRIX DISPLAY)
	Q2 (74HC164)		-	COL3 (DOT MATRIX DISPLAY)
	Q3 (74HC164)		-	COL4 (DOT MATRIX DISPLAY)
	Q4 (74HC164)		-	COL5 (DOT MATRIX DISPLAY)
	Q5 (74HC164)		-	COL6 (DOT MATRIX DISPLAY)
	Q6 (74HC164)		-	COL7 (DOT MATRIX DISPLAY) 	
  Q7 (74HC164)		-	COL8 (DOT MATRIX DISPLAY)


FOR DISPLAY4: 
	DSA (74HC164)		-	P0.14
  CP (74HC164)		-	P0.15
  Q0 (74HC164)		-	COL1 (DOT MATRIX DISPLAY)
	Q1 (74HC164)		-	COL2 (DOT MATRIX DISPLAY)
	Q2 (74HC164)		-	COL3 (DOT MATRIX DISPLAY)
	Q3 (74HC164)		-	COL4 (DOT MATRIX DISPLAY)
	Q4 (74HC164)		-	COL5 (DOT MATRIX DISPLAY)
	Q5 (74HC164)		-	COL6 (DOT MATRIX DISPLAY)
	Q6 (74HC164)		-	COL7 (DOT MATRIX DISPLAY) 	
  Q7 (74HC164)		-	COL8 (DOT MATRIX DISPLAY)


For data input user has to use 0-7 pins on the dot matrix board. Check the dot matrix board for 0-7 pins. For better understanding refer the below mentioned details.

74HC164_1		-	0 - DSA
              1 - CP
74HC164_2		-	2 - DSA
              3 - CP
74HC164_3		-	4 - DSA
              5 - CP
74HC164_4		-	6 - DSA
              7 – CP
              
74HC573:
D0 (74HC573)	-	P0.0 
D1 (74HC573)	-	P0.1 
D2 (74HC573)	-	P0.2 
D3 (74HC573)	-	P0.3 
D4 (74HC573)	-	P0.4 
D5 (74HC573)	-	P0.5 
D6 (74HC573)	-	P0.6 
D7 (74HC573)	-	P0.7 

Q0 (74HC573)	-	ROW8 (DOT MATRIX DISPLAY)
Q1 (74HC573)	-	ROW7 (DOT MATRIX DISPLAY)
Q2 (74HC573)	-	ROW6 (DOT MATRIX DISPLAY)
Q3 (74HC573)	-	ROW5 (DOT MATRIX DISPLAY)
Q4 (74HC573)	-	ROW4 (DOT MATRIX DISPLAY)
Q5 (74HC573)	-	ROW3 (DOT MATRIX DISPLAY)
Q6 (74HC573)	-	ROW2 (DOT MATRIX DISPLAY)
Q7 (74HC573)	-	ROW1 (DOT MATRIX DISPLAY)


SEQUENCE TO BE FOLLOWED FOR IMPLEMENTATION:
	Create New Folder in your server save that folder with your project name and use same folder for required files for your project completion.
	First write one simple program to display one character on the single dot matrix led (Already sample code was uploaded in LMS card. So, download and utilise that code)
	Then write a program to display four-character string on the four-dot matrix Led’s
Example: HELP
	Then prepare code for string scrolling on the four-dot matrix Led’s (which has to display scrolling more than 10 characters string) 
Example: PROJECT SUCUSSFULLY COMPLETED
➢	Next write n bytes into EEPROM and read that n number of bytes from EEPROM and display on LCD.
➢	Next store one user define string in to EEPROM and read that string from EEPROM then scroll that string on dot matrix LED.
➢	Next check uart peripheral by transmitting character constant, string constant and receive string constant using UART logic. (Note: use uart interrupt concept)
➢	Then check the Bluetooth module working condition with the help of PC interface. Take care while connecting to the system. Bluetooth module is giving the TTL voltage levels so be cautious while connecting to the PC for checking purpose. If wrong connections given Bluetooth module will damage.
➢	For checking Bluetooth module first need to install HC-05 terminal application in the android mobile from play store then need to pair to Bluetooth module then send the required data from android mobile to Bluetooth module.
➢	Then in continuous loop, read the EEPROM memory locations to get the latest message and scroll that message on dot matrix LED. if any new message received from the Bluetooth, then stop the scrolling and update the new message into EEPROM specified memory locations. And this updated message needs to scroll on dot matrix LED until receiving the new message.
