void Yazdir(){
  Sicaklik = dht.readTemperature();  //Sıcaklık bilgisini oku
  lcd.setCursor(0,0); // İlk satırın başlangıç noktası
  delay(1000);
  lcd.print("Toprak Nem : %");
  lcd.print(Nem);
  lcd.setCursor(0,1); // İkinci satırın başlangıç noktası
  lcd.print("Sicaklik: ");
  lcd.print(Sicaklik);
  lcd.print("'C");
}
