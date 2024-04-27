#include <string.h>
#include <stdlib.h>
#include "UART.h"
#include "GPIO.h"
#include "GPS.h"

extern float Coordinates[10][2]={0};
int main()
	{
	  uint8_t i;
		uint8_t k;
		char N[]="43.1";
		
		char E[]="1131.000";
		//uint8_t  x;
	double latitude;
		
	  //float Valid_Coordinates[NO_OF_COORDINATES][2];
	
	 PORTA_UART_INIT();
		//UART0_DR_R=latitude;
	 //PORTD_UART_INIT();
	 PORTF_INIT();
	
	while(1)
		{
			 uint8_t input[]="$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47";
			//uint8_t input[]="ok";
			 //char num [10]= "4807.038" ; 
				//float fnm ; 
				
						//fnm = atof (num);
			 //uint8_t input[70]={0};
			//uint8_t GGA_Fields[4][10]={{"GPGGA"},{"1"},{"4807.038"},{"01131.000"}};
			split_str(input);
			if(Coordinates[0][0]>4807&&Coordinates[0][0]<4808){
				GPIO_PORTF_DATA_R=0xE;
			}
			//latitude=Coordinates[0][0];
			//uint8_t GGA_Fields[2][4]={{"2.3"},{'5','7', '8','4'}};
			//UART0_DR_R=  GGA_Fields;
			/*for(i=0;i<2;i++){
				for(k=0;k<10;k++){
					UART0_DR_R=GGA_Fields[i][k];
				}
			}*/
			printString("ok");
			//latitude = atof(GGA_Fields[2]);
			printString(N);
			//split_str(input,GGA_Fields);
			//if (latitude>=40){GPIO_PORTF_DATA_R=0x8;}
			//GPIO_PORTF_DATA_R=0x0;
			// for (i=0; i<10;i++)
			 //{
				// input[i]=GGA_Fields[1][i];
			  //GetChar_PC(input[i]);
			// }
			// input[9]='\0';
		   //Get_Data(input); //append a string per 1 while loop
//			 latitude =Get_Path_Coordinates('h',GGA_Fields);
			 //split_str(input,GGA_Fields);
			// x = GGA_Fields[2];
			// latitude = atof(input);
			 //GetChar_PC(latitude);
			 //if(latitude == 123.3){
       //GPIO_PORTF_DATA_R=0x8;}
		   /*if(Check_GGA(input))
				 {
				     split_str(input,GGA_Fields);			 
					   //GPIO_PORTF_DATA_R=0x8;
				 if(Check_fix(GGA_Fields[6][0])==1)  //means GGA_Fields is a valid string
					 {
						 UART0_DR_R=GGA_Fields[6][0];
						 latitude = atof(GGA_Fields[2]);
						 GPIO_PORTF_DATA_R=0x8;
						
					   //Valid_Coordinates[i][0]=Get_Path_Coordinates('h',GGA_Fields);
					   //Valid_Coordinates[i][1]=Get_Path_Coordinates('v',GGA_Fields);
						  
						  //UART0_DR_R= latitude;
						 
						/*GetChar_PC(Valid_Coordinates[i][0]);
						 UART0_DR_R='\n';
						 UART0_DR_R='\r'; */  
					 /* GetChar_PC( Valid_Coordinates[i][1]);
						 UART0_DR_R='\n';
						 UART0_DR_R='\r'; 
						// i++; 
					 }
					 				//GPIO_PORTF_DATA_R=0xE;

			 }
			 else
				 {
					
					 GPIO_PORTF_DATA_R=0x0;
				 }*/
			
    }
	return 0;
}