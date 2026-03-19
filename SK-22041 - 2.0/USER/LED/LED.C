#include "LED.H"
#include 	"../CONFIG/CONFIG.H"
#include 	"../keyscan/keyscan.H"

BYTE LED_icnt;
BYTE LED_icnt2;
BYTE LED_icnt3;
BYTE LED_Flag;
byte wait_m1_x;
byte wait_m2_x;
word LED_icnt_timer_s;
word LED_icnt_timer_ss;
word LED_icnt_timer_sss;

void Led_start(byte LED_Flag_Temp)
{
	LED_Flag = LED_Flag_Temp;
	if(LED_Flag==1)
	{
		wait_m1_x = wait_m1;
		wait_m1 = 1;
		led1 = 0;
		LED_icnt = 3;
		LED_icnt_timer_s = 0;
	}
	else if(LED_Flag==2)
	{
		wait_m2_x = wait_m2;
		wait_m2 = 1;
		led2 = 0;
		LED_icnt2 = 3;
		LED_icnt_timer_ss = 0;
	}
	else if(LED_Flag==3)
	{
		wait_m1_x = wait_m1;
		wait_m2_x = wait_m2;
		wait_m1 = 1;
		wait_m2 = 1;
		led1 = 0;
		led2 = 0;
		LED_icnt3 = 3;
		LED_icnt_timer_sss = 0;
	}
	//LED_icnt_timer_s = 0;
}

void Func_LED()
{
	/*if(LED_icnt)
	{
		if(LED_icnt_timer_s > 2000)
		{
			LED_icnt_timer_s = 0;
			LED_icnt--;
			if(LED_Flag==1)	
			{
				$ led1 toggle;
				if(!LED_icnt)
				{
					wait_m1 = wait_m1_x;
					if(wait_m1)	led1 = 1;
				}
			}
			else if(LED_Flag==2)	
			{
				$ led2 toggle;
				if(!LED_icnt)
				{
					wait_m2 = wait_m2_x;
					if(wait_m2)	led2 = 1;
				}
			}
			else if(LED_Flag==3)	
			{
				$ led1 toggle;
				$ led2 toggle;
				if(!LED_icnt)
				{
					wait_m1 = wait_m1_x;
					wait_m2 = wait_m2_x;
				}
			}
		}
	}*/
	if(LED_icnt)
	{
		if(LED_icnt_timer_s > 2000)
		{
			LED_icnt_timer_s = 0;
			LED_icnt--;
			//if(LED_Flag==1)	
			{
				$ led1 toggle;
				if(!LED_icnt)
				{
					wait_m1 = wait_m1_x;
					if(wait_m1)	led1 = 1;
				}
			}
		}
	}

	if(LED_icnt2)
	{
		if(LED_icnt_timer_ss > 2000)
		{
			LED_icnt_timer_ss = 0;
			LED_icnt2--;
			//if(LED_Flag==2)	
			{
				$ led2 toggle;
				if(!LED_icnt2)
				{
					wait_m2 = wait_m2_x;
					if(wait_m2)	led2 = 1;
				}
			}
		}
	}

	if(LED_icnt3)
	{
		if(LED_icnt_timer_sss > 2000)
		{
			LED_icnt_timer_sss = 0;
			LED_icnt3--;
			//if(LED_Flag==3)	
			{
				$ led1 toggle;
				$ led2 toggle;
				if(!LED_icnt3)
				{
					wait_m1 = wait_m1_x;
					wait_m2 = wait_m2_x;
				}
			}
		}
	}
}