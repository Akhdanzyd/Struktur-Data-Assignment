# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">Akhdan Ziyad</p>

## Dasar Teori

Array adalah kumpulan data dengan nama dan tipe yang sama, diakses menggunakan indeks, dan dapat berbentuk satu dimensi, dua dimensi, atau lebih. Pointer adalah variabel yang menyimpan alamat memori dari variabel lain dan memiliki hubungan erat dengan array karena keduanya dapat saling digunakan. Fungsi adalah blok kode untuk menjalankan tugas tertentu agar program lebih terstruktur dan efisien, sedangkan prosedur (fungsi void) tidak mengembalikan nilai. Parameter pada fungsi dapat dilewatkan dengan tiga cara: melalui nilai (call by value), pointer (call by pointer), dan referensi (call by reference).## Guided 

### 2. [pengenalan bahasa c++]

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main () {
    int a = 20, b = 30;
    int& ref = a;

    cout << "Nilai a : " << a << endl;
    cout << "Alamat a (&a) : " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "Alamat red (&ref): " << &ref << endl;


    //mengubah nilai a lewar refrence
    ref = 50;
    cout << "\nSetelah ref = 50: " << endl;
    cout << "Nilai a :" << a << endl;
    cout << "Nilai ref :" << ref << endl;

tukar(&a, &b);
cout << "After swapping, value of a : " << a << " and b=" << b << endl;

return 0;
}


#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

main () {
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value a : " << a << endl;
    cout << "Address a : " << &a << endl;
    cout << "Value stored in otr (address of a) : " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;


tukar(&a, &b);
cout << "After swapping, value of a : " << a << " and b=" << b << endl;

return 0;
}

#include <iostream>
using namespace std;

void tulis (int x) {
    for (int i = 0; i < x; i++) {
        cout << "Baris ke -: " << i+1 << endl;
    }
}


int main() {
    int jum;
    cout << "Jumlah baris kata: ";
    cin >> jum;
    tulis(jum);
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    // --- Array 1 Dimensi ---
    int arr[5] = {10, 20, 30, 40, 50};
    cout << "Array 1 Dimensi:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Element ke-" << i << ": " << arr[i] << endl;
    }
    cout << endl;

    // --- Array 2 Dimensi ---
    int arr2D[2][3] = {
        {1, 2, 3},
        {4, 5, 6},
    };
    cout << "Array 2 Dimensi:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "arr2D[" << i << "][" << j << "]: " << arr2D[i][j]
            << " ";
        }
        cout << endl;
    }
    // --- Array Multi Dimensi (3D) ---
    int arr3D[2][2][3] = {
        { {1, 2, 3}, {4, 5, 6} },
        { {7, 8, 9}, {10, 11, 12} },
    };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                cout << "arr3D[" << i << "][" << j << "]["
                << k << "]: " << arr3D[i][j][k] << endl;
            }
        }
    }

    return 0;
}
```
## Unguided 

### 1. [Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 .]

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

### 2. [ Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel]

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
<img width="265" height="74" alt="Image" src="https://github.com/user-attachments/assets/f78686c5-1fba-42bb-b4e9-b3f12ce124e0" />

Kode di atas digunakan untuk menerima satu input angka dari pengguna, lalu mencetak pola cermin angka (mirror pattern) yang menurun dari baris atas ke bawah menggunakan perulangan for dan fungsi cout untuk menampilkan hasil ke layar.
#### Full code Screenshot:
<img width="307" height="404" alt="Image" src="https://github.com/user-attachments/assets/cec748a4-94ca-48b3-87ce-e272a9489e7d" />


## Kesimpulan
Ketiga program tersebut melatih penggunaan operator aritmatika, percabangan if-else, dan perulangan bersarang dalam C++ untuk menghitung operasi matematika, mengubah angka menjadi tulisan, serta mencetak pola segitiga cermin angka secara interaktif di layar.

## Referensi
Petani Kode. (n.d.). Tutorial C++ Dasar: Operator, Percabangan, dan Perulangan.

