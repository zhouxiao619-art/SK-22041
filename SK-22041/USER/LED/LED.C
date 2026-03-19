#include "LED.H"
#include 	"../CONFIG/CONFIG.H"
#include 	"../keyscan/keyscan.H"

BYTE LED_icnt;
BYTE LED_Flag;

void Led_start(byte LED_Flag_Temp)
{
	LED_Flag = LED_Flag_Temp;
	LED_icnt = 1;
	if(LED_Flag==2) led2= 0;
	LED_icnt_timer = 0;
}

void Func_LED()
{
	if(LED_icnt)
	{
		if(LED_icnt_timer > 800)
		{
			LED_icnt_timer = 0;
			LED_icnt--;
			if(LED_Flag==2)
			{
				$ led2 toggle;
			}
		}
	}	
}