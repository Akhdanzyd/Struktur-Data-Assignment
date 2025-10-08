# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (1)</h1>
<p align="center">Akhdan Ziyad</p>

## Dasar Teori

Pertama ada identifier yang biasanya digunakan untuk variabel, konstanta, fungsi atau objek lain yang didefinisikan oleh program. Lalu ada input/output juga diperkenalkan berbagai macam operator. untuk menyelesaikan masalah menggunakan kondisonal seperti if, if-else, switch. dan 2 terakhir ada perulangan dan juga struktur 
## Guided 

### 1. [Nama Topik]

```C++
#include <iostream>
using namespace std;

int main () {
    int a;
    int b;

    cout << "masukan angka: ";
    cin >> a;
    cout << "masukan angka: ";
    cin >> b;

    //operator aritmatika
    cout << "a + b = " << (a+b) << endl;
    cout << "a - b = " << (a-b) << endl;
    cout << "a * b = " << (a*b) << endl;
    cout << "a / b = " << (a/b) << endl;
    cout << "a % b = " << (a%b) << endl;

    //operator logika
    cout << "a < b = " << (a<b) << endl;
    cout << "a > b = " << (a>b) << endl;
    cout << "a <= b = " << (a<=b) << endl;
    cout << "a >= b = " << (a>=b) << endl;
    cout << "a == b = " << (a==b) << endl;
    cout << "a != b = " << (a!=b) << endl;
}#include <iostream>
using namespace std;

int main () {
    int a;
    int b;

    cout << "masukan angka: ";
    cin >> a;
    cout << "masukan angka: ";
    cin >> b;

    //operator aritmatika
    cout << "a + b = " << (a+b) << endl;
    cout << "a - b = " << (a-b) << endl;
    cout << "a * b = " << (a*b) << endl;
    cout << "a / b = " << (a/b) << endl;
    cout << "a % b = " << (a%b) << endl;

    //operator logika
    cout << "a < b = " << (a<b) << endl;
    cout << "a > b = " << (a>b) << endl;
    cout << "a <= b = " << (a<=b) << endl;
    cout << "a >= b = " << (a>=b) << endl;
    cout << "a == b = " << (a==b) << endl;
    cout << "a != b = " << (a!=b) << endl;
}

Kode di atas digunakan untuk menerima dua input bilangan bulat dari pengguna, lalu menampilkan hasil operasi
aritmatika (penjumlahan, pengurangan, perkalian, pembagian, dan sisa bagi) serta hasil perbandingan logika
(lebih kecil, lebih besar, sama dengan, dan tidak sama dengan) antara kedua bilangan tersebut menggunakan
fungsi cout untuk mencetak hasil ke layar.
```
## Unguided 

### 1. [Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian
memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua
bilangan tersebut.
 ]

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << " bilangan pertama: ";
    cin >> a;
    cout << " bilangan kedua: ";
    cin >> b;

    cout << "Penjumlahan = " << a + b << endl;
    cout << "Pengurangan = " << a - b << endl;
    cout << "Perkalian   = " << a * b << endl;

    if (b != 0)
        cout << "Pembagian   = " << a / b << endl;
    else
    return 0;
}

}
```
#### Output:
<img width="520" height="422" alt="Image" src="https://github.com/user-attachments/assets/c22df480-5dcd-400b-9b4f-29cba8dc821e" />

Kode di atas digunakan untuk menerima dua input bilangan bertipe float dari pengguna, kemudian menampilkan hasil operasi penjumlahan, pengurangan, perkalian, dan pembagian menggunakan fungsi cout untuk mencetak hasil ke layar.

#### Full code Screenshot:
<img width="520" height="422" alt="Image" src="https://github.com/user-attachments/assets/c22df480-5dcd-400b-9b4f-29cba8dc821e" />

### 2. [Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai
angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat
positif mulai dari 0 s.d 100]

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;

    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", 
                       "enam", "tujuh", "delapan", "sembilan"};
    string hasil;

    if (n == 0)
        hasil = "nol";
    else if (n == 10)
        hasil = "sepuluh";
    else if (n == 11)
        hasil = "sebelas";
    else if (n < 20)
        hasil = satuan[n - 10] + " belas";
    else if (n < 100) {
        int puluh = n / 10;
        int sisa = n % 10;
        hasil = satuan[puluh] + " puluh";
        if (sisa != 0)
            hasil += " " + satuan[sisa];
    } else if (n == 100)
        hasil = "seratus";
    else
        hasil = "Angka di luar jangkauan!";

    cout << n << " : " << hasil << endl;
    return 0;
}

```
#### Output:
<img width="187" height="35" alt="Image" src="https://github.com/user-attachments/assets/06ea09a6-6ab7-4b8d-abe9-02dd59c89d16" />

Kode di atas digunakan untuk menerima sebuah angka antara 0 sampai 100 dari pengguna, kemudian menampilkan angka tersebut dalam bentuk tulisan (kata) dalam bahasa Indonesia menggunakan fungsi cout untuk mencetak hasil ke layar.

#### Full code Screenshot:
<img width="593" height="420" alt="Image" src="https://github.com/user-attachments/assets/3701c2ef-5dc6-456c-ac98-4bf2d9f4168b" />

### 3. [mwmbuat segitiga terbalik]

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
<img width="187" height="35" alt="Image" src="https://github.com/user-attachments/assets/06ea09a6-6ab7-4b8d-abe9-02dd59c89d16" />

Kode di atas digunakan untuk menerima sebuah angka antara 0 sampai 100 dari pengguna, kemudian menampilkan angka tersebut dalam bentuk tulisan (kata) dalam bahasa Indonesia menggunakan fungsi cout untuk mencetak hasil ke layar.

#### Full code Screenshot:
<img width="593" height="420" alt="Image" src="https://github.com/user-attachments/assets/3701c2ef-5dc6-456c-ac98-4bf2d9f4168b" />


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
