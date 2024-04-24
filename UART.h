#include "STD_TYPES.h"
#include "GPIO.h"

#ifndef UART_H_
#define UART_H_

#define GPIO_PORTA_BASE *((volatile uint32_t*) 0x40004000)
#define UART_GPIO_PORT  GPIO_PORTA_BASE
#define GPIO_TX         GPIO_PORTA_P1   //?
#define GPIO_RX         GPIO_PORTA_P0   //?
#define BAUD_RATE       9600
#define int_BRD         (uint8_t)(16000000 / (16 * BAUD_RATE))  //=104.1677
#define float_BRD       (uint8_t)(0.1677 * 64 + 0.5)  //=11
//(BRD = BRDI + BRDF = UARTSysClk / (ClkDiv * Baud Rate))
//UARTFBRD[DIVFRAC] = integer(0.8507 * 64 + 0.5) = 54

#define SYSCTL_RCGCUART_R       (*((volatile uint32_t *)0x400FE618))
#define SYSCTL_PRUART_R         (*((volatile uint32_t *)0x400FEA18))


#define UART0_DR_R              (*((volatile unsigned long *)0x4000C000))
#define UART0_RSR_R             (*((volatile unsigned long *)0x4000C004))
#define UART0_ECR_R             (*((volatile unsigned long *)0x4000C004))
#define UART0_FR_R              (*((volatile unsigned long *)0x4000C018))
#define UART0_ILPR_R            (*((volatile unsigned long *)0x4000C020))
#define UART0_IBRD_R            (*((volatile uint32_t *)0x4000C024)) //integer
#define UART0_FBRD_R            (*((volatile uint32_t *)0x4000C028)) //fraction
#define UART0_LCRH_R            (*((volatile uint32_t *)0x4000C02C))
#define UART0_CTL_R             (*((volatile unsigned long *)0x4000C030))
#define UART0_IFLS_R            (*((volatile unsigned long *)0x4000C034))
#define UART0_IM_R              (*((volatile unsigned long *)0x4000C038))
#define UART0_ICR_R             (*((volatile unsigned long *)0x4000C044))
#define UART0_DMACTL_R          (*((volatile unsigned long *)0x4000C048))
#define UART0_9BITADDR_R        (*((volatile unsigned long *)0x4000C0A4))
#define UART0_9BITAMASK_R       (*((volatile unsigned long *)0x4000C0A8))
#define UART0_PP_R              (*((volatile unsigned long *)0x4000CFC0))
#define UART0_CC_R              (*((volatile unsigned long *)0x4000CFC8))

#define UART2_DR_R              (*((volatile unsigned long *)0x4000E000))
#define UART2_RSR_R             (*((volatile unsigned long *)0x4000E004))
#define UART2_ECR_R             (*((volatile unsigned long *)0x4000E004))
#define UART2_FR_R              (*((volatile unsigned long *)0x4000E018))
#define UART2_ILPR_R            (*((volatile unsigned long *)0x4000E020))
#define UART2_IBRD_R            (*((volatile unsigned long *)0x4000E024))
#define UART2_FBRD_R            (*((volatile unsigned long *)0x4000E028))
#define UART2_LCRH_R            (*((volatile unsigned long *)0x4000E02C))
#define UART2_CTL_R             (*((volatile unsigned long *)0x4000E030))
#define UART2_IFLS_R            (*((volatile unsigned long *)0x4000E034))
#define UART2_IM_R              (*((volatile unsigned long *)0x4000E038))
#define UART2_RIS_R             (*((volatile unsigned long *)0x4000E03C))
#define UART2_MIS_R             (*((volatile unsigned long *)0x4000E040))
#define UART2_ICR_R             (*((volatile unsigned long *)0x4000E044))
#define UART2_DMACTL_R          (*((volatile unsigned long *)0x4000E048))
#define UART2_9BITADDR_R        (*((volatile unsigned long *)0x4000E0A4))
#define UART2_9BITAMASK_R       (*((volatile unsigned long *)0x4000E0A8))
#define UART2_PP_R              (*((volatile unsigned long *)0x4000EFC0))
#define UART2_CC_R              (*((volatile unsigned long *)0x4000EFC8))
	
#define UART3_DR_R              (*((volatile unsigned long *)0x4000F000))
#define UART3_RSR_R             (*((volatile unsigned long *)0x4000F004))
#define UART3_ECR_R             (*((volatile unsigned long *)0x4000F004))
#define UART3_FR_R              (*((volatile unsigned long *)0x4000F018))
#define UART3_ILPR_R            (*((volatile unsigned long *)0x4000F020))
#define UART3_IBRD_R            (*((volatile unsigned long *)0x4000F024))
#define UART3_FBRD_R            (*((volatile unsigned long *)0x4000F028))
#define UART3_LCRH_R            (*((volatile unsigned long *)0x4000F02C))
#define UART3_CTL_R             (*((volatile unsigned long *)0x4000F030))
	
#define UART5_DR_R              (*((volatile unsigned long *)0x40011000))
#define UART5_RSR_R             (*((volatile unsigned long *)0x40011004))
#define UART5_ECR_R             (*((volatile unsigned long *)0x40011004))
#define UART5_FR_R              (*((volatile unsigned long *)0x40011018))
#define UART5_ILPR_R            (*((volatile unsigned long *)0x40011020))
#define UART5_IBRD_R            (*((volatile unsigned long *)0x40011024))
#define UART5_FBRD_R            (*((volatile unsigned long *)0x40011028))
#define UART5_LCRH_R            (*((volatile unsigned long *)0x4001102C))
#define UART5_CTL_R             (*((volatile unsigned long *)0x40011030))
	

void PORTA_UART_INIT();
void PORTD_UART_INIT();
void UART2_Init();
void UART5_INIT();
char GetChar_PC();
char readChar();
char printChar();
void transChar();
void printString( char* x);
void printString2( char* x);
#endif 