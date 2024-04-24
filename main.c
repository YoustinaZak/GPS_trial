
#include "UART.h"
#include "GPIO.h"
#include "GPS.h"

int main(void)
	{
	 uint8_t i=0;
	
	 double Valid_Coordinates[NO_OF_COORDINATES][2];
	
	 PORTA_UART_INIT();
	 PORTD_UART_INIT();
	 PORTF_INIT();
	
	//printString("\n\rcode started befor while\n\r");
	
	while(1)
		{
			  
			 uint8_t input[50]={0};
			uint8_t old_array[MAX_FIELDS][MAX_FIELD_LENGTH];
			uint8_t GGA_Fields[MAX_FIELDS][MAX_FIELD_LENGTH];


			// GPIO_PORTF_DATA_R=0x4;
			 
			 //while((UART0_FR_R & (1<<5)) !=0){}
		//	printString("in while 1 \n\r ");
			
		
		 
		// while((UART0_FR_R & (1<<5)) !=0){}
					//	printString("in while 2 \n\r");
		 
		 Get_Data(input); //append string
			//printString("before if \n\r");
//
		 if(Check_GGA(input))
			 {
					//	printString("after if \n");
				 
				 //while((UART0_FR_R & (1<<5)) !=0){}
					 //printString("i have found GGA\n\r");
			 
				//GPIO_PORTF_DATA_R=0xE;
				  //printString(input);
				 split_str(input,GGA_Fields);
				 
		
				 	

					
				 		

				 	

          Get_Path_Coordinates(input,'h',GGA_Fields);	
          GPIO_PORTF_DATA_R=0xE;				 
					 
				 if(Check_fix(GGA_Fields[6][0])==1)  //means GGA_Fields is a valid string
					 {
						// GPIO_PORTF_DATA_R=0x8;
						 
						 //printString("checked fix correct\n");
						 //GPIO_PORTF_DATA_R=0x4;
						// Get_Path_Coordinates(input,'h');
						 //GPIO_PORTF_DATA_R=0xE;
						/* Valid_Coordinates[i][0]=Get_Path_Coordinates(input,'h');
						 Valid_Coordinates[i][1]=Get_Path_Coordinates(input,'v');
						 
						 
						GetChar_PC( Valid_Coordinates[i][0]);
						 UART0_DR_R='\n';
						 UART0_DR_R='\r';
					  GetChar_PC( Valid_Coordinates[i][1]);
						 UART0_DR_R='\n';
						 UART0_DR_R='\r';
						 i++;*/
					 }
					 				//GPIO_PORTF_DATA_R=0xE;

			 }
			 else
				 {
					 //GPIO_PORTF_DATA_R=0x2;
					 //printString("i have NOT found GGA\n");
					 //GPIO_PORTF_DATA_R=0x0;
				 }
			
    }
	return 0;
}