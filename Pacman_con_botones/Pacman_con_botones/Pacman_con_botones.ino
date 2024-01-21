#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte CharPACMANDERECHA[8] = 
{
  B01110,
  B11111,
  B11011,
  B11111,
  B11100,
  B11111,
  B11111,
  B01110
};

byte CharPACMANIZQUIERDA[8] = 
{
  B01110,
  B11111,
  B11011,
  B11111,
  B00111,
  B11111,
  B11111,
  B01110
};

const int botonDerechaPin   = 2;
const int botonIzquierdaPin = 3;
const int botonReinicio     = 4;
bool inicio = true;
bool moviendoDerecha = true;
int posicionActual = 0;
int filaActual = 0;

void setup() 
{
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, CharPACMANDERECHA);
  lcd.createChar(1, CharPACMANIZQUIERDA);

  pinMode(botonDerechaPin, INPUT_PULLUP);
  pinMode(botonIzquierdaPin, INPUT_PULLUP);
  pinMode(botonReinicio, INPUT_PULLUP);

  mostrarMensajeInicial();
}

void loop() {
  if (inicio) {
    if (!digitalRead(botonDerechaPin)) 
    {
      inicio = false;
      moviendoDerecha = true;
      moverPacman(0, 0, true); // Comenzar desde la primera línea (0), moviéndose hacia la derecha
    } else if (!digitalRead(botonIzquierdaPin))
    {
      inicio = false;
      moviendoDerecha = false;
      moverPacman(15, 1, false); // Comenzar desde la segunda línea (1), moviéndose hacia la izquierda
    }
  }

  if (!digitalRead(botonReinicio)) 
  {
    mostrarMensajeInicial();
    inicio = true;
    delay(500); // Retraso para evitar rebotes del botón
  }
}

void mostrarMensajeInicial() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("_____PACMAN_____");
  lcd.setCursor(0, 1);
  lcd.print("PracticaEmbebido");
}

void moverPacman(int posicionInicial, int filaInicial, bool derecha) {
  posicionActual = posicionInicial;
  filaActual = filaInicial;
  moviendoDerecha = derecha;

  while (true) {
    lcd.setCursor(posicionActual, filaActual);
    lcd.write(byte(moviendoDerecha ? 0 : 1));
    delay(300);
    lcd.setCursor(posicionActual, filaActual);
    lcd.print(" ");

    if (moviendoDerecha) 
    {
      if (posicionActual < 15) 
      {
        posicionActual++;
      } else if (filaActual == 0) 
      {
        posicionActual = 0;
        filaActual = 1;
      } else 
      {
        mostrarMensajeInicial();
        inicio = true;
        return; // Salir de la función
      }
    } else 
    {
      if (posicionActual > 0) 
      {
        posicionActual--;
      } else if (filaActual == 1) 
      {
        posicionActual = 15;
        filaActual = 0;
      } else 
      {
        mostrarMensajeInicial();
        inicio = true;
        return; // Salir de la función
      }
    }

    if (!digitalRead(botonReinicio)) 
    {
      mostrarMensajeInicial();
      inicio = true;
      return; // Salir de la función moverPacman
    }

    // Cambiar la dirección si se presiona el botón contrario
    if (moviendoDerecha && !digitalRead(botonIzquierdaPin)) {
      moviendoDerecha = false;
      delay(500); // Retraso para evitar rebotes del botón
    } else if (!moviendoDerecha && !digitalRead(botonDerechaPin)) {
      moviendoDerecha = true;
      delay(500); // Retraso para evitar rebotes del botón
    }
  }
}
