void servoRotate0()        // 0 Degree
{
        unsigned int i;
        for(i=0;i<50;i++)
        {
            PORTB.F0=1;
            Delay_us(800);      //1ms = 0 degree
            PORTB.F0=0;
            Delay_us(19200);
        }
}

void servoRotate90()           // 90 Degree
{
        unsigned int i,j;
        for(i=0;i<50;i++)
        {
            PORTB.F0=1;
            Delay_us(1495);     //1.5ms = 90 degree
            if(i==0);
            PORTB.F0=0;
            Delay_us(18500);
        }
}

void servoRotate180()             // 180 Degree
{
        unsigned int i;
        for(i=0;i<50;i++)
        {
            PORTB.F0=1;
            Delay_us(2200);      //2ms = 180 degree
            PORTB.F0=0;
            Delay_us(17800);
        }
}



void main() {

            TRISB=0x00;          // PortB as output port
            TRISC=0xff;
            portb=0x00;
           while(1){
                     if(portc.f0==0xff)
                     {
                      portb.f1=0xff;
                      servoRotate0();
                     }
                     if(portc.f1==0xff)
                     {
                     portb.f1=0x00;
                    servoRotate180();         // 90 Degree
                    Delay_ms(2000);

                      }



          }
}