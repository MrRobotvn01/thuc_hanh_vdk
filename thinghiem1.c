// CHUONG TRINH NHAP NHAY LED
//Author: Nguyen Viet Dan
// LED noi Chan P1_0
#include<regx51.h>

void delay(unsigned int n) // Ham delay n milis giay 
{
int i,j;
for(i=0;i<n;i++)
	for(j=0;j<1000;j++);
}
void main() {
	P1=0x70;
	while(1)
	{
		P1_0=1;
		delay(1000);
		P1_0=0;
		delay(1000);
	}
}
	
