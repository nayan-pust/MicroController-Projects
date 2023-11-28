char arraycc[] = { 0xBF, 0x86, 0xDB, 0xCF, 0xE6, 0xED, 0xFD, 0x87, 0xFF, 0xEF };



void main() {
    int i,k,tens,units;
    TRISB = 0x00;
   TRISC = 0x00;

   while(1)
   {
   for(k=23;k<=34;k++)
   {
   
        tens = k / 10;
        units = k % 10;
        for(
        

       portc.f0 = 0x00;   // active power for digit left
       portb = arrayCC[tens]; // provide data for left digit
       delay_ms(5);
       portc.f0 = 0xff;   // Deactive power for digit left

       portc.f1 = 0x00;     // active power for second digit
       portb = arrayCC[units];    // provide data for second digit
       delay_ms(5);
       portc.f1 = 0xff;      // deactive power for second digit
       delay_ms(1000);
      }

     }
}