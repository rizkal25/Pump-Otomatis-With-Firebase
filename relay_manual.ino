void relay_manual() {

  //Program Kendali Relay Manual

  if (Firebase.getString(firebaseData, "/Hasil_Pembacaan/S1")) {
    FBStatus = firebaseData.stringData();
  }
  if (FBStatus == "1") {
    Serial.println("Relay ON");
    digitalWrite(relay1, HIGH);
  }
  else if (FBStatus == "0") {
    Serial.println("Relay OFF");
    digitalWrite(relay1, LOW);
  }
  else {
    Serial.println("Salah Kode Isi Data ON/OFF");
  }
}
