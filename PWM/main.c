#include "pwm.h"
static uint Pwmscale=30;  //pwm�ĳ�ֵ 25%


void main  ()
{
	init();
	pwmset(Pwmscale);   //���ó�ֵ
		while(1)
		{
		}
 
}
