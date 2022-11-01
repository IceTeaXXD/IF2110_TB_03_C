/* ADT Food */
/*Memiliki data ID makanan, Nama makanan, Waktu kedaluwarsa, Lokasi aksi, dan Lama pengiriman.*/

#ifndef FOOD_H
#define FOOD_H

#include "../utility/boolean.h"
#include "../time/time.h"
#include "../wordmachine/wordmachine.h"

typedef struct
{
   int id;
   Word food_name;
   TIME expiry_time;
   Word action;
   TIME delivery_time;
   //  int id;
   //  char *food_name;
   //  TIME expiry_time;
   //  char *action;
   //  TIME delivery_time;

}food;

/*  Kamus Umum */
#define CAPACITY 100
/* Kapasitas penyimpanan */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define LISTMARK -9999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef food ElType;  /* type elemen List */
typedef int IdxType;
typedef struct {
   ElType contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListFoodStatik;




#define FoodId(F) (F).id
#define FoodName(F) (F).food_name
#define FoodExpiry(F) (F).expiry_time
#define FoodAction(F) (F).action
#define FoodDelivery(F) (F).delivery_time
#define LISTELMT(l, i) (l).contents[(i)]

void CreateFood(food *x, int id, Word name, TIME expiry, Word action, TIME delivery);

void DisplayFood(food x);

void ReadFood_FILE(char filename[], ListFoodStatik *listfood);

/*-------------------------------------*/
/*-------------List Food---------------*/
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListFoodStatik(ListFoodStatik *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength_ListFoodStatik(ListFoodStatik l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty_ListFoodStatik(ListFoodStatik l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */

void printList_ListFoodStatik(ListFoodStatik l);
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */


/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf_ListFoodStatik(ListFoodStatik l, int val);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst_ListFoodStatik(ListFoodStatik *l, ElType val);
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt_ListFoodStatik(ListFoodStatik *l, ElType val, IdxType idx);
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertLast_ListFoodStatik(ListFoodStatik *l, ElType val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

#endif  

