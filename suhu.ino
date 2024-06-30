void suhu() {
  //Program  Sensor
  float kelembaban = myhtu21d.readHumidity();
  float suhu = myhtu21d.readTemperature();
  Serial.print("kelembaban=");
  Serial.println(kelembaban);
  Serial.print("suhu");
  Serial.println(suhu);
  delay(500);

  if (suhu >= 35 ) {
    digitalWrite(kipas, HIGH);
  }
  else {
    digitalWrite(kipas, LOW);
  }

  // Memberikan status suhu dan kelembaban kepada firebase
  if (Firebase.setFloat(firebaseData, "/Hasil_Pembacaan/suhu", suhu)) {
    Serial.println("Suhu terkirim");
  } else {
    Serial.println("Suhu tidak terkirim");
    Serial.println("Karena: " + firebaseData.errorReason());
  }

  if (Firebase.setFloat(firebaseData, "/Hasil_Pembacaan/kelembaban", kelembaban)) {
    Serial.println("Kelembaban terkirim");
    Serial.println();
  } else {
    Serial.println("Kelembaban tidak terkirim");
    Serial.println("Karena: " + firebaseData.errorReason());
  }
}
