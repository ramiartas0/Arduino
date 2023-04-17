

void sensoroku(){

unsigned int position = qtra.readLine(sensors,1,zemin);// 7  6  5 4 3 2 1 0
hata=position-hata_tespit;

if(sensors[0]<300&&sensors[7]<300){zemin=0;} // beyaz
if(sensors[0]>700&&sensors[7]>700){zemin=1;} // siyah
}
