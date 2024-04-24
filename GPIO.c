
#include "GPIO.h"
#include "UART.H"







void PORTF_INIT(){  //7 steps of activating a gpio
	                  //activate clk for port F
	SYSCTL_RCGCGPIO_R |= 0x20;
	                  //wait until status bit changes
	while((SYSCTL_PRGPIO_R & 0x20)==0);
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;   //unlock
	GPIO_PORTF_CR_R|=0x1F;               //enable change 0 to 4
	GPIO_PORTF_DEN_R|=0x1F;	             //enable digital 0 to 4

	GPIO_PORTF_PCTL_R&=~0xFFF0;      //each pin has 4 bits to represent the function 0000=GPIO
	GPIO_PORTF_AFSEL_R&=~0xE; //alternate function enable clear
	GPIO_PORTF_AMSEL_R&=~0xE; //analog clear clear
	GPIO_PORTF_DIR_R |= 0xE;  //PF0 =0 PF1=1 PF2=1 PF3=1 PF4=0
	
}

void PORTA_INIT(){  //7 steps of activating a gpio
	                  //activate clk for port A
	SYSCTL_RCGCGPIO_R |= 0x01;
	                  //wait until status bit changes
	while((SYSCTL_PRGPIO_R & 0x01)==0);
	GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;   //unlock
	GPIO_PORTA_CR_R|=0xFF;               //enable change 0 to 4
	GPIO_PORTA_DEN_R|=0xFF;	             //enable digital 0 to 4

	GPIO_PORTA_PCTL_R&=~0xFFF0;      //each pin has 4 bits to represent the function 0000=GPIO
	GPIO_PORTA_AFSEL_R&=~0xE; //alternate function enable clear
	GPIO_PORTA_AMSEL_R&=~0xE; //analog clear clear
	GPIO_PORTA_DIR_R |= 0xE;  //PF0 =0 PF1=1 PF2=1 PF3=1 PF4=0
	
}
