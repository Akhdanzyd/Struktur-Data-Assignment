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
<img width="332" height="188" alt="Image" src="https://github.com/user-attachments/assets/679bfc31-5f9d-46ec-bab6-043f00487d4b" />

<img width="377" height="217" alt="Image" src="https://github.com/user-attachments/assets/75d0f91a-bb90-406b-8526-49e205fc65e0" />

<img width="351" height="210" alt="Image" src="https://github.com/user-attachments/assets/8efa3213-18e1-46c8-b7a6-bb4c7fa100e8" />

### 3. [3. Buatlah program dengan ketentuan : - 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer - fungsi/prosedur yang menampilkan isi sebuah array integer 2D - fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu - fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah 
pointer]

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArrayPosisi(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarArraySemua(int arr1[3][3], int arr2[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int temp = arr1[i][j];
            arr1[i][j] = arr2[i][j];
            arr2[i][j] = temp;
        }
    }
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    cout << "Array A sebelum ditukar:\n";
    tampilArray(A);
    cout << "\nArray B sebelum ditukar:\n";
    tampilArray(B);

    tukarArraySemua(A, B);

    cout << "\nSetelah menukar seluruh isi array:\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "\nArray B:\n";
    tampilArray(B);

    int x = 10, y = 20;
    int *ptr1 = &x;
    int *ptr2 = &y;

    cout << "\nSebelum tukar pointer: x = " << x << ", y = " << y << endl;
    tukarPointer(ptr1, ptr2);
    cout << "Setelah tukar pointer: x = " << x << ", y = " << y << endl;

    return 0;
}


```
#### Output:
<img width="212" height="268" alt="image" src="https://github.com/user-attachments/assets/0cb5e1b3-14f5-49f2-bc89-4e25fb663ac5" />


Program membuat dua array 2D berukuran 3×3 dan dua pointer integer, lalu memiliki fungsi untuk menampilkan isi array, menukar elemen antar array pada posisi tertentu, serta menukar nilai yang ditunjuk oleh dua pointer dengan menggunakan konsep fungsi, parameter, dan pointer dalam C++.

#### Full code Screenshot:
<img width="426" height="416" alt="Image" src="https://github.com/user-attachments/assets/90be9a62-a493-4d0b-8b36-32969d85f7a7" />

<img width="424" height="431" alt="Image" src="https://github.com/user-attachments/assets/d712f3c1-dae4-470a-8f72-860d2787f5fb" />

## Kesimpulan
pada modul ini mengajarkan penerapan konsep Abstract Data Type (ADT) dalam C++, yaitu bagaimana memisahkan definisi tipe data dan operasinya (fungsi/prosedur) dari program utama, serta penerapan manipulasi data terstruktur (array, struct, dan pointer) untuk membangun program yang lebih modular, terorganisir, dan mudah dipelihara.

## Referensi
Petani Kode. (2017, September 15). Belajar C++ #09: Menggunakan Array di C++.
Petani Kode. (2017, September 30). Belajar C++ #14: Memahami Pointer di C++.



















