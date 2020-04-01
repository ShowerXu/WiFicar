#ifndef _PWM_H
#define _PWM_H
#include <reg52.h>
#include <stdio.h>
#include <stdlib.h>
#define uint  unsigned int 
#define uchar unsigned char
#define Pwm_period 100      //�������ֵ
sbit PWM_OUT1=P1^2;           //PWM�������
sbit PWM_OUT2=P1^3;
sbit ENA = P1^1;
sbit PWM_OUT3=P1^5;           //PWM�������
sbit PWM_OUT4=P1^6;
sbit ENB = P1^4;
void init ();
void delayms();
void pwmset(uint NewPwmValue);
#endif
