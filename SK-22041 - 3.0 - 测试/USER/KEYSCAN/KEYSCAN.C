#include "KEYSCAN.H"
#include 	"../CONFIG/CONFIG.H"
#include 	"../SLEEP/SLEEP.H"
#include 	"../ENCODE/ENCODE.H"
#include 	"../led/led.H"

word key_time;
byte Long_click;
byte Long_click_bak;
word key_time2;
byte Long_click2;
byte Long_click_bak2;
word key_time_s;
byte Long_click_s;
byte Long_click_bak_s;
byte wait_m1;
byte wait_m2;
bit flag_wait;
dword wait_timer;
word LED_icnt_timer_s1;
word LED_icnt_timer_s2;

void KEY_SCAN()
{
	if(KEY1)
	{
		if(key_time >= SINGLE_KEY_TIME && Long_click == 0)
		{
			if(Power_down_flag)
			{
				DISGINT;
				send_icnt = 1;
				data = 0xcccc;
				if(send_icnt)
				{
					RF_Encode();
					send_icnt--;
				}
				ENGINT;
				wait_m1 = 1;
				Led_start(1);
			}
		}
		key_time = 0;
		Long_click = 0;
	}

	if(Long_click_bak != Long_click)	
	{
		if(Power_down_flag)
		{
			if(Long_click == 1)		
			{
				DISGINT;
				send_icnt = 1;
				data = 0x4444;
				if(send_icnt)
				{
					RF_Encode();
					send_icnt--;
				}
				ENGINT;
				Power_down_flag = 0; 
				Long_click = 0xFF;
				key_time = 0;
			}
		}
		else
		{
			if(Long_click == 1)	
			{
				Power_down_flag = 1;
				Long_click = 0xFF;
				key_time = 0;
			}
		}
		Long_click_bak = Long_click;
	}

	if(KEY2)
	{
		if(key_time2 >= SINGLE_KEY_TIME && Long_click2 == 0)
		{
			if(Power_down_flag)
			{
				DISGINT;
				send_icnt = 1;
				data = 0xaaaa;
				if(send_icnt)
				{
					RF_Encode();
					send_icnt--;
				}
				ENGINT;
				wait_m2 = 1;
				Led_start(2);
			}
		}
		key_time2 = 0;
		Long_click2 = 0;
	}
	if(Long_click_bak2 != Long_click2)	
	{
		if(Power_down_flag)
		{
			if(Long_click2 == 1)		
			{
				DISGINT;
				send_icnt = 1;
				data = 0x2222;
				if(send_icnt)
				{
					RF_Encode();
					send_icnt--;
				}
				ENGINT;
				Power_down_flag = 0; 
				Long_click2 = 0xFF;
				key_time2 = 0;
			}
		}
		else
		{
			if(Long_click2 == 1)	
			{
				Power_down_flag = 1;
				Long_click2 = 0xFF;
				key_time2 = 0;
			}
		}
		Long_click_bak2 = Long_click2;
	}
}










