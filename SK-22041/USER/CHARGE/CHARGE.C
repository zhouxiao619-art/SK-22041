#include 	"CHARGE.H"
#include 	"../CONFIG/CONFIG.H"
#include  	"../GPC/GPC.H"
#include  	"../KEYSCAN/KEYSCAN.H"
#include  	"../LED/LED.H"

Byte CHARGE_STEP;
word vdd_count;

void CHARGE_MOD(void)
{
	if(CHARGE_STEP == 0) //充电检测
	{
		.delay 10000;
		if(CHARGE)
		{
			Close_Hardware();
			Power_down_flag = 0;	//充电玩成进入 省电模式
			CHARGE_STEP = 1;
			VDD_count = 0;
		}
	}

	if(CHARGE_STEP == 1)	//充电呼吸
	{
		if(key2)
		{
			if(VDD_count >= 3000)CHARGE_STEP = 2;
		}
		else VDD_count = 0;

		led1 = 1;
		led2 = 1;
	}

	if(CHARGE_STEP == 2)	//充满常亮
	{
		if(LED_icnt_timer > 5000)
		{
			LED_icnt_timer = 0;
			$ led1 toggle;
			$ led2 toggle;
		}
	}
}