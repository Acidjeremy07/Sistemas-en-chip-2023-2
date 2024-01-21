// Definir los pines
const int ledPin = 9;  // Pin PWM para el LED
const int buttonUpPin = 2;   // Pin para el botón de aumentar
const int buttonDownPin = 3; // Pin para el botón de disminuir

int ledBrightness = 128;  // Iniciar con una luminosidad media

void setup() {
  // Iniciar los pines
  pinMode(ledPin, OUTPUT);
  pinMode(buttonUpPin, INPUT);
  pinMode(buttonDownPin, INPUT);
}

void loop() {
  // Aumentar la luminosidad si se presiona el botón de arriba
  if (digitalRead(buttonUpPin) == HIGH) {
    ledBrightness += 5;
    if (ledBrightness > 255) ledBrightness = 255;
    delay(100); // Pequeño retardo para evitar cambios demasiado rápidos
  }

  // Disminuir la luminosidad si se presiona el botón de abajo
  if (digitalRead(buttonDownPin) == HIGH) {
    ledBrightness -= 5;
    if (ledBrightness < 0) ledBrightness = 0;
    delay(100); // Pequeño retardo
  }

  // Establecer la luminosidad del LED
  analogWrite(ledPin, ledBrightness);
}
