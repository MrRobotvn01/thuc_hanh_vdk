#include <regx51.h>
int t=0;
void delay(unsigned int n) {
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<125;j++);
	}
void ngat() interrupt 0 
{
	t=t++;
	if( t>8) t=0;
	delay(1000);
}
void led(int n){
	switch(n) {
		case 0: P1=0x00; break;
		case 1: P1=0x01; break;
		case 2: P1=0x03; break;
		case 3: P1=0x07; break;
		case 4: P1=0x0F; break;
		case 5: P1=0x1F; break;
		case 6: P1=0x3F; break;
	  case 7: P1=0x7F; break;
		case 8: P1=0xFF; break;
		}
}		
void main() {
	IE=0x85;
	
	P1=0x00;
	while(1) {
		led(t);
		}
	}	
	