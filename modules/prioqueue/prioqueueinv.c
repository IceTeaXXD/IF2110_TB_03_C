#include "prioqueueinv.h"
#include <stdio.h>
#include "../wordmachine/wordmachine.h"
/* ********* Prototype ********* */
boolean IsEmpty_Prioqueue (Prioqueueinv Q){
    return (Head(Q) == Nil) && (Tail(Q) == Nil);
}
/* Mengirim true jika Q kosong: lihat definisi di atas */

/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt_Prioqueue(Prioqueueinv Q){
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    
    if (IsEmpty_Prioqueue(Q)){
        return 0;
    }
    else {
        if ((Tail(Q) - Head(Q)) >= 0){
            return Tail(Q) - Head(Q) + 1;
        }
        else {
            return MaxElQ(Q) - (Head(Q) - (Tail(Q) + 1));
        }
    }

}

boolean IsFull_Prioqueue (Prioqueueinv Q){
    return (MaxElQ(Q) == NBElmt_Prioqueue(Q));
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty_Prioqueue (Prioqueueinv * Q, int Max){
    (*Q).T = (food *) malloc((Max) * sizeof(food));
    if ((*Q).T == NULL) {
        MaxElQ(*Q) = 0;
    }
    else {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        MaxElQ(*Q) = Max;
    }
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi_Prioqueue(Prioqueueinv * Q){
    {
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    MaxElQ(*Q) = 0;
    free((*Q).T);
}
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue_Prioqueue(Prioqueueinv *Q, food X){
    boolean found;
    int idx;
    int i, j;
    food temp;

    // enqueue based on expiry_time
    if (IsEmpty_Prioqueue(*Q)){
            Head(*Q) = 0;
            Tail(*Q) = 0;
            InfoHead(*Q) = X;
    }
    else if (IsFull_Prioqueue(*Q)){
        printf("Queue is full\n");
    }
    else {
        Tail(*Q) = Tail(*Q) == MaxElQ(*Q) - 1 ? 0 : Tail(*Q) + 1;
        InfoTail(*Q) = X;
        i = Tail(*Q);
        j = (i == 0) ? MaxElQ(*Q) - 1 : i - 1;
        while (i != Head(*Q) && TIMEToMenit(FoodExpiry(Elmt(*Q, i))) < TIMEToMenit(FoodExpiry(Elmt(*Q, j)))){
            temp = Elmt(*Q, i);
            Elmt(*Q, i) = Elmt(*Q, j);
            Elmt(*Q, j) = temp;
            i = j;
            j = (i == 0) ? MaxElQ(*Q) - 1 : i - 1;
        }
    


     /*--------------------------------------------------------*/   
    /*    found = false;
        idx = Head(*Q);
        while ((idx != Tail(*Q)) && (!found)){
            int food_expired = TIMEToMenit(X.expiry_time);
            int head_expired = TIMEToMenit(InfoHead(*Q).expiry_time);
            if (food_expired < head_expired){
                found = true;
            }
            else {
                idx = (idx + 1) % MaxElQ(*Q);
            }
        }
        if (found){
            i = Tail(*Q);
            while (i != idx){
                j = (i - 1 + MaxElQ(*Q)) % MaxElQ(*Q);
                (*Q).T[i] = (*Q).T[j];
                i = j;
            }
            (*Q).T[idx] = X;
            Tail(*Q) = (Tail(*Q) + 1) % MaxElQ(*Q);
        }
        else {
            Tail(*Q) = (Tail(*Q) + 1) % MaxElQ(*Q);
            InfoTail(*Q) = X;
        }
    }
    // } */ }
}
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue_Prioqueue (Prioqueueinv * Q, food * X){
    if (NBElmt_Prioqueue(*Q) == 1) {
        *X = InfoHead(*Q);
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else {
        *X = InfoHead(*Q);
        Head(*Q) = (Head(*Q) == MaxElQ(*Q) - 1) ? 0 : Head(*Q) + 1;
    }
    
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioqueueinv (Prioqueueinv Q){
    int i;
    if (IsEmpty_Prioqueue(Q)){
        printf("Queue is empty\n");
    } else {
        i = Head(Q);
        int idx = 1;
        while (i != Tail(Q)){
            printf("%d. ",idx);
            idx++;

            PrintWord(FoodName(Q.T[i]));
            printf(" (");
            Timetokata(FoodDelivery(Q.T[i]));
            printf(")\n");
            i = (i + 1) % MaxElQ(Q);
        }
        printf("%d. ",idx);
        idx++;

        PrintWord(FoodName(Q.T[i]));
        printf(" (");
        Timetokata(FoodDelivery(Q.T[i]));
        printf(")\n");
    }
}

void PrintInvPrio(Prioqueueinv Q){
    int i;
    if (IsEmpty_Prioqueue(Q)){
        printf("Queue is empty\n");
    }
    else{
        i = Head(Q);
        int idx = 1;
        while (i != Tail(Q)){
            printf("%d. ",idx);
            idx++;

            PrintWord(FoodName(Q.T[i]));
            printf(" (");
            Timetokata(FoodExpiry(Q.T[i]));
            printf(")\n");
            i = (i + 1) % MaxElQ(Q);
        }
        printf("%d. ",idx);
        idx++;

        PrintWord(FoodName(Q.T[i]));
        printf(" (");
        Timetokata(FoodExpiry(Q.T[i]));
        printf(")\n");
    }
}
void Enqueue_Prioqueue_Delivery(Prioqueueinv *Q, food X){
    boolean found;
    int idx;
    int i, j;
    food temp;

    // enqueue based on expiry_time
    if (IsEmpty_Prioqueue(*Q)){
            Head(*Q) = 0;
            Tail(*Q) = 0;
            InfoHead(*Q) = X;
    }
    else if (IsFull_Prioqueue(*Q)){
        printf("Queue is full\n");
    }
    else {
        Tail(*Q) = Tail(*Q) == MaxElQ(*Q) - 1 ? 0 : Tail(*Q) + 1;
        InfoTail(*Q) = X;
        i = Tail(*Q);
        j = (i == 0) ? MaxElQ(*Q) - 1 : i - 1;
        while (i != Head(*Q) && TIMEToMenit(FoodDelivery(Elmt(*Q, i))) < TIMEToMenit(FoodDelivery(Elmt(*Q, j)))){
            temp = Elmt(*Q, i);
            Elmt(*Q, i) = Elmt(*Q, j);
            Elmt(*Q, j) = temp;
            i = j;
            j = (i == 0) ? MaxElQ(*Q) - 1 : i - 1;
        }
    }
}