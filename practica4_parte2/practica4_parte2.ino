#include <dht.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
dht DHT;
#define DHT11_PIN 7

void setup() {
  lcd.begin(16, 1);
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  lcd.init();
  lcd.setCursor(0,0); 
  lcd.backlight();
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");

  // Lógica corregida para imprimir mensajes según la temperatura
  lcd.setCursor(0,1); // Asegúrate de que esta línea esté comentada o eliminada si tu LCD solo tiene 2 filas.
  if (DHT.temperature < 20) {
    lcd.print("Muy baja");
  } else if (DHT.temperature < 30) {
    lcd.print("Es intermedio");
  } else if (DHT.temperature < 40) {
    lcd.print("Muy alto");
  } else {
    lcd.print("Fuera de parametro");
  }

  delay(1000);
}