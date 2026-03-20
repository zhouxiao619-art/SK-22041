#include "SLEEP.H"
#include 	"../CONFIG/CONFIG.H"

/*============================================================================
							PMS150G(SOP-8)		
						VDD-----------------GND
		led1			PA7-----------------PA0			key2/charge_full				
		led2			PA6-----------------PA4			key1
		CHARGE			PA5-----------------PA3			RF_DATA
==============================================================================*/

byte Sleep_delay;
byte CLKMD_BK;

//=======掉电模式=========
void Power_down(void)
{
	//===User can add code=====
	//进入省电模式前动作
	//=========================

	PADIER = 0b0011_0001;				//将PA0、PA3、PA6 设置为数字模式		//设置   唤醒IO

	CLKMD_BK = CLKMD;
	//休眠前需要切换低频ILRC用来防止唤醒失败
	$ CLKMD ILRC/1,En_IHRC,En_ILRC;		//系统时钟选择，是否启用IHRC，是否启用ILRC，（En_IHRC和En_ILRC不写为停用，写为启用）
										//系统时钟可选择IHRC/4, IHRC/16, IHRC/2, IHRC/8, ILRC/16, IHRC/32, IHRC/64, ILRC/4, ILRC/1
										//选择系统时钟为ILRC/1，启用IHLC和IHRC；（注：两个RC振荡器至少有一个开启，否则会出现宕机）
	CLKMD.En_IHRC = 0;					//关闭高频IHRC，若上条语句没使用低频时钟，此句必须去掉

	while(1)
	{
		nop;
		stopsys;						//进入断电模式
		if((!KEY1)||(!KEY2)||charge)break;
	}

	$ CLKMD ILRC/1,EN_IHRC,EN_ILRC;		//打开高频使能，准备切换回系统时钟
	nop;

	PADIER 	= 	0b1111_1001;			// 设置数字模式
	CLKMD = CLKMD_BK;						//恢复休眠前的时钟
	Sleep_delay = 200;
}






































