/* File: time.h */
/* Tanggal: 3 September 2022 */
/* Definisi ADT TIME */

#ifndef TIME_H
#define TIME_H

#include "../utility/boolean.h"

/* *** Definisi TYPE TIME <DD:HH:MM> *** */
typedef struct { 
	int DD; /* integer  */
	int HH; /* integer [0..24] */
	int MM; /* integer [0..59] */
} TIME;

/* *** Notasi Akses: selektor TIME *** */
#define Day(T) (T).DD
#define Hour(T) (T).HH
#define MM(T) (T).MM

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int D, int H, int M);
/* Mengirim true jika D,H,M dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Waktu */

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int DD, int HH, int MM);
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : DD, HH, MM valid untuk membentuk TIME */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T);
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan waktu yang valid */
/* Proses : mengulangi membaca komponen DD, HH, MM sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen DD, HH, MM
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */

   
void TulisTIME (TIME T);
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format DDD:HH:MM */
/* Proses : menulis nilai setiap komponen T ke layar dalam format DDD:HH:MM
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
void TulisTIME2 (TIME T);
/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToMenit (TIME T);
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah menut dari pukul 0:0:0 */
/* Rumus : menit = 1440*DD + 60*HH + MM */


TIME MenitToTIME (long N); 
/* Mengirim  konversi menit ke TIME */


/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2);
/* Mengirimkan true jika T1=T2, false jika tidak */
boolean TNEQ (TIME T1, TIME T2);
/* Mengirimkan true jika T1 tidak sama dengan T2 */
boolean TLT (TIME T1, TIME T2);
/* Mengirimkan true jika T1<T2, false jika tidak */
boolean TGT (TIME T1, TIME T2);
/* Mengirimkan true jika T1>T2, false jika tidak */
/* *** Operator aritmatika TIME *** */
TIME NextMenit (TIME T);
/* Mengirim 1 Menit setelah T dalam bentuk TIME */
TIME NextNMenit (TIME T, int N);
/* Mengirim N Menit setelah T dalam bentuk TIME */
TIME PrevMenit (TIME T);
/* Mengirim 1 Menit sebelum T dalam bentuk TIME */
TIME PrevNMenit (TIME T, int N);
/* Mengirim N Menit sebelum T dalam bentuk TIME */
/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh);
/* Mengirim TAkh-TAw dlm Menit, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */

void Timetokata(TIME waktu);

void TambahTime (TIME * T, int DD, int HH, int MM);

#endif