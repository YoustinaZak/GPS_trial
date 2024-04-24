#define EEPROM_EESIZE_R         (*((volatile unsigned long *)0x400AF000))
#define EEPROM_EEBLOCK_R        (*((volatile unsigned long *)0x400AF004))
#define EEPROM_EEOFFSET_R       (*((volatile unsigned long *)0x400AF008))
#define EEPROM_EERDWR_R         (*((volatile unsigned long *)0x400AF010))
#define EEPROM_EERDWRINC_R      (*((volatile unsigned long *)0x400AF014))
#define EEPROM_EEDONE_R         (*((volatile unsigned long *)0x400AF018))
#define EEPROM_EESUPP_R         (*((volatile unsigned long *)0x400AF01C))
#define EEPROM_EEUNLOCK_R       (*((volatile unsigned long *)0x400AF020))
#define EEPROM_EEPROT_R         (*((volatile unsigned long *)0x400AF030))
#define EEPROM_EEPASS0_R        (*((volatile unsigned long *)0x400AF034))
#define EEPROM_EEPASS1_R        (*((volatile unsigned long *)0x400AF038))
#define EEPROM_EEPASS2_R        (*((volatile unsigned long *)0x400AF03C))
#define EEPROM_EEINT_R          (*((volatile unsigned long *)0x400AF040))
#define EEPROM_EEHIDE_R         (*((volatile unsigned long *)0x400AF050))
#define EEPROM_EEDBGME_R        (*((volatile unsigned long *)0x400AF080))
#define EEPROM_PP_R             (*((volatile unsigned long *)0x400AFFC0))
	
#define SYSCTL_PREEPROM_R       (*((volatile unsigned long *)0x400FEA58)) //peripheral ready
#define SYSCTL_RCGCEEPROM_R     (*((volatile unsigned long *)0x400FE658)) //clk enable
	