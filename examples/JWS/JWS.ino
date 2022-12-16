byte tanggalSekarang = 16;
byte bulanSekarang = 12;
int tahunSekarang = 2022;

// Koordinat Sumedang Selatan
float latitudeSetempat = -6.8671778;
float longitudeSetempat = 107.9172078;

byte timezoneSetempat = 7; // WIB=7, WITA=8, WIT=9
#include "JadwalWaktuShalat.h"

int jamSekarang = 3;
int menitSekarang = 48;

boolean flagSubuh = false;
boolean flagDzuhur = false;
boolean flagAshar = false;
boolean flagMaghrib = false;
boolean flagIsya = false;

#include<KRrtc.h>

void setup() {
  Serial.begin(19200);
  waktuShalatDimulai();
  rtcBegin();
  //  setComputer();
  //  setManual(2020, 4, 8, 16, 1, 0);
}

void loop() {
  dapatkanWaktuShalat();
  rtcGet();
  tanggalSekarang = tanggal;
  bulanSekarang = bulan;
  tahunSekarang = tahun;
  jamSekarang = jam;
  menitSekarang = menit;

  // KODING JADWAL SUBUH
  int jamSubuh = jadwalShalat(satuanWaktu[SUBUH][JAM]).toInt();
  int menitSubuh = jadwalShalat(satuanWaktu[SUBUH][MENIT]).toInt();
  int selisihMenitSubuh =
    selisihMenit(jamSubuh, menitSubuh, jamSekarang, menitSekarang);
  Serial.println(String() + namaWaktu[SUBUH] + "\t" + jamSubuh + ":" +
                 menitSubuh);
  Serial.println(String() + "Selisih Menit Subuh:" + selisihMenitSubuh);
  if ((selisihMenitSubuh == 45) && (flagSubuh == false)) {
    Serial.println("PLAY MURUTALLL...");
    flagSubuh = true;
  } else if (selisihMenitSubuh != 15) {
    flagSubuh = false;
  } else if (selisihMenitSubuh == 0) {
    Serial.println("NOTIF LED...WAKTU ADZAN");
  }

  // KODING JADWAL DZUHUR
  int jamDzuhur = jadwalShalat(satuanWaktu[DZUHUR][JAM]).toInt();
  int menitDzuhur = jadwalShalat(satuanWaktu[DZUHUR][MENIT]).toInt();
  int selisihMenitDzuhur =
    selisihMenit(jamDzuhur, menitDzuhur, jamSekarang, menitSekarang);
  Serial.println(String() + namaWaktu[DZUHUR] + "\t" + jamDzuhur + ":" +
                 menitDzuhur);
  Serial.println(String() + "Selisih Menit Dzuhur:" + selisihMenitDzuhur);
  if ((selisihMenitDzuhur == 45) && (flagDzuhur == false)) {
    Serial.println("PLAY MURUTALLL...");
    flagDzuhur = true;
  } else if (selisihMenitDzuhur != 15) {
    flagDzuhur = false;
  } else if (selisihMenitDzuhur == 0) {
    Serial.println("NOTIF LED...WAKTU ADZAN");
  }

  // KODING JADWAL ASHAR
  int jamAshar = jadwalShalat(satuanWaktu[ASHAR][JAM]).toInt();
  int menitAshar = jadwalShalat(satuanWaktu[ASHAR][MENIT]).toInt();
  int selisihMenitAshar =
    selisihMenit(jamAshar, menitAshar, jamSekarang, menitSekarang);
  Serial.println(String() + namaWaktu[ASHAR] + "\t" + jamAshar + ":" +
                 menitAshar);
  Serial.println(String() + "Selisih Menit Ashar:" + selisihMenitAshar);
  if ((selisihMenitAshar == 45) && (flagAshar == false)) {
    Serial.println("PLAY MURUTALLL...");
    flagAshar = true;
  } else if (selisihMenitAshar != 15) {
    flagAshar = false;
  } else if (selisihMenitAshar == 0) {
    Serial.println("NOTIF LED...WAKTU ADZAN");
  }

  // KODING JADWAL MAGHRIB
  int jamMaghrib = jadwalShalat(satuanWaktu[MAGHRIB][JAM]).toInt();
  int menitMaghrib = jadwalShalat(satuanWaktu[MAGHRIB][MENIT]).toInt();
  int selisihMenitMaghrib =
    selisihMenit(jamMaghrib, menitMaghrib, jamSekarang, menitSekarang);
  Serial.println(String() + namaWaktu[MAGHRIB] + "\t" + jamMaghrib + ":" +
                 menitMaghrib);
  Serial.println(String() + "Selisih Menit Maghrib:" + selisihMenitMaghrib);
  if ((selisihMenitMaghrib == 45) && (flagMaghrib == false)) {
    Serial.println("PLAY MURUTALLL...");
    flagMaghrib = true;
  } else if (selisihMenitMaghrib != 15) {
    flagMaghrib = false;
  } else if (selisihMenitMaghrib == 0) {
    Serial.println("NOTIF LED...WAKTU ADZAN");
  }

  // KODING JADWAL ISYA
  int jamIsya = jadwalShalat(satuanWaktu[ISYA][JAM]).toInt();
  int menitIsya = jadwalShalat(satuanWaktu[ISYA][MENIT]).toInt();
  int selisihMenitIsya =
    selisihMenit(jamIsya, menitIsya, jamSekarang, menitSekarang);
  Serial.println(String() + namaWaktu[ISYA] + "\t" + jamIsya + ":" + menitIsya);
  Serial.println(String() + "Selisih Menit Isya:" + selisihMenitIsya);
  if ((selisihMenitIsya == 45) && (flagIsya == false)) {
    Serial.println("PLAY MURUTALLL...");
    flagIsya = true;
  } else if (selisihMenitIsya != 15) {
    flagIsya = false;
  } else if (selisihMenitIsya == 0) {
    Serial.println("NOTIF LED...WAKTU ADZAN");
  }

  delay(1500);
}
