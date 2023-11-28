char arraycc[] = { 0xBF, 0x86, 0xDB, 0xCF, 0xE6, 0xED, 0xFD, 0x87, 0xFF, 0xEF };
//char arrayca[] = { 0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10 };



void main() {
    int i;
   int  bt_zero = 0, bt_one = 0, input_value,res,mod,k;






   TRISB = 0x00;
   TRISC = 0x00;
   TRISD.f0 = 0xff;
   TRISD.f1 = 0xff;
   TRISD.f2 = 0xff;
   TRISD.f3 = 0xff;
   TRISD.f5 = 0x00;
   portb = 0x00;
   portc = 0x00;
   portd.f5=0x00;

   while(1)
   {

   // SECOND CIRCUIT IMPLEMENTATION AND PROVIDE DATA IN SECOND CIRCUIT FROM TO THE FIRST CIRCUIT

         if(portd.f1 == 0xff)  // click initialize
       {
          delay_ms(150);
          if(portd.f1 == 0xff)  // click stability check
          {
              bt_zero++;        // digit increment
              if(bt_zero == 10) // after 9, next is 0
              {

                 bt_zero = 0;
              }
          }
       }
       if(portd.f0 == 0xff)
       {
          delay_ms(150);
          if(portd.f0 == 0xff)
          {
              bt_one++;
              if(bt_one == 10)
              {
                 bt_one = 0;
              }
          }
       }

        input_value = (bt_zero * 10 + bt_one); // Calculate the input value
        
        if(portd.f2 == 0xff)
        {

           for(i=1;i<=input_value*60;i++)
        {
         portd.f5=0xff;
         delay_ms(1000);

        }

             }
             portd.f5=0x00;

       portc.f0 = 0x00;   // active power for digit left
       portb = arraycc[bt_zero]; // provide data for left digit
       delay_ms(10);
       portc.f0 = 0xff;   // Deactive power for digit left

       portc.f1 = 0x00;     // active power for second digit
       portb = arraycc[bt_one];    // provide data for second digit
       delay_ms(10);
       portc.f1 = 0xff;      // deactive power for second digit

    }
    }