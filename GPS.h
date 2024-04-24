#include "STD_TYPES.h"

#define MAX_FIELDS 14
#define MAX_FIELD_LENGTH 20
#define NO_OF_COORDINATES 200

uint8_t Check_GGA();
void Get_String();
void Get_Data(char * data);
uint8_t Check_fix();

void split_str(uint8_t *input, uint8_t arr[MAX_FIELDS][MAX_FIELD_LENGTH]);
double Get_Path_Coordinates(uint8_t *input, uint8_t axis ,uint8_t hold_array[MAX_FIELDS][MAX_FIELD_LENGTH] );