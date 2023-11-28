sbit LCD_RS at RB0_bit;
sbit LCD_EN at RB1_bit;
sbit LCD_D4 at RB2_bit;
sbit LCD_D5 at RB3_bit;
sbit LCD_D6 at RB4_bit;
sbit LCD_D7 at RB5_bit;

sbit LCD_RS_Direction at TRISB0_bit;
sbit LCD_EN_Direction at TRISB1_bit;
sbit LCD_D4_Direction at TRISB2_bit;
sbit LCD_D5_Direction at TRISB3_bit;
sbit LCD_D6_Direction at TRISB4_bit;
sbit LCD_D7_Direction at TRISB5_bit;
// LCD Module connection End

char display[16] = "";

void main() {
    unsigned int result;
    float volt, tempC, tempF;
    trisb = 0x00;
    trisa = 0xff;
    adcon1 = 0x80;
    lcd_init();                 // Initialize LCD
    lcd_cmd(_lcd_clear);        // Clear LCD
    lcd_cmd(_lcd_cursor_off);   // Cursor Off of LCD

    while (1) {
        result = adc_read(0);   // Read ADC value in RA0
        volt = result * 4.88;
        tempC = volt / 10;

        // Celsius temperature display
        lcd_out(1, 1, "Temp(C): ");
        floattostr(tempC, display);
        lcd_out_cp(display);
        lcd_chr(1, 16, 223);      // Print degree symbol
        lcd_out_cp(" C  ");

        // Fahrenheit temperature calculation and display
        tempF = (tempC * 9 / 5) + 32;
        lcd_out(2, 1, "Temp(F): ");
        floattostr(tempF, display);
        lcd_out_cp(display);
        lcd_chr(2, 16, 223);      // Print degree symbol
        lcd_out_cp(" F  ");
    }
}
