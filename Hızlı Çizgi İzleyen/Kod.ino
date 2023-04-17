//14.ROBOT YARIŞMASI HIZLI ÇİZGİ İZLEYEN ROBOT KODALRI
//............................................................................
//Yazan: Muhammed Rami ARTAŞ
#include <QTRSensors.h>
#define min_hiz 100
#define sagAin2 10
#define sagAin1 11
#define sagmotorpwmpin 5
#define solBin2 8
#define solBin1 7
#define solmotorpwmpin 6
#define mesafe_sensor 4
#define solencoder 2
#define sagencoder 3
#define pervane 9
#define taktik_1 12
#define taktik_2 13
//----------------------------------------------------------------------------
QTRSensorsAnalog qtra((unsigned char[]) {A0, A1, A2, A3, A4, A5, A6, A7},8);
//Değişgenleri tanımladık.
unsigned int sensors[8];//sensors[7],sensors[6],sensors[5],sensors[4],sensors[3],sensors[2],sensors[1],sensors[0]
float Kp = 0.04;      float Kd = 0.06;      //float Ki = 0.0001;
int ekhiz = 0;        int sonhata = 0;      int hata = 0;
int sagmotorpwm = 0;  int solmotorpwm = 0;  int zemin = 1;     
int pist_bolum = 1;   int durak = 0;        int hata_tespit = 3500;
int t_say = 0;
int sag_encoder_yuzey = 0;     int sag_encoder_say = 0;
int sol_encoder_yuzey = 0;     int sol_encoder_say = 0;
int taktik_durum;              int engel_durum;
int duz_yol_durum = 0;
int start_durum=0;
int t_durum=0;
int bitis_durum=1;
int rulman_durum=20;
float ortalama_uzunluk = 0;
float tur_carpani = 5.024; //Yarı çap 1.6 ve formül 2*3.14*r/2
void setup() {
    //Dijital pinler giriş veya çıkış olarak kullanıldı..
  Serial.begin(9600);
  pinMode(sagAin2,OUTPUT);        pinMode(sagAin1,OUTPUT); 
  pinMode(sagmotorpwmpin,OUTPUT);
  pinMode(solBin2,OUTPUT);        pinMode(solBin1,OUTPUT);
  pinMode(solmotorpwmpin,OUTPUT);
  pinMode(pervane,OUTPUT);        pinMode(mesafe_sensor,INPUT);
  pinMode(taktik_1,INPUT);        pinMode(taktik_2,INPUT);
  pinMode(solencoder,INPUT);      pinMode(sagencoder,INPUT);
  analogWrite(pervane,0);

  
  delay(1000);

for(int i=0;i<150;i++)
{
  if(0<=i && i<5) motorkontrol(15+rulman_durum,-15-rulman_durum);
  if(5<=i && i<15) motorkontrol(-15-rulman_durum,15+rulman_durum);
  if(15<=i && i< 25) motorkontrol(15+rulman_durum,-15-rulman_durum);
  if(25<=i && i<35) motorkontrol(-15-rulman_durum,15+rulman_durum);
  if(35<=i && i< 40) motorkontrol(15+rulman_durum,-15-rulman_durum);
  if(45<=i && i<50) motorkontrol(-15-rulman_durum,15+rulman_durum);
qtra.calibrate();delay(1);
if(i>=50){
motorkontrol(0,0);
delay(3);}}

while(digitalRead(mesafe_sensor)==HIGH){dur();}

}
void loop() {
  sensoroku();
  pd();
  motorkontrol(solmotorpwm,sagmotorpwm);
  encodersay();
if(durak==0) {duz_yol(270,10,50,50);dur();}
  }
