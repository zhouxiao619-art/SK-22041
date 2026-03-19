#include "CONFIG.H"
#include 	"../KEYSCAN/KEYSCAN.H"
#include 	"../SLEEP/SLEEP.H"
#include 	"../gpc/gpc.H"

/*============================================================================
							PMS150G(SOP-8)		
						VDD-----------------GND
		led1			PA7-----------------PA0			key2/charge_full				
		led2			PA6-----------------PA4			key1
		CHARGE			PA5-----------------PA3			RF_DATA
==============================================================================*/

byte Power_down_flag;
word LED_icnt_timer;
byte send_icnt;

void IO_init(void)
{
	PAPH   =  0b0001_0001;
	PAC    =  0b1100_1000;
	PA 	   =  0b0001_0001;
	PADIER =  0b1111_1001;
}

void Close_Hardware()
{
	led1 = 0;
	led2 = 0;
	wait_m1 = 0;
	wait_m2 = 0;
	long_click = 0;
	long_click2 = 0;
	vdd_set = 1;
}