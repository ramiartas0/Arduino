void t_yol(int sol_don,int duz_git,int sag_don){
 //Siyah zeminde 
 if(t_durum==0){ 
//finish
if(duz_git==0&&sol_don==0&&sag_don==0&&sensors[0]<300&&sensors[1]<300&&sensors[2]<300&&sensors[3]<300&&sensors[4]<300&&sensors[5]<300&&sensors[6]<300&&sensors[7]<300){
motorkontrol(min_hiz+ekhiz,min_hiz+ekhiz);delay(0);
 duz_git=0;analogWrite(pervane,0);t_durum=1;dur();
}
//finish



  
if(duz_git==1&&sol_don==0&&sag_don==0&&sensors[0]<300&&sensors[1]<300&&sensors[2]<300&&sensors[3]<300&&sensors[4]<300&&sensors[5]<300&&sensors[6]<300&&sensors[7]<300){
t_say=t_say+1;
while(1)      {
  sensoroku();
  motorkontrol(min_hiz+ekhiz,min_hiz+ekhiz);
  if(!(sensors[0]<300&&sensors[1]<300&&sensors[2]<300&&sensors[3]<300&&sensors[4]<300&&sensors[5]<300&&sensors[6]<300&&sensors[7]<300)){
 duz_git=0;analogWrite(pervane,0);t_durum=1; break;}}}

if(duz_git==0&&sol_don==1&&sag_don==0&&sensors[0]<300&&sensors[1]<300&&sensors[2]<300&&sensors[3]<300&&sensors[4]<300&&sensors[5]<300&&sensors[6]<300&&sensors[7]<300){
motorkontrol(-30,60);
while(1){
  sensoroku();  
  if(sensors[5]>700&&sensors[6]>700){break;}
        }       
while(1){
  sensoroku();  
  motorkontrol(-30,60);
  if(sensors[7]<300||sensors[6]<300){
ekhiz=0;sol_encoder_say=0;sag_encoder_say=0;ortalama_uzunluk=0;analogWrite(pervane,0);sol_don=1;t_durum=1;break;}
        }             }
if(duz_git==0&&sol_don==0&&sag_don==1&&sensors[0]<300&&sensors[1]<300&&sensors[2]<300&&sensors[3]<300&&sensors[4]<300&&sensors[5]<300&&sensors[6]<300&&sensors[7]<300){
motorkontrol(60,-30);
while(1){
  sensoroku();  
  if(sensors[5]>700&&sensors[6]>700){break;}
        }       
while(1){
  sensoroku();  
  motorkontrol(60,-30);
  if(sensors[7]<300||sensors[6]<300){
ekhiz=0;sol_encoder_say=0;sag_encoder_say=0;ortalama_uzunluk=0;analogWrite(pervane,0);sag_don=1;t_durum=1;break;}
        }             }
 }


}
