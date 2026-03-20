extern bit BREATH_Switch;
extern byte BREATH_DUTY;
extern bit Add_sign;

extern byte BREATH_DUTY_temp;
extern word BREATH_time;
extern BYTE LED_icnt;
extern BYTE LED_icnt2;
extern BYTE LED_icnt3;
extern BYTE Lock_LED_Flag;
extern word LED_icnt_timer_s;
extern word LED_icnt_timer_ss;
extern word LED_icnt_timer_sss;

void Led_start(byte LED_Flag_Temp);
void Func_LED();
void BREATH_LIGHT_MOD();