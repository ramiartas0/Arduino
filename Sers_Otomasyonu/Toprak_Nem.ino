void Toprak_nem(){
  Nem= analogRead(Toprak_Nem);
  Nem=map(Nem,0,1023,100,0);
}
