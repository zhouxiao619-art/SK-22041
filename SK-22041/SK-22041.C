#include "extern.h"
#include "./USER/CONFIG/CONFIG.H"
#include "./USER/SLEEP/SLEEP.H"
#include "./USER/ISR/ISR.H"
#include "./USER/KEYSCAN/KEYSCAN.H"
#include "./USER/ENCODE/ENCODE.H"
#include "./USER/CHARGE/CHARGE.H"
#include "./USER/gpc/gpc.H"
#include "./USER/led/led.H"

void FPPA0 (void)
{
	.ADJUST_IC	SYSCLK=IHRC/16,Init_RAM;
	IO_init();
	nop;
	Timer16_Init();

	while (1)
	{
		if(!CHARGE)
		{
			KEY_SCAN();
			CHARGE_STEP = 0;
			if(Power_down_flag)
			{
				Measure_GPC();
				func_wait();
			}
			else
			{
				if((Sleep_delay == 0) && (key_time == 0) && (key_time2 == 0))	//into Powerdonw
				{
					close_hardware();
					Power_down();
				}
			}
		}
		else CHARGE_MOD();			
	}
}

//-------------------------------------------------------------------------------------
void Interrupt(void)
{
	pushaf;
//-------------------------------------------------------------------------------------
	if(Intrq.T16)
	{	
		//T16 Trig ÖÜÆÚ£º100us
		STT16	Reload_T16;
		Intrq.T16 = 0;
		if(!charge)
		{
			if(!KEY1 && !Long_click)
			{
				key_time++;
				if(!wait_m1)
				{
					if(key_time >= 20000 )Long_click = 1;
				}
				else
				{
					if(key_time >= 15000 )Long_click = 1;
				}
				if(Power_down_flag == 0)Sleep_Delay = 200;
			}
			if(!KEY2 && !Long_click2)
			{
				key_time2++;
				if(!wait_m2)
				{
					if(key_time2 >= 20000 )Long_click2 = 1;
				}
				else
				{
					if(key_time2 >= 15000 )Long_click2 = 1;
				}
				if(Power_down_flag == 0)Sleep_Delay = 200;
			}
			if(!KEY1 && !KEY2 && !Long_click_s)
			{
				key_time = 0;
				key_time2 = 0;
				key_time_s++;
				if(key_time_s >= 15000 )Long_click_s = 1;
			}
		}
		
		if(Sleep_delay)Sleep_delay--;
		LED_icnt_timer++;
		VDD_count++;

		if(!wait_m1 && !wait_m1 && !charge)	wait_timer++;
		else								wait_timer = 0;

		led_t1++;
		led_t2++;
	}
	//----------------------------------------------------------------------------
	popaf;
}
//--------------------------------------------------------------------------------