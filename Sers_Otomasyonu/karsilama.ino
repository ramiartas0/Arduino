void karsilama(){
  lcd.setCursor(2,0); // İlk satırın başlangıç noktası
  lcd.print("MEZOPOTAMYA");
  lcd.setCursor(2,1); // İkinci satırın başlangıç noktası
  lcd.print("Living Lab");
  delay(2000);
  lcd.clear();

  for(int i=0; i<17; i++)
  {
    lcd.setCursor(2,0); // İlk satırın başlangıç noktası
    lcd.print("Otonom Sera");
    lcd.setCursor(i,1); // İkinci satırın başlangıç noktası, for döngüsü sayesinde bu sütun sürekli kayacaktır
    lcd.print("Sistemi");
    delay(500);
    lcd.setCursor(i,1);
    lcd.print(" ");
    lcd.clear();
  }  
}
