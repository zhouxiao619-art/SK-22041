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

void func_wait()
{
	if(!wait_m1 && !wait_m2)	flag_wait = 1;
	else						flag_wait = 0;
	if(LED_icnt_timer_s1 > 5000)
	{
		LED_icnt_timer_s1 = 0;
		if(!wait_m1)	$ led1 toggle;
	}
	if(LED_icnt_timer_s2 > 5000)
	{
		LED_icnt_timer_s2 = 0;
		if(!wait_m2)	$ led2 toggle;
	}
	if(wait_timer > 30 * 60 * 10000)
	{
		Power_down_flag = 0;
		wait_timer = 0;
	}
}

void KEY_SCAN()
{
	if(KEY1 && KEY2)
	{
		key_time_s = 0;
		Long_click_s = 0;
	}

	if(Long_click_bak_s != Long_click_s)		
	{
		if(Power_down_flag)
		{
			if(Long_click_s == 1)
			{
				DISGINT;
				send_icnt = 1;
				data = 0x1111;
				if(send_icnt)
				{
					RF_Encode();
					send_icnt--;
				}
				ENGINT;
				if(wait_m1)	wait_m1 = 0;
				if(wait_m2)	wait_m2 = 0;
				Led_start(3);
				Long_click_s = 0xFF;
				key_time_s = 0;
				key_time = 0;
				key_time2 = 0;
				Long_click = 0xff;
				Long_click2 = 0xff;
			}
		}
		Long_click_bak_s = Long_click_s;
	}

	if(KEY1)
	{
		if(key_time >= SINGLE_KEY_TIME && Long_click != 1)
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
				if(flag_wait)
				{
					DISGINT;
					send_icnt = 1;
					data = 0xdddd;
					if(send_icnt)
					{
						RF_Encode();
						send_icnt--;
					}
					ENGINT;
					Power_down_flag = 0; 
				}
				if(wait_m1)
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
					wait_m1 = 0;
					Led_start(1);
				}
				Long_click = 0xFF;
				key_time = 0;
			}
		}
		else
		{
			if(Long_click == 1)	
			{
				wait_m1 = 0;
				wait_m2 = 0;
				Power_down_flag = 1;
				Long_click = 0xFF;
				key_time = 0;
			}
		}
		Long_click_bak = Long_click;
	}

	if(KEY2)
	{
		if(key_time2 >= SINGLE_KEY_TIME)
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
				if(flag_wait)
				{
					DISGINT;
					send_icnt = 1;
					data = 0xdddd;
					if(send_icnt)
					{
						RF_Encode();
						send_icnt--;
					}
					ENGINT;
					Power_down_flag = 0; 
				}
				if(wait_m2)
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
					wait_m2 = 0;
					Led_start(2);
				}
				Long_click2 = 0xFF;
				key_time2 = 0;
			}
		}
		else
		{
			if(Long_click2 == 1)	
			{
				wait_m1 = 0;
				wait_m2 = 0;
				Power_down_flag = 1;
				Long_click2 = 0xFF;
				key_time2 = 0;
			}
		}
		Long_click_bak2 = Long_click2;
	}
}











