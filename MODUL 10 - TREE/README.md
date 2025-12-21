# <h1 align="center">  TREE(BAGIANPERTAMA)  </h1>
<p align="center">Akhdan Ziyad</p>

## Dasar Teori
Secara harfiah, rekursif berarti suatu proses pengulangan sesuatu dengan cara kesamaan-diri atau suatu proses yang memanggil dirinya sendiri. Prosedur dan fungsi merupakan sub program yang sangat bermanfaat dalam pemrograman, terutama untuk program atau proyek yang besar.
## Guided 

### 1. [DLL]
bst.h
```C++
#ifndef BST_H
#define BST_H
#define Nil nullptr

using namespace std;

typedef struct BST *Node; //alis pointer = node

struct BST{ // nama structnya BST 
    int angka;
    node left;
    node right;
};

typedef node BinTree; //alias tree = BinTree (merujuk ke node root dari BST)

bool isEmpty(BinTree tree);
void createTree(Bintree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BimTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BInTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int hegight(BinTree tree);

#endif
}
```
bst.cpp
```
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```
main.cpp

```
#include "bst.h"
#include <iostream>

using namespace std;

//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
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


