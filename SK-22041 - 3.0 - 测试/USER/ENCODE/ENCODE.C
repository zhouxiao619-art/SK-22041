#include "ENCODE.H"
#include 	"../CONFIG/CONFIG.H"
word data;

void rf_start()
{
	byte loop_rf = 5;
	while(loop_rf--)
	{
		RF_data = 1;
		.delay 507;
		RF_data = 0;
		.delay 254;
	}
	RF_data = 1;
	.delay 253;
	RF_data = 0;
	.delay 1015;
}

void RF_end()
{
	RF_data = 1;
	.delay 253;
	RF_data = 0;
	.delay 508;
}

void RF_Encode()
{
	byte data_icnt;
	byte loop_rf = 13;
	word data_temp;
	while(loop_rf--)
	{
		rf_start();
		data_icnt = 16;
		data_temp = data;
		do
		{
			if(data_temp & 0x8000)	//bit 1
			{
				RF_data = 1;		
				.delay 507;
				RF_data = 0;
				.delay 254;
			}
			else					//bit0
			{
				RF_data = 1;
				.delay 253;
				RF_data = 0;
				.delay 508;
			}
			data_temp <<= 1;
		}while(--data_icnt);
		RF_end();
	}
}