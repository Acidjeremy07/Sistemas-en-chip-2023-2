#include <dht.h>
#include <LiquidCrystal_I2C.h>
#include <VL53L0X.h>

LiquidCrystal_I2C lcd(0X27,16,2);
dht DHT;
#define DHT11_PIN 7
VL53L0X sensor;

#define LED_ROJO 5
#define LED_AMARILLO 4
#define LED_VERDE 3

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);

  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();

  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");

  int distance_mm = sensor.readRangeContinuousMillimeters();
  float distance_cm = distance_mm / 10.0;

  if (sensor.timeoutOccurred()) {
    lcd.setCursor(0,1); 
    lcd.print("Error      ");
  } else {
    lcd.setCursor(0,1); 
    lcd.print("Dist: ");
    lcd.print(distance_cm);
    lcd.print(" cm ");
  }

  if (distance_cm < 6) {
    digitalWrite(LED_ROJO, HIGH);
    delay(500);
    digitalWrite(LED_ROJO, LOW);
    delay(500);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_VERDE, LOW);
  } else if (distance_cm >= 6.1 && distance_cm <= 12) {
    digitalWrite(LED_AMARILLO, HIGH);
    delay(500);
    digitalWrite(LED_AMARILLO, LOW);
    delay(500);
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_VERDE, LOW);
  } else if (distance_cm > 12) {
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(LED_AMARILLO, LOW);
  }

  delay(500); // Retardo adicional para estabilizar la lectura
}
