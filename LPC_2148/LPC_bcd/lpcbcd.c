#include<lpc214x.h>
int main()
{
unsigned int v1,v2,v3;
IODIR0=0x000000FF;//port0 lsb pins configured as output
while(1)
{
IOSET0=0x0000000F;//lsb 4 leds on
IOCLR0=0x000000F0;//4leds off
for(v1=0;v1<200000;v1++);
IOSET0=0x000000F0;//lsb 4 leds off
IOCLR0=0x0000000F;//4 leds on
for(v1=0;v1<200000;v1++);
IOCLR0=0x000000FF;
v3=0x00000001;
for(v2=0;v2<8;v2++)//one by one
{
IOSET0=v3;
for(v1=0;v1<200000;v1++);
IOSET0=v3;
v3=v3<<1;
}
v3=0x00000001;//fountain
for(v2=0;v2<200000;v2++)
{
IOSET0=v3;
for(v1=0;v1<200000;v1++);
v3=v3<<1;
}
v3=0x00000080;
for(v2=0;v2<8;v2++)
{
IOCLR0=v3;
for(v1=0;v1<200000;v1++);
v3=v3>>1;
}
}
}  


