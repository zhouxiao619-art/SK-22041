#include "GPC.H"
#include 	"../CHARGE/CHARGE.H"
byte	VDD_Set;

void	GPC_Init(void)
{
	$ GPCC Enable,BANDGAP,P_R;
	switch(VDD_Set)
	{
		case 0:
			$ GPCS VDD*16/40;//VDD = 3V
			break;
		case 1:
			$ GPCS VDD*12/32;//VDD = 3.2V
			break;
	}
}
void	Measure_GPC(void)
{
	GPC_Init();
	if(VDD_set)
	{
		if(GPC_out)
		{
			VDD_count = 0;
		}
		else
		{
			if(VDD_count > 2000)
			{
				VDD_set = 0;
				led1 = 0;
				led2 = 0;
				VDD_count = 0;
			}
		}
	}
	else
	{
		if(GPC_out)
		{
			VDD_count = 0;
			if(LED_icnt_timer > 2000)
			{
				LED_icnt_timer = 0;
				$ led1 toggle;
				$ led2 toggle;
			}
		}
		else
		{
			if(LED_icnt_timer > 3000)
			{
				LED_icnt_timer = 0;
				$ led1 toggle;
				$ led2 toggle;
			}
			if(VDD_count > 10000)
			{
				Power_down_flag = 0;
				VDD_count = 0;
			}
		}
	}
}