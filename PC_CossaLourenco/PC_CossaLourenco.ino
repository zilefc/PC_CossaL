#include <LiquidCrystal_I2C.h>

int sensorSala = 3;
int sensorCorredor = 4;
int lampadaSala = 13;
int lampadaCorredor = 10;
int ldrSala = A1;
int ldrCorredor = A2;

LiquidCrystal_I2C display(0x3F, 16, 2);

void setup() {
  pinMode(lampadaSala, OUTPUT);
  pinMode(lampadaCorredor, OUTPUT);
  pinMode(ldrSala, INPUT);
  pinMode(ldrCorredor, INPUT);
  pinMode(sensorSala, INPUT);
  pinMode(sensorCorredor, INPUT);

  display.init();
  display.backlight();
  display.setCursor(3, 0);
  display.print("Iniciando..........");

}

void loop() {
  int LDRsala = analogRead(ldrSala);
  boolean SENSORsala = digitalRead(sensorSala);
  int LDRcorredor = analogRead(ldrCorredor);
  boolean SENSORcorredor = digitalRead(sensorCorredor);

  if (LDRsala > 500 && SENSORsala == LOW) {
    digitalWrite(lampadaSala, HIGH);
    display.clear();
    display.setCursor(0, 0);
    display.print("luz ligada");
  }

  if (LDRcorredor > 500) {
    analogWrite(lampadaCorredor, 127);
    if ( SENSORcorredor == LOW) {
      analogWrite(lampadaCorredor, 255);
      display.clear();
      display.setCursor(0, 0);
      display.print("luz ligada");
    }
  }
}
