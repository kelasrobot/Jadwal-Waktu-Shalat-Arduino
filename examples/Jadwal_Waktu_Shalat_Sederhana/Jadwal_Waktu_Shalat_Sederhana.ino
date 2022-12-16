byte tanggalSekarang = 16;
byte bulanSekarang = 12;
int tahunSekarang = 2022;

//Koordinat Sumedang Selatan
float latitudeSetempat = -6.8671778;
float longitudeSetempat = 107.9172078;

byte timezoneSetempat = 7; // WIB=7, WITA=8, WIT=9
#include "JadwalWaktuShalat.h"

void setup() {
  Serial.begin(19200);
  waktuShalatDimulai();
}

void loop() {
  dapatkanWaktuShalat();

  Serial.println("  =============================");
  Serial.print("  JADWAL SHALAT TGL. ");
  Serial.println(String() + tanggalSekarang + "-" +
                 bulanSekarang + "-" + tahunSekarang);
  Serial.println("  =============================");

  for (int i = 0; i < 8; i++) {
    if ( i == 5 ) continue;
    Serial.print(String() + "\t" + namaWaktu[i]);
    Serial.print(String() + "\t" + jadwalShalat(satuanWaktu[i][0]));
    Serial.println(String() + ":" + jadwalShalat(satuanWaktu[i][1]));
  }
  
  Serial.println();
  delay(5000L);
}