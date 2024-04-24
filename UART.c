#include "UART.h"


void PORTC_UART_INIT(){
	
}

void PORTA_UART_INIT(){
	//PORT INIT
	SYSCTL_RCGCGPIO_R |=0x01;
	while((SYSCTL_PRGPIO_R & 0x01)==0);
	GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTA_CR_R |=0x03;  //COMMIT INIT BEFORE PUR PDR DEN
	GPIO_PORTA_DEN_R |=0x03;
	
	//UART0 INIT
	SYSCTL_RCGCUART_R |=0x01;
	while((SYSCTL_PRUART_R & 0x1)==0);
	GPIO_PORTA_AFSEL_R |=0x03;   //pin 0 and 1 are alternate func
	
	GPIO_PORTA_PCTL_R |= 0x11;   //1 in decimal = uart (EACH PIN HAS 4 BITS)
	UART0_CTL_R &=~0x01;         //diable uart
	                             // baudrate must be written before LCRH
	UART0_IBRD_R = int_BRD ;
	UART0_FBRD_R = float_BRD;
	UART0_LCRH_R= (0<<7)|(11<<5);    //disable stick parity, 8bits, FIFO disabled, 1stop bit
	UART0_CC_R =0x05;
	UART0_CTL_R = (1<<0)|(1<<8)|(1<<9); //UART ENABLED, TX ENABLED, RX ENABLED
}


void PORTD_UART_INIT(){   
	//PORT INIT
	SYSCTL_RCGCGPIO_R |=0x08;
	while((SYSCTL_PRGPIO_R & 0x08)==0);

	GPIO_PORTD_CR_R |=(1<<6)|(1<<7);  //COMMIT INIT BEFORE PUR PDR DEN
	GPIO_PORTD_DEN_R |=(1<<6)|(1<<7); //0XC
	GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;
	SYSCTL_RCGCUART_R |=(1<<2);
	while((SYSCTL_PRUART_R &(1<<2))!=(1<<2));
	GPIO_PORTD_AFSEL_R |=(1<<6)|(1<<7);   //pin 0 and 1 are alternate func 0XC
	
	GPIO_PORTD_PCTL_R |= 0x11000000;   //1 in decimal = uart (EACH PIN HAS 4 BITS) pin 6 and pin 7
	UART2_CTL_R &=~0x01;         //diable uart
	                             // baudrate must be written before LCRH
	UART2_IBRD_R = int_BRD;
	UART2_FBRD_R = float_BRD;
	//UART2_LCRH_R= (0<<7)|(11<<5);    //disable stick parity, 8bits, FIFO disabled, 1stop bit
	UART2_LCRH_R= 0x60;
	//UART2_CC_R =0x05;                    //MSH MKTOB FL REPO
	UART2_CTL_R = (1<<0)|(1<<8)|(1<<9); //UART ENABLED, TX ENABLED, RX ENABLED
	
}

void UART2_Init() {
	   SYSCTL_RCGCUART_R |= 0x04;
	SYSCTL_RCGCGPIO_R |= 0x08;
	UART2_CTL_R &= ~0x01;          //disable UART5
	UART2_IBRD_R = 104;
	UART2_FBRD_R = 11;
	UART2_LCRH_R  |= 0x60;
	UART2_CTL_R |= 0x301;          //enable UART5
	GPIO_PORTD_AFSEL_R |= 0xC0;
	GPIO_PORTD_PCTL_R = 0x11000000;
	GPIO_PORTD_DEN_R |= 0xC0;
	//GPIO_PORTD_AMSEL_R &= ~0xC0 ; // disabling anlog functions for PE4 & PE5
}
void UART5_INIT(){              //PE4 = rx
	SYSCTL_RCGCUART_R |= 0x20;
	SYSCTL_RCGCGPIO_R |= 0x10;
	UART5_CTL_R &= ~0x01;          //disable UART5
	UART5_IBRD_R = 104;
	UART5_FBRD_R = 11;
	UART5_LCRH_R  |= 0x60;
	UART5_CTL_R |= 0x301;          //enable UART5
	GPIO_PORTE_AFSEL_R |= 0x30;
	GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R & ~0x00FF0000) | 0x00110000;
	GPIO_PORTE_DEN_R |= 0x30;
	GPIO_PORTE_AMSEL_R &= ~0x30 ; // disabling anlog functions for PE4 & PE5

}


char GetChar_PC(){
	while((UART0_FR_R & (1<<4))!=0){} //loop if receive holding reg is empty (y3ny estna l7d ma ygelk 7aga tst2blha)
		return UART0_DR_R; 
}

char GetChar_GPS(){
	while((UART2_FR_R & (1<<4)) !=0){} //CHECK RECEIVE REG
	return UART2_DR_R;
}

void transChar(){
	while((UART2_FR_R & (1<<4))!=0){} //loop if receive holding reg is empty (y3ny estna l7d ma ygelk 7aga tst2blha)
	while((UART0_FR_R & (1<<5)) !=0){} // loop if trans reg is not empty (y3ny estna l7d ma el f edak y5ls)
	UART0_DR_R=UART2_DR_R;
}

void printString( char* x){
    while(*x){
			while((UART0_FR_R & (1<<5)) !=0){}
		    UART0_DR_R= (*(x++));
		}
}

void printString2( char* x){
    while(*x){
			while((UART2_FR_R & (1<<5)) !=0){}
		    UART2_DR_R= (*(x++));
		}
}