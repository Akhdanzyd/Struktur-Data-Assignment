# <h1 align="center">SINGLY LINKED LIST  </h1>
<p align="center">Akhdan Ziyad</p>

## Dasar Teori

Singly Linked List adalah struktur data dinamis yang terdiri dari sejumlah node saling terhubung satu arah melalui pointer. Setiap node memiliki dua bagian, yaitu data dan pointer yang menunjuk ke node berikutnya. Struktur ini fleksibel karena dapat bertambah atau berkurang sesuai kebutuhan tanpa alokasi memori tetap seperti array. Operasi dasarnya meliputi pembuatan, penambahan, penghapusan, dan penelusuran node. Kelebihannya efisien dalam penyisipan dan penghapusan data, sedangkan kekurangannya memerlukan memori tambahan untuk pointer dan hanya dapat ditelusuri satu arah.
## Guided 

### 1. [SLL  ]

```C++
#include <iostream>
using namespace std;

struct mahasiswa{ 
char nim[10]; 
int nilai1,nilai2;
};
void inputMhs(mahasiswa &m); 
float rata2(mahasiswa m);

int main() 
{ 
mahasiswa mhs; 
inputMhs(mhs); 
cout << “rata-rata = “ << rata2(mhs); 
return 0; 
}


void inputMhs(mahasiswa &m){ 
cout << “input nama = “; 
cin >> m.nim; 
cout << “input nilai = “; 
cin >> m.nilai1; 
cout << “input nilai2 = “;
cin >> m.nilai2; 
} 
float rata2(mahasiswa m){ 
return float(m.nilai1+m.nilai2)/2; 
}

mahasiswa.h
#ifndef MAHASISWA_H_INCLUDED 
#define MAHASISWA_H_INCLUDED 
struct mahasiswa{ 
char nim[10]; 
int nilai1, nilai2; 
};
void inputMhs(mahasiswa &m); 
float rata2(mahasiswa m); 
#endif // MAHASISWA_H_INCLUDED

mahasiswa.cpp
#include “mahasiswa.h” 
void inputMhs(mahasiswa &m){ 
cout << “input nama = “; 
cin >> (m).nim; 
cout << “input nilai = “; 
cin >> (m).nilai1; 
cout << “input nilai2 = “; 
cin >> (m).nilai2;
} 
 
float rata2(mahasiswa m){ 
  return float(m.nilai1+m.nilai2)/2; 
}

main.cpp
#include <iostream> 
#include “mahasiswa.h” 
 
using namespace std; 
 
int main() 
{ 
  mahasiswa mhs; 
  inputMhs(mhs); 
  cout << “rata-rata = “ << rata2(mhs); 
  return 0; 
} 
```
## Unguided 

### 1. [ Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h” kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”]

```C++
#include <iostream>
using namespace std;

struct mahasiswa {
    char nama[30];
    char nim[15];
    float uts, uas, tugas, nilaiAkhir;
};

void inputMhs(mahasiswa &m);
float hitungNilaiAkhir(mahasiswa m);

int main() {
    mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Jumlah mahasiswa tidak boleh lebih dari 10!" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        inputMhs(mhs[i]);
        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i]);
    }

    cout << "\n=== Data Mahasiswa ===\n";
    for (int i = 0; i < n; i++) {
        cout << "\nNama        : " << mhs[i].nama;
        cout << "\nNIM         : " << mhs[i].nim;
        cout << "\nUTS         : " << mhs[i].uts;
        cout << "\nUAS         : " << mhs[i].uas;
        cout << "\nTugas       : " << mhs[i].tugas;
        cout << "\nNilai Akhir : " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}

void inputMhs(mahasiswa &m) {
    cout << "Input nama   : ";
    cin >> m.nama;
    cout << "Input NIM    : ";
    cin >> m.nim;
    cout << "Input nilai UTS   : ";
    cin >> m.uts;
    cout << "Input nilai UAS   : ";
    cin >> m.uas;
    cout << "Input nilai Tugas : ";
    cin >> m.tugas;
}

float hitungNilaiAkhir(mahasiswa m) {
    return 0.3 * m.uts + 0.4 * m.uas + 0.3 * m.tugas;
}


```
#### Output:
<img width="200" height="188" alt="Image" src="https://github.com/user-attachments/assets/148a3901-4aa5-4881-82ba-30996c7e6882" />

Program ini menyimpan data maksimal 10 mahasiswa dan menghitung nilai akhir tiap mahasiswa menggunakan fungsi dengan rumus 0.3UTS + 0.4UAS + 0.3*Tugas.

#### Full code Screenshot:
<img width="281" height="490" alt="Image" src="https://github.com/user-attachments/assets/f9cfdcc7-e376-492c-bc40-7dea6d1ab59b" />

### 2. [Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList(). Output yang diharapkan : ]

```C++
main.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}

pelajaran.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "Nama Mata Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode Mata Pelajaran : " << pel.kodeMapel << endl;
}

pelajaran.h
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif



```
#### Output:
<img width="198" height="46" alt="Image" src="https://github.com/user-attachments/assets/bf177d84-9e31-432f-9f30-4fbd64ee553e" />

Program di atas membuat ADT (Abstract Data Type) pelajaran yang menyimpan data mata pelajaran berupa namaMapel dan kodeMapel, lalu menampilkan isinya menggunakan dua fungsi: create_pelajaran(), tampil_pelajaran()

#### Full code Screenshot:
<img width="332" height="188" alt="Image" src="https://github.com/user-attachments/assets/679bfc31-5f9d-46ec-bab6-043f00487d4b" />

<img width="377" height="217" alt="Image" src="https://github.com/user-attachments/assets/75d0f91a-bb90-406b-8526-49e205fc65e0" />

<img width="351" height="210" alt="Image" src="https://github.com/user-attachments/assets/8efa3213-18e1-46c8-b7a6-bb4c7fa100e8" />


## Kesimpulan
pada modul ini mengajarkan penerapan konsep Abstract Data Type (ADT) dalam C++, yaitu bagaimana memisahkan definisi tipe data dan operasinya (fungsi/prosedur) dari program utama, serta penerapan manipulasi data terstruktur (array, struct, dan pointer) untuk membangun program yang lebih modular, terorganisir, dan mudah dipelihara.

## Referensi
Petani Kode. (2017, September 15). Belajar C++ #09: Menggunakan Array di C++.
Petani Kode. (2017, September 30). Belajar C++ #14: Memahami Pointer di C++.





















