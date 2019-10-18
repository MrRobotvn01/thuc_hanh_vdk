// Chuong trinh doc phim nhan tren Ban phim 4x3
// Dieu khien 8 led
// Nhan 1 phim thi led tuong ung sáng
// Nhan cac phim hang cuoi cung thi tat ca cac den tat
// Author: NGUYEN VIET DAN TDH15
#include <regx51.h>
void delay(unsigned int n) {
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<125;j++);
	}
int cophim()
	{
		P2_0=0;
		P2_1=0;
		P2_2=0;
		P2_3=0;
		if((P2_4 && P2_5 && P2_6)==0) return 1;
		else return 0;
	}	
int xacdinhphim()
	{ //Nôi duong nguon tat ca cac hang
		P2_0=1;
		P2_1=1;
		P2_2=1;
		P2_3=1;
		//Noi dat tung cot
		//-------------------Kiem tra hang 1------------------
		P2_0=0;
			if(P2_4==0) return 1;
		  else if(P2_5==0) return 2;
		  else if(P2_6==0) return 3;
		//-------------------Kiem tra hang 2------------------
		P2_1=0;
		  if(P2_4==0) return 4;
		  else if(P2_5==0) return 5;
		  else if(P2_6==0) return 6;
		//-------------------Kiem tr hang 3-------------------
		P2_2=0;
		  if(P2_4==0) return 7;
		  else if(P2_5==0) return 8;
		  else if(P2_6==0) return 9;
		//------------------Kiem tra hang 4--------------------
		P2_3=0;
		  if((P2_4 && P2_5 && P2_6)==0) return 0;
	}
void dieu_khien_led( int n)
		{ 
			switch(n) {
				case 0: P1=0xFF; P2_7=1; break;
				case 1: P1_0=0; break;
				case 2: P1_1=0; break;
				case 3: P1_2=0; break;
				case 4: P1_3=0; break;
				case 5: P1_4=0; break;
				case 6: P1_5=0; break;
			  case 7: P1_6=0; break;
        case 8:	P1_7=0; break;
				case 9: P2_7=0; break;
				}
    }				
void main() 
{
	P1=0xFF;
	P2=0xF0;
	while(1)
		{
			if(cophim()==1)
				{
						int p=xacdinhphim();
					  dieu_khien_led(p);
				}
    }
}		
			
