#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(regis,bit)    (regis |=(1<<bit))
#define CLEAR_BIT(regis,bit)   (regis &= ~(1<<bit))
#define GET_BIT(regis,bit)     (regis &(1<<bit))
#define TOGGLE_BIT(regis,bit)  (regis ^=(1<<bit))

#define SET_PORT(regis)        (regis |= 0xFF )


#endif