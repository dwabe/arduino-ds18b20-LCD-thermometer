#include <DallasTemperature.h>
#include <OneWire.h>
#include <LiquidCrystal_I2C.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu ukladu na 0x27

void setup()
{
  // Inicjacja czujnika
  sensors.begin();
  // Inicjacja wyświetlacza
  lcd.begin(16,2);
  lcd.clear();
  lcd.backlight(); // zalaczenie podswietlenia
}

void loop()
{
   lcd.setCursor(0,0);
   lcd.print("Temperatura:");
   lcd.setCursor(0,1);

   sensors.requestTemperatures();

   lcd.print(sensors.getTempCByIndex(0));

   lcd.setCursor(6, 1);
   lcd.print("st. C");
   delay(1000);
}
