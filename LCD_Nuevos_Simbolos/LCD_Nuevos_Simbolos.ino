#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // Create LCD instance with address 0x27, 16 columns, and 2 rows


//Se deberán crear 5 nuevos caracteres
//Recordemos que la dirección de escritura es
//0x27, y que el LCD es de 16 columnas y 2 filas

byte CharA[8] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B01010,
  B01010,
  B01110,
  B00000
};

byte CharB[8] = {
  B00000,
  B00100,
  B01010,
  B01010,
  B01110,
  B01010,
  B01010,
  B00000
};
byte CharC[8] = {
  B00100,
  B01110,
  B10101,
  B00100,
  B00100,
  B00100,
  B00100,
  B00000
};
byte CharD[8] = {
  B00100,
  B01010,
  B10001,
  B01010,
  B00100,
  B01010,
  B10001,
  B00000
};
byte CharE[8] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};
byte CharF[8] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B01110,
  B10001,
  B00000,
  B00000
};
byte CharG[8] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B10101,
  B01110,
  B00100,
  B00000
};
byte CharH[8] = {
  B10001,
  B01010,
  B00100,
  B01010,
  B10001,
  B00100,
  B01010,
  B00000
};
byte CharI[8] = {
  B01110,
  B10001,
  B10001,
  B01110,
  B01110,
  B01110,
  B01110,
  B00000
};
byte CharJ[8] = {
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111,
  B00000
};
void setup() {
  //inicializar la LCD
  lcd.init();
  //Encender luz de fondo
  lcd.backlight();
  //Crear nuevos caracteres
  lcd.createChar (0, CharA);
  lcd.createChar (1, CharB);
  lcd.createChar (2, CharC);
  lcd.createChar (3, CharD);  
  lcd.createChar (4, CharE);
  lcd.createChar (5, CharF);
  lcd.createChar (6, CharG);
  lcd.createChar (7, CharH);
  lcd.createChar (8, CharI);  
  lcd.createChar (9, CharJ);
  //Escribir texto en el primer caracter de la primera linea
  lcd.setCursor(0,0);
  lcd.print("Clase 6VC2");
  //Escribir en el primer caracter de la segunda linea
  lcd.setCursor(0,1);
  lcd.write (byte (0));
  lcd.print ("");
  lcd.write (byte (1));
  lcd.print ("");
  lcd.write (byte (2));
  lcd.print ("");
  lcd.write (byte (3));
  lcd.print ("");
  lcd.write (byte (4));
  lcd.print ("");
  lcd.write (byte (5));
  lcd.print ("");
  lcd.write (byte (6));
  lcd.print ("");
  lcd.write (byte (7));
  lcd.print ("");
  lcd.write (byte (8));
  lcd.print ("");
  lcd.write (byte (9));
  lcd.print ("");
}

void loop() {
  // put your main code here, to run repeatedly:

}