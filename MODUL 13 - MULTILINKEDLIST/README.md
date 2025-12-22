# <h1 align="center">  MULTILINKEDLIST  </h1>
<p align="center">Akhdan Ziyad</p>

## Dasar Teori
Secara harfiah, rekursif berarti suatu proses pengulangan sesuatu dengan cara kesamaan-diri atau suatu proses yang memanggil dirinya sendiri. Prosedur dan fungsi merupakan sub program yang sangat bermanfaat dalam pemrograman, terutama untuk program atau proyek yang besar.
## Guided 

### 1. [MLL]
```C++
/* buat dahulu elemen yang akan disisipkan */ 
address_anak alokasiAnak(infotypeanak X){
    address_anak P = alokasi(X); 
    P→next = Nil; 
    P→prev = Nil; 
    return P; 
} 
/* mencari apakah ada elemen pegawai dengan info X */ 
address findElm(listinduk L, infotypeinduk X){ 
    address cariInduk = L.first; 
    do{ 
        if(cariInduk.info == X){ 
            return cariInduk; 
        }else{ 
            cariInduk = cariInduk→next; 
}  
    }while(cariInduk.info != X || cariInduk != L→last) 
} 
/* menyisipkan anak pada akhir list anak */ 
void insertLastAnak(listanak &Lanak, address_anak P){ 
    address_anak ! = head(&Lanak); 
    do{ 
        Q = Q→next; 
    }while(next(&Lanak)!=Nil) 
    Q→next = P; 
    P→prev = Q; 
    P→next = Nil; 
}
```
multilist.h
```
/* contoh ADT list berkait dengan representasi fisik pointer*/ 
/* representasi address dengan pointer*/ 
 
/* info tipe adalah integer */ 
#ifndef MULTILIST_H_INCLUDED 
#define MULTILIST_H_INCLUDED 
#define Nil NULL 
 
typedef int infotypeanak; 
typedef int infotypeinduk; 
typedef struct elemen_list_induk *address; 
typedef struct elemen_list_anak *address_anak; 
/* define list : */ 
 
/* list kosong jika L.first=Nil 
setiap elemen address P dapat diacu P→info atau P→next 
elemen terakhir list jika addressnya last, maka L.last = Nil */ 
struct elemen_list_anak{ 
/* struct ini untuk menyimpan elemen anak dan pointer penunjuk 
   elemen tetangganya */ 
     infotypeanak info; 
     address_anak next; 
     address_anak prev; 
}; 
 
struct listanak { 
/* struct ini digunakan untuk menyimpan list anak itu sendiri */ 
   address_anak first; 
   address_anak last; 
}; 
 
struct elemen_list_induk{ 
/* struct ini untuk menyimpan elemen induk dan pointer penunjuk 
   elemen tetangganya */
      infotypeanak info; 
      listanak lanak;
      address next; 
      address prev; 
}; 
struct listinduk { 
/* struct ini digunakan untuk menyimpan list induk itu sendiri */ 
  address first;
  address last;
}; 
 
/********* pengecekan apakah list kosong ***********/ 
boolean ListEmpty(listinduk L); 
/*mengembalikan nilai true jika list induk kosong*/ 
boolean ListEmptyAnak(listanak L); 
/*mengembalikan nilai true jika list anak kosong*/ 
 
/********* pembuatan list kosong *********/ 
void CreateList(listinduk &L); 
/* I.S. sembarang 
   F.S. terbentuk list induk kosong*/ 
void CreateListAnak(listanak &L); 
/* I.S. sembarang 
   F.S. terbentuk list anak kosong*/ 
    
/********* manajemen memori *********/ 
address alokasi(infotypeinduk P); 
/* mengirimkan address dari alokasi sebuah elemen induk 
   jika alokasi berhasil, maka nilai address tidak Nil dan jika gagal 
   nilai address Nil */ 
    
address_anak alokasiAnak(infotypeanak P); 
/* mengirimkan address dari alokasi sebuah elemen anak 
   jika alokasi berhasil, maka nilai address tidak Nil dan jika gagal 
   nilai address_anak Nil */ 
    
void dealokasi(address P); 
/* I.S. P terdefinisi 
   F.S. memori yang digunakan P dikembalikan ke sistem */ 
 
void dealokasiAnak(address_anak P); 
/* I.S. P terdefinisi 
   F.S. memori yang digunakan P dikembalikan ke sistem */    
/********* pencarian sebuah elemen list *********/ 
address findElm(listinduk L, infotypeinduk X); 
/* mencari apakah ada elemen list dengan P→info = X 
   jika ada, mengembalikan address elemen tab tsb, dan Nil jika sebaliknya 
*/ 
address_anak findElm(listanak Lanak, infotypeanak X); 
/* mencari apakah ada elemen list dengan P→info = X 
   jika ada, mengembalikan address elemen tab tsb, dan Nil jika sebaliknya 
*/ 
boolean fFindElm(listinduk L, address P); 
/* mencari apakah ada elemen list dengan alamat P 
   mengembalikan true jika ada dan false jika tidak ada */ 
boolean fFindElmanak(listanak Lanak, address_anak P); 
/* mencari apakah ada elemen list dengan alamat P 
   mengembalikan true jika ada dan false jika tidak ada */ 
 
address findBefore(listinduk L, address P); 
/* mengembalikan address elemen sebelum P 
   jika P berada pada awal list, maka mengembalikan nilai Nil */ 
address_anak findBeforeAnak(listanak Lanak, infotypeinduk X, address_anak 
P); 
/* mengembalikan address elemen sebelum P dimana P→info = X 
   jika P berada pada awal list, maka mengembalikan nilai Nil */ 
    
/********* penambahan elemen **********/ 
void insertFirst(listinduk &L, address P); 
/* I.S. sembarang, P sudah dialokasikan 
   F.S. menempatkan elemen beralamat P pada awal list */ 
    
void insertAfter(listinduk &L, address P, address Prec); 
/* I.S. sembarang, P dan Prec alamt salah satu elemen list 
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */
void insertLast(listinduk &L, address P); 
/* I.S. sembarang, P sudah dialokasikan 
   F.S. menempatkan elemen beralamat P pada akhir list */ 
    
void insertFirstAnak(listanak &L, address_anak P); 
/* I.S. sembarang, P sudah dialokasikan 
   F.S. menempatkan elemen beralamat P pada awal list */ 
    
void insertAfterAnak(listanak &L, address_anak P, address_anak Prec); 
/* I.S. sembarang, P dan Prec alamt salah satu elemen list 
   F.S. menempatkan elemen beralamat P sesudah elemen beralamat Prec */ 
 
void insertLastAnak(listanak &L, address_anak P); 
/* I.S. sembarang, P sudah dialokasikan 
   F.S. menempatkan elemen beralamat P pada akhir list */ 
    
/********* penghapusan sebuah elemen *********/ 
void delFirst(listinduk &L, address &P); 
/* I.S. list tidak kosong 
   F.S. adalah alamat dari alamat elemen pertama list 
   sebelum elemen pertama list dihapus 
   elemen pertama list hilang dan list mungkin menjadi kosong 
   first elemen yang baru adalah successor first elemen yang lama */ 
void delLast(listinduk &L, address &P); 
/* I.S. list tidak kosong 
   F.S. adalah alamat dari alamat elemen terakhir list 
   sebelum elemen terakhir list dihapus 
   elemen terakhir list hilang dan list mungkin menjadi kosong 
   last elemen yang baru adalah successor last elemen yang lama */ 
 
void delAfter(listinduk &L, address &P, address Prec); 
/* I.S. list tidak kosng, Prec alamat salah satu elemen list 
   F.S. P adalah alamatdari Prec→next, menghapus Prec→next dari list */ 
void delP (listinduk &L, infotypeinduk X); 
/* I.S. sembarang 
   F.S. jika ada elemen list dengan alamat P, dimana P→info = X,  
        maka P dihapus dan P di-dealokasi,  
        jika tidak ada maka list tetap list mungkin akan menjadi kosong  
        karena penghapusan */ 
   
void delFirstAnak(listanak &L, address_anak &P); 
/* I.S. list tidak kosong 
   F.S. adalah alamat dari alamat elemen pertama list 
   sebelum elemen pertama list dihapus 
   elemen pertama list hilang dan list mungkin menjadi kosong 
   first elemen yang baru adalah successor first elemen yang lama */ 
void delLastAnak(listanak &L, address_anak &P); 
/* I.S. list tidak kosong 
   F.S. adalah alamat dari alamat elemen terakhir list 
   sebelum elemen terakhir list dihapus 
   elemen terakhir list hilang dan list mungkin menjadi kosong 
   last elemen yang baru adalah successor last elemen yang lama */ 
 
void delAfterAnak(listanak &L, address_anak &P, address_anak Prec); 
/* I.S. list tidak kosng, Prec alamat salah satu elemen list 
   F.S. P adalah alamatdari Prec→next, menghapus Prec→next dari list */ 
void delPAnak (listanak &L, infotypeanak X); 
/* I.S. sembarang 
   F.S. jika ada elemen list dengan alamat P, dimana P→info = X,  
        maka P dihapus dan P di-dealokasi,  
        jika tidak ada maka list tetap list mungkin akan menjadi kosong  
        karena penghapusan */ 
/********** proses semau elemen list *********/ 
void printInfo(list L); 
/* I.S. list mungkin kosong 
   F.S. jika list tidak kosong menampilkan semua info yang ada pada list 
*/ 

int nbList(list L); 
/* mengembalikan jumlah elemen pada list */ 
 
void printInfoAnak(listanak Lanak); 
/* I.S. list mungkin kosong 
   F.S. jika list tidak kosong menampilkan semua info yang ada pada list 
*/ 
 
int nbListAnak(listanak Lanak); 
/* mengembalikan jumlah elemen pada list anak */ 
 
/********** proses terhadap list **********/ 
void delAll(listinduk &L); 
/* menghapus semua elemen list dan semua elemen di-dealokasi */ 
#endif
```
## Unguided 


circularlist.h
```C++
#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <iostream>
using namespace std;

/* ========== TYPE ========== */
struct mahasiswa {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
};

typedef mahasiswa infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertFirst(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void insertLast(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteLast(List &L, address &P);

address findElm(List L, infotype x);
void printInfo(List L);

address createData(string nama, string nim, char jk, float ipk);

#endif

```
circularlist.cpp
```
#include "circularlist.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertFirst(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
        P->next = P;
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        P->next = L.first;
        last->next = P;
        L.first = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        insertFirst(L, P);
    } else {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }
        last->next = P;
        P->next = L.first;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.first != NULL) {
        address last = L.first;
        while (last->next != L.first) {
            last = last->next;
        }

        if (L.first->next == L.first) {
            P = L.first;
            L.first = NULL;
        } else {
            P = L.first;
            L.first = L.first->next;
            last->next = L.first;
        }
        P->next = NULL;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != NULL && Prec->next != L.first) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = NULL;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first != NULL) {
        address prev = NULL;
        address last = L.first;

        while (last->next != L.first) {
            prev = last;
            last = last->next;
        }

        if (prev == NULL) {
            P = L.first;
            L.first = NULL;
        } else {
            prev->next = L.first;
            P = last;
        }
        P->next = NULL;
    }
}

address findElm(List L, infotype x) {
    address P = L.first;
    if (P == NULL) return NULL;

    do {
        if (P->info.nim == x.nim) {
            return P;
        }
        P = P->next;
    } while (P != L.first);

    return NULL;
}

void printInfo(List L) {
    address P = L.first;
    if (P != NULL) {
        do {
            cout << "Nama : " << P->info.nama << endl;
            cout << "NIM  : " << P->info.nim << endl;
            cout << "JK   : " << P->info.jenis_kelamin << endl;
            cout << "IPK  : " << P->info.ipk << endl;
            cout << "------------------" << endl;
            P = P->next;
        } while (P != L.first);
    }
}

address createData(string nama, string nim, char jk, float ipk) {
    infotype x;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jk;
    x.ipk = ipk;
    return alokasi(x);
}

```
main.cpp
```
#include "circularlist.h"

int main() {
    List L;
    address P1, P2;
    infotype x;

    createList(L);

    cout << "coba insert first, last, dan after" << endl;

    P1 = createData("Danu", "04", 'l', 4.0);
    insertFirst(L, P1);

    P1 = createData("Fahmi", "06", 'l', 3.45);
    insertLast(L, P1);

    P1 = createData("Bobi", "02", 'l', 3.71);
    insertFirst(L, P1);

    P1 = createData("Ali", "01", 'l', 3.3);
    insertFirst(L, P1);

    P1 = createData("Gita", "07", 'p', 3.75);
    insertLast(L, P1);

    x.nim = "07";
    P1 = findElm(L, x);
    P2 = createData("Cindi", "03", 'p', 3.5);
    insertAfter(L, P1, P2);

    x.nim = "02";
    P1 = findElm(L, x);
    P2 = createData("Hilmi", "08", 'p', 3.3);
    insertAfter(L, P1, P2);

    x.nim = "04";
    P1 = findElm(L, x);
    P2 = createData("Eli", "05", 'p', 3.4);
    insertAfter(L, P1, P2);

    printInfo(L);

    return 0;
}


```

#### Output:
<img width="308" height="368" alt="image" src="https://github.com/user-attachments/assets/a6ef4d59-e159-4e13-9417-8f77c4c44985" />






Soal ini menekankan pemahaman ADT Circular Doubly Linked List dalam pengelolaan data mahasiswa secara dinamis. Implementasi operasi insert, delete, dan pencarian menunjukkan keterkaitan antar node secara melingkar melalui pointer next, sehingga struktur list tetap konsisten, efisien, dan mudah ditelusuri tanpa elemen NULL.
#### Full code Screenshot:

<img width="308" height="445" alt="image" src="https://github.com/user-attachments/assets/fae9702c-41e1-4459-996f-488ad3e18a45" />
<img width="385" height="477" alt="image" src="https://github.com/user-attachments/assets/80243b78-079c-4b40-a33c-9dfb28ba5bf7" />
<img width="284" height="466" alt="image" src="https://github.com/user-attachments/assets/b7569d35-b259-47c9-a206-b233569e7c22" />
<img width="327" height="394" alt="image" src="https://github.com/user-attachments/assets/0e3b7b33-d1d5-4141-8219-1c28d756cb86" />
<img width="305" height="452" alt="image" src="https://github.com/user-attachments/assets/717fee01-7a3e-4d80-a3fe-2171af8a6cf2" />


## Kesimpulan
Praktikum ini bertujuan untuk memahami mekanisme kerja Multi Linked List serta proses pengelolaan data di dalamnya, khususnya pada operasi penambahan data di bagian awal, akhir, dan setelah node tertentu, serta menampilkan kembali data secara terstruktur dan berurutan.
## Referensi
Petani Kode. (n.d.). Struktur Data Linked List.





