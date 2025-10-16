# <h1 align="center">ABSTRACT DATA TYPE (ADT)  </h1>
<p align="center">Akhdan Ziyad</p>

## Dasar Teori

ADT (Abstract Data Type) adalah sebuah tipe data beserta sekumpulan operasi dasar (primitif) yang dapat dilakukan terhadap tipe tersebut. Dalam ADT yang lengkap, juga terdapat definisi invarian tipe dan aksioma yang berlaku, sehingga ADT bersifat statis. Sebuah ADT dapat berisi definisi ADT lain, seperti ADT waktu yang terdiri dari ADT jam dan tanggal, atau ADT garis yang tersusun dari dua ADT titik (POINT), serta ADT segi empat yang terdiri dari dua pasangan titik (Top, Left) dan (Bottom, Right). Dalam bahasa pemrograman seperti C, tipe ADT diterjemahkan menjadi struct, sedangkan operasi primitifnya diimplementasikan sebagai fungsi atau prosedur. Operasi primitif ini meliputi konstruktor atau kreator (pembentuk nilai tipe, biasanya diawali “Make”), selector (mengakses komponen, diawali “Get”), prosedur pengubah nilai komponen, validator komponen, destruktor atau dealokator (menghapus nilai dan memori), operasi baca/tulis untuk I/O, operator relasional, operasi aritmatika khusus, serta konversi antar tipe. Implementasi ADT biasanya dibagi menjadi dua modul utama dan satu modul driver, yaitu: (1) definisi atau spesifikasi tipe dan primitif dalam file header (.h) yang berisi deklarasi tipe dan fungsi sesuai kaidah bahasa pemrograman, serta (2) realisasi atau implementasi primitif dalam file program (.c atau .cpp) yang berisi kode fungsi dan prosedur dengan memanfaatkan konstruktor dan selector.
## Guided 

### 1. [ADT c++]

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

### 1. [Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.]

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

### 2. [ Soal ke 2]

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
<img width="347" height="312" alt="Image" src="https://github.com/user-attachments/assets/54b1990a-936c-4524-ab5c-4298141fbf69" />

### 3. [Diketahui sebuah array 1 dimensi sebagai berikut :  
arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} 
Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari 
array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan 
function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur 
hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan 
menu switch-case seperti berikut ini : 
--- Menu Program Array --- 
1. Tampilkan isi array 
2. cari nilai maksimum 
3. cari nilai minimum 
4. Hitung nilai rata - rata]

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan angka: ";
    cin >> n;

    for (int i = n; i >= 1; i--) {
        for (int s = n; s > i; s--) {
            cout << "  "; 
        }
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "* ";
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    for (int s = 0; s < n; s++) {
        cout << "  "; 
    }
    cout << "*\n";

    return 0;
}

```
#### Output:
<img width="181" height="425" alt="Image" src="https://github.com/user-attachments/assets/2a191f12-89c7-446b-82d9-266fc2081c90" />

Program array satu dimensi digunakan untuk menampilkan isi array serta mencari nilai maksimum, minimum, dan rata-rata menggunakan fungsi dan prosedur dengan menu pilihan.

#### Full code Screenshot:
<img width="299" height="483" alt="Image" src="https://github.com/user-attachments/assets/48f2969d-3c9a-4ef6-baa4-b43f12fa387a" />

## Kesimpulan
Ketiga program tersebut menunjukkan penerapan konsep dasar C++ yaitu penggunaan array, pointer, reference, fungsi, dan prosedur untuk mempermudah pengolahan data seperti operasi matriks, pertukaran nilai variabel, serta pencarian nilai maksimum, minimum, dan rata-rata secara efisien dan terstruktur.

## Referensi
Petani Kode. (2024, April 14). Belajar C++ #14: Memahami Pointer di C++.
Petani Kode. (2019, Mei 18). Belajar Pemrograman C #11: Mengenal Fungsi pada C.
















