void motorkontrol(int solmotorpwm,int sagmotorpwm){  //Örnek: motorkontrol (-50,50);




if(solmotorpwm<=0){
  solmotorpwm = abs(solmotorpwm);
  digitalWrite(solBin2,LOW);
  digitalWrite(solBin1,HIGH);
  analogWrite(solmotorpwmpin,solmotorpwm);
}
else{
  digitalWrite(solBin2,HIGH);
  digitalWrite(solBin1,LOW);
  analogWrite(solmotorpwmpin,solmotorpwm);
}  

if(sagmotorpwm<=0){
  sagmotorpwm = abs(sagmotorpwm);
  digitalWrite(sagAin2,LOW);
  digitalWrite(sagAin1,HIGH);
  analogWrite(sagmotorpwmpin,sagmotorpwm);
}
else{
  digitalWrite(sagAin2,HIGH);
  digitalWrite(sagAin1,LOW);
  analogWrite(sagmotorpwmpin,sagmotorpwm);
}  
  
  
   }
