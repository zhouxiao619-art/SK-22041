#include "ISR.H"

Word	Reload_T16;
void Timer16_Init(void)				//100us
{
	Reload_T16 = 32768 - 1532;
	stt16 Reload_T16;
	$ T16M IHRC,/1,bit15;
	$ INTEGS BIT_R;
	INTRQ.T16 = 0;
	INTEN.T16 = 1;
	ENGINT;
}