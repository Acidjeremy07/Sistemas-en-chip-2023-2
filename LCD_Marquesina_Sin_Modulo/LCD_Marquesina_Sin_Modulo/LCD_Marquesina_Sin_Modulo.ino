#include <LiquidCrystal.h>

// Define los nuevos pines para el LCD
const int rs = 0, enable = 1, d4 = 2, d5 = 3, d6 = 4, d7 = 5;

// Inicializa el LCD con los nuevos números de pines de la interfaz
LiquidCrystal lcd(rs, enable, d4, d5, d6, d7);

String mensaje = "Hernandez Salinas Diego Alberto ";
int maxDisplayChars = 16;

void setup() {
  lcd.begin(16, 2); // Configura el número de columnas y filas del LCD
}

void loop() {
  int mensajeLength = mensaje.length();
  // Muestra el mensaje con efecto de marquesina
  for (int i = 0; i < mensajeLength + maxDisplayChars; i++) {
    lcd.clear();

    // Calcula la cantidad de espacios a agregar al inicio
    int spaces = min(maxDisplayChars, maxDisplayChars - i);

    // Crea una cadena de espacios
    String spaceString = "";
    for (int j = 0; j < spaces; j++) {
      spaceString += " ";
    }

    // Calcula el inicio de la subcadena a mostrar
    int start = max(0, i - maxDisplayChars);

    // Crea la cadena para mostrar
    String displayString = spaceString + mensaje.substring(start, min(i, mensajeLength));

    // Muestra la porción del mensaje
    lcd.setCursor(0, 0);
    lcd.print(displayString);

    delay(400);
  }
}
