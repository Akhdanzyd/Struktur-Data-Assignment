#include <iostream>
#include "QueuePengiriman.h"
using namespace std;

bool isEmpty(QueueEkspedisi &Q) {
    return (Q.Head == -1 && Q.Tail == -1);
}

bool isFull(QueueEkspedisi &Q) {
    return (Q.Tail == MAX - 1);
}

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enQueue(QueueEkspedisi &Q) {
    if (isFull(Q)) {
        cout << "Queue penuh! Tidak bisa menambah data.\n";
        return;
    }

    Paket P;
    cout << "Masukkan Kode Resi      : ";
    cin >> P.KodeResi;
    cout << "Masukkan Nama Pengirim  : ";
    cin >> P.NamaPengirim;
    cout << "Masukkan Berat Barang   : ";
    cin >> P.BeratBarang;
    cout << "Masukkan Tujuan         : ";
    cin >> P.Tujuan;

    if (isEmpty(Q)) {
        Q.Head = Q.Tail = 0;
    } else {
        Q.Tail++;
    }

    Q.dataPaket[Q.Tail] = P;
    cout << "Data berhasil masuk queue.\n";
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong, tidak bisa menghapus.\n";
        return;
    }

    cout << "Menghapus paket dengan resi: "
         << Q.dataPaket[Q.Head].KodeResi << endl;

    for (int i = Q.Head; i < Q.Tail; i++) {
        Q.dataPaket[i] = Q.dataPaket[i+1];
    }

    Q.Tail--;

    if (Q.Tail < Q.Head) {
        Q.Head = Q.Tail = -1;
    }
}

void viewQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong.\n";
        return;
    }

    cout << "\n=== DAFTAR PAKET DALAM QUEUE ===\n";
    for (int i = Q.Head; i <= Q.Tail; i++) {
        cout << "Posisi " << i << endl;
        cout << " Resi   : " << Q.dataPaket[i].KodeResi << endl;
        cout << " Nama   : " << Q.dataPaket[i].NamaPengirim << endl;
        cout << " Berat  : " << Q.dataPaket[i].BeratBarang << " kg" << endl;
        cout << " Tujuan : " << Q.dataPaket[i].Tujuan << endl;
        cout << "----------------------------------\n";
    }
}

int TotalBiayaPengiriman(QueueEkspedisi &Q) {
    if (isEmpty(Q)) return 0;

    int total = 0;
    for (int i = Q.Head; i <= Q.Tail; i++) {
        total += Q.dataPaket[i].BeratBarang * 8250;
    }
    return total;
}
