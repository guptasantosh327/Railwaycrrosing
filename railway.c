#include<reg51.h>
#define lcd P2
 
sbit IR=P1^0;
sbit A=P3^0;
sbit B1=P3^1;
sbit C=P3^2;
sbit D=P3^3;
sbit rs=P3^7; //register select
sbit rw=P3^6; //RW
sbit en=P3^5; //enable
 
void lcd_init();
void cmd(unsigned char);
void dat(unsigned char);
void delay();
void lcd_string(char *s);
 
void main()
{
    lcd_init();
    lcd_string(" RailwayGate  ");
    while(1) {
        if(IR == 0) 
					{
            cmd(0xc0);
            lcd_string("Close");
            delay();
						A=1;
            B1=0;
						C=0;
						D=1;	
        } 
					
				else

				{
            cmd(0xc0);
            lcd_string("Open");
						A=1;
            B1=0;
						C=0;
						D=0;
					delay();
        }
    }
}
 
void lcd_init()
{
    cmd(0x38);
    cmd(0x0e);
    cmd(0x06);
    cmd(0x01);
    cmd(0x80);
}
 
void cmd(unsigned char a)
{
    lcd=a;
    rs=0;
    rw=0;
    en=1;
    delay();
    en=0;
}
 
void dat(unsigned char b)
{
    lcd=b;
    rs=1;
    rw=0;
    en=1;
    delay();
    en=0;
}
 
void lcd_string(char *s)
{
    while(*s) {
       dat(*s++);
     }
}
 
void delay()
{
    unsigned int i;
    for(i=0;i<20000;i++);
}