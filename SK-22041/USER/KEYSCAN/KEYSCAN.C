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
word led_t1;
word led_t2;

void code_flash12()
{
	led_t1 = 0;
	led_t2 = 0;
	while(led_t1 < 8010)
	{
		if(led_t2 > 2000)
		{
			$ led1 toggle;
			$ led2 toggle;
			led_t2 = 0;
		}
	}
}

void code_flash1()
{
	led_t1 = 0;
	led_t2 = 0;
	while(led_t1 < 8010)
	{
		if(led_t2 > 2000)
		{
			$ led1 toggle;
			led_t2 = 0;
		}
	}
}

void code_flash2()
{
	led_t1 = 0;
	led_t2 = 0;
	while(led_t1 < 8010)
	{
		if(led_t2 > 2000)
		{
			$ led2 toggle;
			led_t2 = 0;
		}
	}
}

void func_wait()
{
	if(!wait_m1 && !wait_m2)	flag_wait = 1;
	else						flag_wait = 0;
	if(LED_icnt_timer > 5000)
	{
		LED_icnt_timer = 0;
		if(!wait_m1)	$ led1 toggle;
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
				code_flash12();
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
				code_flash1();
				led1 = 1;
				wait_m1 = 1;
				DISGINT;
				send_icnt = 1;
				data = 0xcccc;
				if(send_icnt)
				{
					RF_Encode();
					send_icnt--;
				}
				ENGINT;
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
					code_flash1();
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
				code_flash2();
				led2 = 1;
				wait_m2 = 1;
				DISGINT;
				send_icnt = 1;
				data = 0xaaaa;
				if(send_icnt)
				{
					RF_Encode();
					send_icnt--;
				}
				ENGINT;
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
					code_flash2();
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












