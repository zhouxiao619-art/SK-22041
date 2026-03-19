#ifndef CONFIG_H_
#define CONFIG_H_

/*============================================================================
							PMS150G(SOP-8)		
						VDD-----------------GND
		led1			PA7-----------------PA0			key2/charge_full				
		led2			PA6-----------------PA4			key1
		CHARGE			PA5-----------------PA3			RF_DATA
==============================================================================*/

bit key1 				: PA.4;
bit led1 				: PA.7;
bit led2 				: PA.6;
bit key2 				: PA.0;
bit RF_data				: PA.3;
bit CHARGE				: PA.5;

#define LED_ON	1
#define	LED_OFF	0

extern byte send_icnt;
extern byte Power_down_flag;
extern word LED_icnt_timer;

void IO_init(void);
void close_hardware(void);

#endif