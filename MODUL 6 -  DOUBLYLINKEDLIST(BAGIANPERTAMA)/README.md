# <h1 align="center">  DOUBLYLINKEDLIST(BAGIANPERTAMA)  </h1>
<p align="center">Akhdan Ziyad</p>

## Dasar Teori
DoublyLinkedlist adalah linked list yang masing–masing elemennya memiliki 2 successor, yaitu successor yang menunjuk pada elemen sebelumnya(prev) dan successor yang menunjuk pada elemen sesudahnya(next).
## Guided 

### 1. [DLL]

```C++
#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype; // Definisikan tipe data infotype sebagai integer untuk menyimpan informasi elemen
typedef struct elmlist *address; // Definisikan tipe address sebagai pointer ke struct elmlist

struct elmlist {
    infotype info; // Deklarasikan field info untuk menyimpan data elemen
    address next;
    address prev;
};

struct List { 
    address first; 
    address last; 
}; 

void insertFirst(List &L, address P) { 
    P->next = L.first; // Set pointer next dari P ke elemen pertama saat ini
    P->prev = Nil; // Set pointer prev dari P ke Nil karena menjadi elemen pertama
    if (L.first != Nil) L.first->prev = P; // Jika list tidak kosong, set prev elemen pertama lama ke P
    else L.last = P; // Jika list kosong, set last juga ke P
    L.first = P; // Update first list menjadi P
} 

void insertLast(List &L, address P) { 
    P->prev = L.last; // Set pointer prev dari P ke elemen terakhir saat ini
    P->next = Nil; // Set pointer next dari P ke Nil karena menjadi elemen terakhir
    if (L.last != Nil) L.last->next = P; // Jika list tidak kosong, set next elemen terakhir lama ke P
    else L.first = P; // Jika list kosong, set first juga ke P
    L.last = P; // Update last list menjadi P
} 

void insertAfter(List &L, address P, address R) { // Definisikan fungsi insertAfter untuk menyisipkan elemen setelah R
    P->next = R->next; // Set pointer next dari P ke elemen setelah R
    P->prev = R; // Set pointer prev dari P ke R
    if (R->next != Nil) R->next->prev = P; // Jika ada elemen setelah R, set prev elemen tersebut ke P
    else L.last = P; // Jika R adalah terakhir, update last menjadi P
    R->next = P; // Set next dari R ke P
}

address alokasi(infotype x) { // Definisikan fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P->info = x; // Set info elemen dengan nilai x
    P->next = Nil; // Set next elemen ke Nil
    P->prev = Nil; // Set prev elemen ke Nil
    return P; 
} 

void printInfo(List L) { // Definisikan fungsi printInfo untuk mencetak isi list
    address P = L.first; // Set P ke elemen pertama list
    while (P != Nil) { // Loop selama P tidak Nil
        cout << P->info << " "; // Cetak info dari P 
        P = P->next; // Pindah ke elemen berikutnya
    } 
    cout << endl; 
}

int main() { 
    List L; 
    L.first = Nil; 
    L.last = Nil;
    address P1 = alokasi(1); 
    insertFirst(L, P1); 
    address P2 = alokasi(2); 
    insertLast(L, P2); 
    address P3 = alokasi(3); 
    insertAfter(L, P3, P1); 
    printInfo(L); 
    return 0; 
}

```
## Unguided 

### 1.BuatlahADTDoublyLinkedlistsebagaiberikutdidalamfile“Doublylist.h”


Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>
using namespace std;

typedef struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
} infotype;

typedef struct ElmList *address;

typedef struct ElmList {
    infotype info;
    address next;
    address prev;
} ElmList;

typedef struct {
    address First;
    address Last;
} List;

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertLast(List &L, address P);
void printInfo(List L);

address findElm(List L, infotype x);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif




```
Doublylist.cpp

```c++
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = NULL;
    L.Last  = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last  = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    cout << "\nDATA LIST\n";
    while (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl << endl;
        P = P->next;
    }
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void deleteFirst(List &L, address &P) {
    P = L.First;
    if (P != NULL) {
        if (L.First == L.Last) {
            L.First = NULL;
            L.Last  = NULL;
        } else {
            L.First = P->next;
            L.First->prev = NULL;
            P->next = NULL;
        }
    }
}

void deleteLast(List &L, address &P) {
    P = L.Last;
    if (P != NULL) {
        if (L.First == L.Last) {
            L.First = NULL;
            L.Last  = NULL;
        } else {
            L.Last = P->prev;
            L.Last->next = NULL;
            P->prev = NULL;
        }
    }
}

void deleteAfter(address Prec, address &P) {
    P = Prec->next;
    if (P != NULL) {
        Prec->next = P->next;
        if (P->next != NULL) {
            P->next->prev = Prec;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}


```
main.cpp
```c++
#include "Doublylist.h"

int main() {
    List L;
    infotype x, cari;
    address P, Prec;
    int n;

    CreateList(L);

    cout << "Masukkan jumlah kendaraan: ";
    cin >> n;
    cin.ignore();

    // ===== INPUT DATA (SOAL 1 + CEK DUPLIKAT) =====
    for (int i = 1; i <= n; i++) {
        cout << "\nData kendaraan ke-" << i << endl;

        cout << "Nomor Polisi : ";
        getline(cin, x.nopol);

        // 🔴 CEK NOMOR POLISI DUPLIKAT
        if (findElm(L, x) != NULL) {
            cout << "Nomor polisi sudah terdaftar!\n";
            i--;        // ulangi input
            continue;
        }

        cout << "Warna        : ";
        getline(cin, x.warna);

        cout << "Tahun        : ";
        cin >> x.thnBuat;
        cin.ignore();

        insertLast(L, alokasi(x));
    }

    printInfo(L);

    // ===== SOAL 2: CARI DATA =====
    cout << "Masukkan nomor polisi yang dicari: ";
    getline(cin, cari.nopol);

    P = findElm(L, cari);
    if (P != NULL) {
        cout << "\nData ditemukan\n";
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "\nData tidak ditemukan\n";
    }

    // ===== SOAL 3: HAPUS DATA =====
    cout << "\nMasukkan nomor polisi yang akan dihapus: ";
    getline(cin, cari.nopol);

    P = findElm(L, cari);
    if (P != NULL) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            Prec = P->prev;
            deleteAfter(Prec, P);
        }
        dealokasi(P);
        cout << "Data berhasil dihapus\n";
    } else {
        cout << "Data tidak ditemukan\n";
    }

    printInfo(L);

    return 0;
}



```
#### Output:
<img width="301" height="283" alt="image" src="https://github.com/user-attachments/assets/b73f48a0-eb33-47c3-b35a-4ae5407ac0df" />
<img width="281" height="71" alt="image" src="https://github.com/user-attachments/assets/29bc8e21-7c9c-4e5d-802c-784822cc28c0" />
<img width="233" height="86" alt="image" src="https://github.com/user-attachments/assets/076e4844-64c3-411a-8ad2-780811e601fc" />




Pada soal di atas, menekankan pemahaman konsep ADT Doubly Linked List serta analisis struktur data yang digunakan untuk mengelola data kendaraan secara terurut dan dinamis. Penerapan operasi insert, pencarian data menggunakan fungsi findElm, serta penghapusan data dengan prosedur deleteFirst, deleteLast, dan deleteAfter menunjukkan bagaimana setiap proses saling berkaitan untuk menghasilkan solusi yang tepat, konsisten, dan efisien sesuai ketentuan yang diberikan, termasuk validasi agar tidak terjadi duplikasi nomor polisi.
#### Full code Screenshot:

<img width="286" height="403" alt="image" src="https://github.com/user-attachments/assets/2d3688c7-f2fd-4344-b6dc-b75b668de231" />

<img width="410" height="396" alt="image" src="https://github.com/user-attachments/assets/6435104f-0789-49ca-a5fd-d657df6c204c" />

<img width="256" height="340" alt="image" src="https://github.com/user-attachments/assets/99bcf3b3-1683-4e97-bb40-e487d72a5d4c" />

<img width="353" height="409" alt="image" src="https://github.com/user-attachments/assets/49ea4706-19f0-48ff-bc58-3f6dc7b70e26" />

<img width="292" height="196" alt="image" src="https://github.com/user-attachments/assets/e6cacd5f-576c-4fa1-961d-574d94a1e914" />

## Kesimpulan
Doubly Linked List menawarkan kemampuan yang lebih fleksibel dibandingkan Singly Linked List dalam menangani kebutuhan akses dua arah pada data, meskipun memerlukan penggunaan memori yang lebih besar akibat adanya pointer tambahan. Struktur data ini sangat efisien digunakan pada aplikasi yang membutuhkan operasi penambahan dan penghapusan elemen di berbagai posisi dalam list.
## Referensi
Petani Kode. (n.d.). Belajar Struktur Data: Doubly Linked List pada C++.























