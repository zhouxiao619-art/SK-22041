#ifndef _LED_H_
#define _LED_H_

extern BYTE LED_icnt;
extern BYTE Lock_LED_Flag;

void Led_start(byte LED_Flag_Temp);
void Func_LED();
void BREATH_LIGHT_MOD();

#endif