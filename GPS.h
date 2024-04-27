

#ifndef GPS_H_
#define GPS_H_


#include "STD_TYPES.h"
#define MAX_FIELDS 14
#define MAX_FIELD_LENGTH 20
#define NO_OF_COORDINATES 20  //should be 200

extern float Coordinates[10][2];
uint8_t Check_GGA();
void Get_String();
void Get_Data(uint8_t data[]);
uint8_t Check_fix();

void split_str(uint8_t *input) ;
float Get_Path_Coordinates(uint8_t axis ,uint8_t hold_array[MAX_FIELDS][MAX_FIELD_LENGTH] );

#endif