#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GPS.h"
#include "GPIO.h"
#include "UART.h"
#include "STD_TYPES.h"

uint8_t Check_GGA(uint8_t input[])
	{
    if(input[3] =='G' && input[4] =='G' && input[5] == 'A')
			{
				return 1;
			}
		else
			{
				return 0;
		  }
	}		

void Get_String()
	{
	  while((UART2_FR_R & (1<<4))!=0){}
		if (UART2_DR_R=='$')
			{
			UART0_DR_R= UART2_DR_R;
			GPIO_PORTF_DATA_R =0x2;
		  }
		else 
			{
			GPIO_PORTF_DATA_R =0x4;
		  }
	}		
	
void Get_Data(char * data)
	{
		uint8_t i;
		while((UART2_FR_R & (1<<4))!=0){} //receive flag
		if( UART2_DR_R =='$')
				  {
						for(i=0; i<50; i++)
						{
					    data[i]= UART2_DR_R;
						while((UART0_FR_R & (1<<5))!=0){}
							//UART0_DR_R= data[i];
							if(data[i]=='*')
								{
									//UART0_DR_R='\n';
									//while((UART0_FR_R & (1<<5))!=0){}
									//UART0_DR_R='\r';
									break;
								}
							while((UART2_FR_R & (1<<4))!=0){}
				    }		 
	        }
					
	}
	
	
uint8_t Check_fix (uint8_t input)
{
		if(input =='1')
			{
				return 1;
			}
		else
			{
				return 0;
			}
}

void split_str(uint8_t *input, uint8_t arr[MAX_FIELDS][MAX_FIELD_LENGTH]) 
	{
		
		uint8_t *token;
   
		int fieldCount = 0;
		
   
		// b2sm el input by comma
    token = strtok(input, ",");
		
   /* while (token != NULL && fieldCount < MAX_FIELDS) ////////////check the token condtion seems wired
			{
        strcpy(arr[fieldCount], token);
        fieldCount++;
        token = strtok(NULL, ",");
      }
			GPIO_PORTF_DATA_R=0xE;
*/
}


double Get_Path_Coordinates(uint8_t *input, uint8_t axis ,uint8_t hold_array[MAX_FIELDS][MAX_FIELD_LENGTH]  )
	{
		
		 double latitude;
     uint8_t lat_deg;
     double lat_min;
		
		double longitude; 
    double lon_deg;
    double lon_min ;
		
		
		 //split rl str
		// uint8_t hold_array[MAX_FIELDS][MAX_FIELD_LENGTH];
		
    //split_str(input, hold_array);
		
		// GPIO_PORTF_DATA_R=0xE;

    //calc latitude
    latitude = strtod(hold_array[2], NULL);
    lat_deg = (uint8_t)(latitude / 100);
    lat_min = latitude - lat_deg * 100;
    latitude = lat_deg + lat_min / 60;


    //calc longitude
     longitude = strtod(hold_array[4], NULL);
     lon_deg = (uint8_t)(longitude / 100);
     lon_min = longitude - lon_deg * 100;
        longitude = lon_deg + lon_min / 60;

    //if south not north --or-- west instead of east
    if(hold_array[3][0] == 'S'){latitude = -latitude;}
    if(hold_array[5][0] == 'W'){longitude = -longitude;}
				

    //return the output
    if(axis == 'h'){return latitude ;}
    if(axis == 'v'){return longitude ;} 

}
	