# <h1 align="center">Laporan Praktikum Modul Pengenalan Bahasa C++ (2)</h1>
<p align="center">Akhdan Ziyad</p>

## Dasar Teori

Array adalah kumpulan data dengan nama dan tipe yang sama, diakses menggunakan indeks, dan dapat berbentuk satu dimensi, dua dimensi, atau lebih. Pointer adalah variabel yang menyimpan alamat memori dari variabel lain dan memiliki hubungan erat dengan array karena keduanya dapat saling digunakan. Fungsi adalah blok kode untuk menjalankan tugas tertentu agar program lebih terstruktur dan efisien, sedangkan prosedur (fungsi void) tidak mengembalikan nilai. Parameter pada fungsi dapat dilewatkan dengan tiga cara: melalui nilai (call by value), pointer (call by pointer), dan referensi (call by reference).
## Guided 

### 1. [pengenalan bahasa c++]

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
    int A[3][3], B[3][3], C[3][3];

    cout << " matriks A (3x3):" << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> A[i][j];

    cout << "\n matriks B (3x3):" << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> B[i][j];

    
    cout << "\n Penjumlahan (A + B):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] + B[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\n Pengurangan (A - B):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] - B[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\n Perkalian (A × B):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++)
                C[i][j] += A[i][k] * B[k][j];
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

```
#### Output:
<img width="181" height="344" alt="Image" src="https://github.com/user-attachments/assets/19b1840c-0dad-4565-8ecd-4a1b88c4fcf0" />

Program operasi matriks 3x3 digunakan untuk menghitung hasil penjumlahan, pengurangan, dan perkalian antara dua matriks berordo 3x3.

#### Full code Screenshot:
<img width="190" height="377" alt="Image" src="https://github.com/user-attachments/assets/29add33e-bd71-4a35-8641-c0249666987a" />

### 2. [ Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel]

```C++
#include <iostream>
using namespace std;

void tukarDenganPointer(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}
void tukarDenganReference(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}
int main() {
    int a , b , c;
    cin >> a >> b >> c;
    cout << "Nilai awal:\n";
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    tukarDenganPointer(&a, &b, &c);
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    tukarDenganReference(a, b, c);
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}


```
#### Output:
<img width="179" height="67" alt="Image" src="https://github.com/user-attachments/assets/2e528223-ffc1-49d6-8f93-74e972b373a8" />

Program pertukaran nilai dengan pointer dan reference digunakan untuk menukar nilai dari tiga variabel menggunakan dua cara berbeda, yaitu melalui alamat memori (pointer) dan referensi variabel.

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









