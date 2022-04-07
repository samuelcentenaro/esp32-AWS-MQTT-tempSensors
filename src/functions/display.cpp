/* setup and main functions for display LCD */
#include "display.h"

//drivers for sensors
LiquidCrystal_I2C lcd(0x27, 16, 2); // driver for LCD

/*                    Initialize and enable the LCD                           */
#if DISPLAY_ENABLE == true
void displayInit()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();
}
#endif