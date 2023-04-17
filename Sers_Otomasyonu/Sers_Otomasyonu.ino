#include <LiquidCrystalTr_I2C.h> //LCD Ekran Kütüphanesi

LiquidCrystal_I2C lcd(0x27,16,2);

#define SDA 20 #define SLC 21

#include "DHT.h"  //DHT kütüphanesini çağır

int Sicaklik_Sensor =  7;  // DHT sensörün bağlı olduğu pini tanımla

int led = 10;

int Sicaklik;

#include <Servo.h>

Servo sag_Servo; 

Servo sol_Servo; 

int Pompa = 4;
 
DHT dht(Sicaklik_Sensor, DHT11);  // dht adında sensör nesnesi tanımla.

int Toprak_Nem = A5;
 
int Nem = 0;
void setup() {
  lcd.begin();  dht.begin(); 
//karsilama();
  pinMode(Toprak_Nem,INPUT);
  pinMode(Pompa, OUTPUT);
  pinMode(led, OUTPUT); //LED'in çıkış elemanı olduğunu belirtiyoruz
  sag_Servo.attach(6);
  sol_Servo.attach(5);
}

void loop() {
  int isik = analogRead(A1); 
    if (isik < 50) { //Okunan ışık değeri 900'den büyük ise
    digitalWrite(led, LOW); //LED yanmasın
  }
   else{
digitalWrite(led, HIGH); //LED yanmasın
}

  Toprak_nem();
  Yazdir();
  if(Sicaklik > 35)
  {
    Servo_sag(70);
    Servo_sol(70);
   }
  
 if(Sicaklik <=35)
 {
    Servo_sag(0);
    Servo_sol(0);
    
 }
  if(Nem < 65)
 {
    digitalWrite(Pompa,LOW);
 }
  if(Nem > 65)
 {
    digitalWrite(Pompa,HIGH);
 } 

}
