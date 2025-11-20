#include <iostream>
#include <iomanip>
#include "StackMahasiswa.h"

using namespace std;


bool isEmpty(StackMahasiswa &S) {
    return S.Top == -1;
}

bool isFull(StackMahasiswa &S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.Top = -1;
}


void inputMahasiswa(Mahasiswa &M) {
    cout << "Masukkan Nama        : ";
    cin >> M.Nama;
    cout << "Masukkan NIM         : ";
    cin >> M.NIM;
    cout << "Masukkan Nilai Tugas : ";
    cin >> M.NilaiTugas;
    cout << "Masukkan Nilai UTS   : ";
    cin >> M.NilaiUTS;
    cout << "Masukkan Nilai UAS   : ";
    cin >> M.NilaiUAS;
}

float hitungNilaiAkhir(const Mahasiswa &M) {
    return 0.2f * M.NilaiTugas +
           0.4f * M.NilaiUTS +
           0.4f * M.NilaiUAS;
}


void Push(StackMahasiswa &S) {
    if (isFull(S)) {
        cout << "Stack penuh, tidak bisa push.\n";
        return;
    }
    S.Top++;

    cout << "\n--- Input Data Mahasiswa Untuk Push ---\n";
    inputMahasiswa(S.dataMahasiswa[S.Top]);
    cout << "Data berhasil di-push.\n";
}


void Pop(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong, tidak bisa pop.\n";
        return;
    }
    cout << "Data terhapus (POP): " << S.dataMahasiswa[S.Top].Nama << endl;
    S.Top--;
}


void Update(StackMahasiswa &S, int posisi) {
    if (isEmpty(S)) {
        cout << "Stack kosong.\n";
        return;
    }
    if (posisi < 1 || posisi > S.Top + 1) {
        cout << "Posisi tidak valid.\n";
        return;
    }

    int idx = posisi - 1;
    cout << "\n--- Update Data Mahasiswa Posisi " << posisi << " ---\n";
    inputMahasiswa(S.dataMahasiswa[idx]);

    cout << "Data berhasil di-update.\n";
}


void View(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong.\n";
        return;
    }

    cout << "\n=== Isi Stack (Top di bawah) ===\n";
    cout << left << setw(5) << "Pos"
         << setw(12) << "Nama"
         << setw(12) << "NIM"
         << setw(10) << "Tugas"
         << setw(10) << "UTS"
         << setw(10) << "UAS"
         << setw(10) << "Akhir"
         << endl;

    for (int i = 0; i <= S.Top; i++) {
        float akhir = hitungNilaiAkhir(S.dataMahasiswa[i]);
        cout << left << setw(5) << (i + 1)
             << setw(12) << S.dataMahasiswa[i].Nama
             << setw(12) << S.dataMahasiswa[i].NIM
             << setw(10) << S.dataMahasiswa[i].NilaiTugas
             << setw(10) << S.dataMahasiswa[i].NilaiUTS
             << setw(10) << S.dataMahasiswa[i].NilaiUAS
             << setw(10) << akhir
             << endl;
    }
}

void SearchNilaiAkhir(StackMahasiswa &S, float minAkhir, float maxAkhir) {
    if (isEmpty(S)) {
        cout << "Stack kosong.\n";
        return;
    }

    cout << "\n=== Hasil Searching Nilai Akhir dari "
         << minAkhir << " sampai " << maxAkhir << " ===\n";

    bool found = false;

    for (int i = 0; i <= S.Top; i++) {
        float akhir = hitungNilaiAkhir(S.dataMahasiswa[i]);

        if (akhir >= minAkhir && akhir <= maxAkhir) {
            cout << "Posisi " << (i + 1)
                 << " | Nama: " << S.dataMahasiswa[i].Nama
                 << " | Nilai Akhir: " << akhir << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Tidak ada data dalam rentang tersebut.\n";
    }
}


void MaxNilaiAkhir(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong.\n";
        return;
    }

    int idxMax = 0;
    float maxAkhir = hitungNilaiAkhir(S.dataMahasiswa[0]);

    for (int i = 1; i <= S.Top; i++) {
        float akhir = hitungNilaiAkhir(S.dataMahasiswa[i]);
        if (akhir > maxAkhir) {
            maxAkhir = akhir;
            idxMax = i;
        }
    }

    cout << "\n=== Data Dengan Nilai Akhir Terbesar ===\n";
    cout << "Posisi: " << (idxMax + 1) << endl;
    cout << "Nama  : " << S.dataMahasiswa[idxMax].Nama << endl;
    cout << "NIM   : " << S.dataMahasiswa[idxMax].NIM << endl;
    cout << "Nilai Akhir: " << maxAkhir << endl;
}
