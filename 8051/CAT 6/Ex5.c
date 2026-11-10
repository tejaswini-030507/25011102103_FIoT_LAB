#include <reg51.h>

void uart_init(){
    TMOD = 0x20;      
    SCON = 0x50;      
    TR1  = 1; 
	TH1 = 0xFD;
    TI = 0;           
    RI = 0;           
}

int main(){
	char c;
	SBUF = 'T';
	uart_init();
	
	while(1){
		while (RI == 0);
		c = SBUF;
		RI = 0;
		TI = 0;
		SBUF = c;
		while (TI == 0){
		}
		TI = 0;
		
	}
}