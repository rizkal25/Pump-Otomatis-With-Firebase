//Program Kendali Relay dengan Waktu
void waktu_setting() {
    
  if (Firebase.getString(firebaseData, "/Hasil_Pembacaan/time_h")) {
    jam = firebaseData.stringData();
    time_h = jam.toInt();
    //time_h=firebaseData.intData();
    Serial.print("jam:");
    Serial.print (time_h);
  }

  if (Firebase.getString(firebaseData, "/Hasil_Pembacaan/time_m")) {
    menit = firebaseData.stringData();
    time_m = menit.toInt();
      //print_time();
    Serial.print("menit:");
    Serial.print (time_m);
  }
  if (Firebase.getString(firebaseData, "/Hasil_Pembacaan/time_s")) {
    detik = firebaseData.stringData();
    //time_s=firebaseData.intData();
    time_s = detik.toInt();
    Serial.print("detik:");
    Serial.print (time_s);
  }
  if (Firebase.getString(firebaseData, "/Hasil_Pembacaan/S2_waktu")) {
    status_waktu = firebaseData.stringData();
  }

  if (status_waktu == "1") {
    waktu_kontrol1 = 1;
    digitalWrite(relay1, HIGH);
    tdown.restart();
    tdown.start();
  }

  if (time_s == 0 && time_m == 0 && time_h == 0 && waktu_kontrol1 == 1) {
    waktu_kontrol2 = 0;
    tdown.stop();
    digitalWrite(relay1, LOW);
    tesjam = 0;
  }

  if (waktu_kontrol1 == 1) {
    digitalWrite(relay1, HIGH);

  }
  else {
    digitalWrite(relay1, LOW);
  }

}
