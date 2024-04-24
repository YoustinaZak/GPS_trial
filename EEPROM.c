#include "EEPROM.h"
#include "BIT_MATH.h"

void EEPROM_INIT()
	{
		SET_BIT(SYSCTL_RCGCEEPROM_R ,0);
		while(~GET_BIT(SYSCTL_PREEPROM_R,0)){}
		while(~GET_BIT(EEPROM_EEDONE_R,0)){}
  }
	
void EEPROM_Write()
	{
		while(~GET_BIT(EEPROM_EEDONE_R,0)){}
  }