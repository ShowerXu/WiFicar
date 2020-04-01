#include "pwm.h"
uint pwm=0,Count=0;
uint Pwmvalue=0;
uint flag = 0;
sbit key = P2^1;

void delayms()
{
	uint i,j;
	for(i=0;i<2000;i++)
	for(j=0;j<2;j++);
}


void init ()
{
	TMOD=0X22;  //˫��ʱ�����򿪹�����ʽ2
	SCON=0X50;
	TH1=0XFD;    //9600�Ĳ�����
	TL1=0XFD;
	TL0=245;	 //1ms��ʱ��
	TH0=245;
	ET0=1;
	TR0=1;
	TR1=1;
	EA=1;
	ES=1;
	PS=1;       //�����ж���������ȼ�
	pwm=0;     //�ߵ�ƽ��ռ�ձ�
	Count=0;  //ʱ�����
	
}
 
void pwmset(uint NewPwmValue)       //����ռ�ձ� ������PWM��
{
	if((NewPwmValue>=1)&&(NewPwmValue<=99))
	{
			pwm=NewPwmValue;
	}
	else     //�����õ�ռ�ձ�û������
	{	
			pwm=0x01;   //���һ������
	}
}
 
 
void pwmproduce() interrupt 1    //��ʱ0�ķ�ʽ���ж�
{
	if(flag == 0){	 //�ƶ�
		PWM_OUT1=0;
		PWM_OUT2=0;		   
		PWM_OUT3=0;
		PWM_OUT4=0;
	}else if(flag == 1){		  //ǰ��
		 Count++;           //ʱ����� ÿ1ms��һ
		 PWM_OUT2=0;
		 PWM_OUT1=1;
		 PWM_OUT4=0;
		 PWM_OUT3=1;
		if(Count<=pwm)    //����ʱ��С�ڹ涨ռ�ձ�
		{
			ENA = 1;
			ENB = 1;
		}
		else                      //�����˹涨ʱ��
		{
			ENA = 0;
			ENB = 0;
			if(Count>=100)   //����ֵ����100
			{
					Count=0;     //����ֵ����
			}
		}
	}else if(flag == 2){			//����
		 Count++;           //ʱ����� ÿ1ms��һ
		 PWM_OUT1=0;
		 PWM_OUT2=1;
		 PWM_OUT4=1;
		 PWM_OUT3=0;
		if(Count<=pwm)    //����ʱ��С�ڹ涨ռ�ձ�
		{
			ENA = 1;	        //����ߵ�ƽ
			ENB = 1;
		}
		else                      //�����˹涨ʱ��
		{
			ENA = 0;        //����͵�ƽ
			ENB = 0;
			if(Count>=100)  //����ֵ����100
			{
				Count=0;     //����ֵ����
			}
		}
	}else if(flag == 3){			//ǰ�����
		 Count++;           //ʱ����� ÿ1ms��һ
		 PWM_OUT2=0;
		 PWM_OUT1=1;
		 PWM_OUT4=0;
		 PWM_OUT3=1;
		if(Count<=pwm)    //����ʱ��С�ڹ涨ռ�ձ�
		{
			ENA = 1;	        //����ߵ�ƽ
			if(Count<=(pwm/4)){
			 	 ENB = 1;
			}else{
				ENB = 0;
			}
			
		}
		else                      //�����˹涨ʱ��
		{
			ENA = 0;        //����͵�ƽ
			ENB = 0;
			if(Count>=100)  //����ֵ����100
			{
				Count=0;     //����ֵ����
			}
		}
	}else if(flag == 4){			//ǰ���ҹ�
		 Count++;           //ʱ����� ÿ1ms��һ
		 PWM_OUT2=0;
		 PWM_OUT1=1;
		 PWM_OUT4=0;
		 PWM_OUT3=1;
		if(Count<=pwm)    //����ʱ��С�ڹ涨ռ�ձ�
		{
				        //����ߵ�ƽ
			ENB = 1;
			if(Count<=(pwm/4)){
			 	ENA = 1;
			}else{
				ENA = 0;
			}
		}
		else                      //�����˹涨ʱ��
		{
			ENA = 0;        //����͵�ƽ
			ENB = 0;
			if(Count>=100)  //����ֵ����100
			{
				Count=0;     //����ֵ����
			}
		}
	}else if(flag == 5){			//�������
		 Count++;           //ʱ����� ÿ1ms��һ
		 PWM_OUT1=0;
		 PWM_OUT2=1;
		 PWM_OUT4=1;
		 PWM_OUT3=0;
		if(Count<=pwm)    //����ʱ��С�ڹ涨ռ�ձ�
		{
			ENA = 1;	        //����ߵ�ƽ
			
			if(Count<=(pwm/4)){
			 	ENB = 1;
			}else{
				ENB = 0;
			}
		}
		else                      //�����˹涨ʱ��
		{
			ENA = 0;        //����͵�ƽ
			ENB = 0;
			if(Count>=100)  //����ֵ����100
			{
					Count=0;     //����ֵ����
			}
		}
	}else if(flag == 6){			//�����ҹ�
		 Count++;           //ʱ����� ÿ1ms��һ
		 PWM_OUT1=0;
		 PWM_OUT2=1;
		 PWM_OUT4=1;
		 PWM_OUT3=0;
		if(Count<=pwm)    //����ʱ��С�ڹ涨ռ�ձ�
		{
			ENB = 1;	        //����ߵ�ƽ
			
			if(Count<=(pwm/4)){
			 	ENA = 1;
			}else{
				ENA = 0;
			}
		}
		else                      //�����˹涨ʱ��
		{
			ENA = 0;        //����͵�ƽ
			ENB = 0;
			if(Count>=100)  //����ֵ����100
			{
					Count=0;     //����ֵ����
			}
		}
	}
	
}
void chuan() interrupt 4      //�����ж�
{
	RI=0;   
	Pwmvalue=SBUF;          //���ܴ��ڷ�����ռ�ձ�����
	if(Pwmvalue=='1'){	   //ǰ��
		flag = 1;
		 pwmset(30);       //�����µ�ռ�ձ�	 
	}else if(Pwmvalue=='0'){	//�ƶ�
		flag = 0;
	} else if(Pwmvalue=='2'){  //����
		flag = 2;
		 pwmset(30);       //�����µ�ռ�ձ�
	} else if(Pwmvalue=='3'){  //ǰ�����
		flag = 3;
		 pwmset(30);       //�����µ�ռ�ձ�
	} else if(Pwmvalue=='4'){  //ǰ���ҹ�
		flag = 4;
		 pwmset(30);       //�����µ�ռ�ձ�
	}else if(Pwmvalue=='5'){  //����
		flag = 5;
		 pwmset(30);       //�����µ�ռ�ձ�
	}else if(Pwmvalue=='6'){  //����
		flag = 6;
		 pwmset(30);       //�����µ�ռ�ձ�
	}
	
	ES=0;						
	TI=1;						
	while(!TI);
	TI=0;
	ES=1;
}
