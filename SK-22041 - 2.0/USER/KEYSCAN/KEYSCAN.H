#ifndef KEYSCAN_H_
#define	KEYSCAN_H_

#define SINGLE_KEY_TIME     100       // SINGLE_KEY_TIME*10us = 10MS

extern byte Long_click;
extern byte Long_click_bak;
extern word key_time;
extern word key_time2;
extern byte Long_click2;
extern byte Long_click_bak2;
void KEY_SCAN();
extern byte wait_m1;
extern byte wait_m2;
void func_wait();
extern dword wait_timer;
extern bit flag_wait;
extern byte Long_click_s;
extern byte Long_click_bak_s;
extern word key_time_s;
extern word led_t1;
extern word led_t2;
extern word LED_icnt_timer_s1;
extern word LED_icnt_timer_s2;

#endif