#include <regx51.h>
//int F=0
int T=0;
void Timer0_Init()
{
	TMOD = 0x01;          //Timer hoat dong o che do 1
	//TH0=(65535-500)/256;  //Nap gia tri vao 8 bit cao
	//TL0=(65535-500)%256+1;//Nap gia tri vao 8 bit thap
	TF0=0;                //Xoa co tran TF0 
	TR0=1;                //Bat bo dem Timer0
}
void delay_timer(int n) // n<65535
 { TR0=0;               //Tat timer0
  TH0=(65535-n)/256;   
	TL0=(65535-n)%256+1;
	TF0=0;               //Xoa co TF0  
	TR0=1;               //Bat bo dem
	while(TF0==0);       //Dem toi khi nao co tran bao day
	TF0=0;               //Reset co tran
	TR0=0;               //Tat bo dem
}
void main() { 
	P1_0=1;
	T=1000;
	Timer0_Init();
	while(1) {
		int i=1;
		for(i=1;i<=10;i++)
		{
			delay_timer(i*T/10); //T tinh theo don vi us
			P1_0 = 0;
      delay_timer(T-i*T/10);//Sau moi vong lap thi duty tang 10%
      P1_0 = 1;`			
		}
	}
}	