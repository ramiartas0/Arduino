
void pd(){
 int duzeltmehizi=Kp*hata+Kd*(hata-sonhata);  
 sonhata=hata;


 sagmotorpwm=(min_hiz+ekhiz)+duzeltmehizi;
 solmotorpwm=(min_hiz+ekhiz)-duzeltmehizi;

sagmotorpwm=constrain(sagmotorpwm,-254,254);
solmotorpwm=constrain(solmotorpwm, -254,254);
//motorkontrol(solmotorpwm,sagmotorpwm);
}
