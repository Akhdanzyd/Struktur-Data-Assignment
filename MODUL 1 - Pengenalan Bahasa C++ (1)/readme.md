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

## Unguided 

### 1. [Soal]

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
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk menerima dua input bilangan bertipe float dari pengguna, kemudian menampilkan hasil operasi penjumlahan, pengurangan, perkalian, dan pembagian menggunakan fungsi cout untuk mencetak hasil ke layar.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
