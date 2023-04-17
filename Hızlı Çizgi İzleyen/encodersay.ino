
void encodersay(){
if(digitalRead(solencoder)==0&&sol_encoder_yuzey==0){
  sol_encoder_yuzey=1;
  sol_encoder_say=sol_encoder_say+1;
Serial.println(sol_encoder_say);
Serial.print("\t");
}
if(digitalRead(solencoder)==1){sol_encoder_yuzey=0;}       
if(digitalRead(sagencoder)==0&&sag_encoder_yuzey==0){sag_encoder_yuzey=1;sag_encoder_say=sag_encoder_say+1;
  Serial.println(sag_encoder_say);
  Serial.print("\n");
}
if(digitalRead(sagencoder)==1){
  sag_encoder_yuzey=0;
}
ortalama_uzunluk=(sag_encoder_say+sol_encoder_say)/2*tur_carpani;  
}
