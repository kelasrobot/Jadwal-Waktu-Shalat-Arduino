#include "PrayerTimes.h"
double waktu[sizeof(TimeName) / sizeof(char*)];
static const char* namaWaktu[] = {
  "Imsak",
  "Subuh",
  "Syuruq",
  "Dzuhur",
  "Ashar",
  "Terbenam",
  "Maghrib",
  "Isya",
  "Count"
};
const byte JUMLAH_WAKTU_DEFAULT = sizeof(waktu) / sizeof(double);
const byte JUMLAH_WAKTU = sizeof(namaWaktu) / sizeof(char*);
const byte DATA_WAKTU = 2; // jam dan menit
byte satuanWaktu[JUMLAH_WAKTU][DATA_WAKTU];
// sudut subuh dan maghrib Indonesia
int _sudut_subuh = 20;
int _sudut_isyak = 18;

#define IMSAK 0
#define SUBUH 1
#define SYURUQ 2
#define DZUHUR 3
#define ASHAR 4
#define TERBENAM 5
#define MAGHRIB 6
#define ISYA 7

#define JAM 0
#define MENIT 1


void waktuShalatDimulai() {
  set_calc_method(ISNA);  // metode perhitungan
  set_asr_method(Shafii); // madzhab?
  set_high_lats_adjust_method(AngleBased);
  set_fajr_angle(_sudut_subuh);     // sudut waktu subuh
  set_isha_angle(_sudut_isyak);     // sudut waktu isyak
}

void WaktuShalat(byte WaktuShalat[JUMLAH_WAKTU][DATA_WAKTU]) {
  get_prayer_times(tahunSekarang, bulanSekarang, tanggalSekarang, latitudeSetempat, longitudeSetempat, timezoneSetempat, waktu);
  byte waktu_custom = 0;
  for (byte i = 0; i < JUMLAH_WAKTU_DEFAULT - 1; i++) {
    int jam, menit;
    get_float_time_parts(waktu[i], jam, menit);
    if ( i == 0 ) {
      satuanWaktu[waktu_custom][0] = jam;
      satuanWaktu[waktu_custom][1] = menit - 10;
      waktu_custom++;
      satuanWaktu[waktu_custom][0] = jam;
      satuanWaktu[waktu_custom][1] = menit;
    } else {
      satuanWaktu[waktu_custom][0] = jam;
      satuanWaktu[waktu_custom][1] = menit;
    }
    waktu_custom++;
  }
}

String jadwalShalat(byte angka) {
  if ( angka > 9 ) {
    return String(angka);
  } else {
    String tmp = "0";
    tmp.concat(angka);
    return tmp;
  }
}

void dapatkanWaktuShalat() {
  WaktuShalat(satuanWaktu);
}

int selisihMenit(int jamJadwalShalat, int menitJadwalShalat, int jamSekarang, int menitSekarang) {
  int totalMenitJadwalShalat = 0;
  int selisihMenitJadwalShalatDanSekarang;
  int totalMenitSekarang;
  selisihMenitJadwalShalatDanSekarang;
  totalMenitJadwalShalat = (jamJadwalShalat * 60) + menitJadwalShalat;
  totalMenitSekarang = (jamSekarang * 60) + menitSekarang;
  selisihMenitJadwalShalatDanSekarang = totalMenitJadwalShalat - totalMenitSekarang;
  return selisihMenitJadwalShalatDanSekarang;
}