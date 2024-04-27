#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GPS.h"
#include "GPIO.h"
#include "UART.h"
#include "STD_TYPES.h"

/*uint8_t Check_GGA(uint8_t input[])
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
	
void Get_Data(uint8_t data[])
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

*/
void split_str(uint8_t input []) 
	{
		
		char *token;
		int fieldCount = 0;
		static int i=0;
		float lat;
		char num [5]= "30.2" ;
		float fnm ; 
		// b2sm el input by comma
    token = strtok(input, ",");
		 
				
		fnm = atof (num);
		
    while (token != NULL && fieldCount < MAX_FIELDS) ////////////check the token condtion seems wired
			{
       // strcpy(arr[fieldCount], token);
				
				if(fieldCount==2)
					{
					//{
						Coordinates[i][0]= atof(token);
				  }
				else if(fieldCount==4)
					{
						 Coordinates[i][1]= atof(token);
				}
					else if(fieldCount==6)
					{
						if(*token ==0)
						{
							i--;
						}
						break;
					}
        fieldCount++;
        token = strtok(NULL, ",");
      }		
			i++;
}

/*
float Get_Path_Coordinates(uint8_t axis ,uint8_t hold_array[MAX_FIELDS][MAX_FIELD_LENGTH])
	{
		
		 float latitude;
     uint8_t lat_deg;
     float lat_min;
		
		float longitude; 
    float lon_deg;
    float lon_min ;

    //calc latitude
    latitude = atof(hold_array[2]);
    lat_deg = (uint8_t)(latitude / 100);
    lat_min = latitude - lat_deg * 100;
    latitude = lat_deg + lat_min / 60;


    //calc longitude
     longitude = atof(hold_array[4]);
     lon_deg = (uint8_t)(longitude / 100);
     lon_min = longitude - lon_deg * 100;
        longitude = lon_deg + lon_min / 60;

    //if south not north --or-- west instead of east
    if(hold_array[3][0] == 'S'){latitude = -latitude;}
    if(hold_array[5][0] == 'W'){longitude = -longitude;}
				

    //return the output
    if(axis == 'h'){return latitude ;}
    if(axis == 'v'){return longitude ;} 

}*/
	