#include<16f88.h>
#device adc=10
#fuses INTRC_IO,nomclr
#use delay(clock=4m)
#use rs232(baud=9600,parity=N,xmit=PIN_A1,bits=8,stream=PORT1)

int i[8]={1,2,4,8,16,32,64,128};
int b=0,c=100;

unsigned long int bilgi;
unsigned long int deger;



void main()
{

set_tris_a(0x01);
output_a(0x01);
setup_adc(ADC_CLOCK_div_32);
setup_adc_ports(ALL_ANALOG);


set_tris_b(0x00);
output_b(0x00);




while(true)
{
set_adc_channel(0);
delay_us(20);
bilgi=read_adc();
deger = (bilgi * 0.0048888);
printf("\fdeger: %lu -  bilgi: %lu\n ",deger,bilgi);




//!if(input(pin_a0))
//!{
//!delay_ms(10);
//!c=c+100;
//!if(c == 1500)
//!c=100;
//!
//!}while(input(pin_a0));


for(b=0; b<=7; b++)
{
output_b(i[b]);
delay_ms(250);
}

for(b=6; 0<=b; b--)
{
output_b(i[b]);
delay_ms(250);
if(b==0)
break;
}


}

}
