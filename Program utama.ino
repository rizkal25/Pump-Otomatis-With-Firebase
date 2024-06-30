#include "Countimer.h"
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SparkFunHTU21D.h>
#include <FirebaseESP32.h>
#include <Esp32WifiManager.h>
#include <Adafruit_HTU21DF.h>
#include <Wire.h>


// Parameter firebass dan wifi
#define FIREBASE_HOST "https://smart-agri-2f20a-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "AIzaSyCSlXYpgrMFjJ9Ijg3qs__mo8w25YYMYQY"
#define WIFI_SSID "Rizkal"
#define WIFI_PASSWORD "rizkal25"
#define TFT_CS 16
#define TFT_DC 5
#define TFT_MOSI 23
#define TFT_SCK 14
#define TFT_RST 17
#define TFT_MISO 19
#define WHITE 0xFFFF
#define BLACK 0x0000
#define SDAX  33
#define SCLX  32
#define kipas 13

int relay1 = 27;
int time_h=0;
int time_m=0;
int time_s=0;

int tesjam = 0;
String jam;
String menit;
String detik;
int waktu_kontrol1 = 0;
int waktu_kontrol2 = 0;
String FBStatus;
String status_waktu;


FirebaseData firebaseData;
HTU21D myhtu21d;
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
Countimer tdown;

//Adafruit_HTU21DF humidity_suhu;
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RST, TFT_MISO);
//sda 33 scl 32 sensor suhu
//kipas 13, led 2, relay 27,
// mosi 23, miso 19, sclk 14, rst lcd 17 , cs 16, dc 5


void setup() {

  Wire.begin(SDAX, SCLX);
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(BLACK);
  // tft.background(250,16,200);
  tft.setTextColor(WHITE);
  tft.setCursor(135, 50);
  tft.setTextSize(3);
  tft.println("POC");

  tft.setCursor(10, 100);
  tft.setTextSize(3);
  tft.println("SMART AGRICULTURE");

  //  tft.println("SMARTAGRICULTURE");
  //  tft.setCursor(20,30);
  //  tft.println("JICA-UGM");
  //  tft.setCursor(60,120);
  //  tft.println("2022");
  //  tft.setCursor(50,24);
  Serial.begin(9600);
  //   htu2x.begin();
  myhtu21d.begin();

  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, LOW);
  pinMode(kipas, OUTPUT);
  digitalWrite(kipas, LOW);


  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  if (WiFi.status() == WL_CONNECTED) {

    Serial.print("connecting");
  }
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    digitalWrite(relay1, LOW);
    delay(500);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  tdown.setInterval(print_time, 999);
  //Firebase.setInt("S1",0);
}


void tdownComplete() {
  Serial.print("ok");
}

void loop() {
  suhu();

  waktu_setting();

}
