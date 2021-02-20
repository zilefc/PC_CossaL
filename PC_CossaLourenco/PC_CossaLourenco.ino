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
Serial.begin(9600);
  display.init();
  display.backlight();
  display.setCursor(0, 0);
  display.print("Iniciando..........");
  display.setCursor(0, 1);
  display.print("Cossa, Lourenco");
}

void loop() {
   delay(1000);
   display.clear();
  int LDRsala = analogRead(ldrSala);
  boolean SENSORsala = digitalRead(sensorSala);
  int LDRcorredor = analogRead(ldrCorredor);
  boolean SENSORcorredor = digitalRead(sensorCorredor);
Serial.println("sala:");
Serial.println(LDRsala);
Serial.println(SENSORsala);


  if ((LDRsala <670) && SENSORsala == HIGH) {
    digitalWrite(lampadaSala, HIGH);
    display.setCursor(0, 0);
    display.print("luz Sl ligada");
  }

  if (LDRcorredor < 670) {
    analogWrite(lampadaCorredor, 127);
    if ( SENSORcorredor == HIGH) {
      analogWrite(lampadaCorredor, 255);
      display.setCursor(0, 1);
      display.print("luz Cor ligada");
    }
  }
}
