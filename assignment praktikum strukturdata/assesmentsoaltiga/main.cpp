#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

int main() {
    StackMahasiswa S;
    createStack(S);

    Mahasiswa m;

    m.Nama = "Venti";
    m.NIM = "11111";
    m.NilaiTugas = 75.7;
    m.NilaiUTS = 82.1;
    m.NilaiUAS = 65.5;
    S.Top++;
    S.dataMahasiswa[S.Top] = m;

    m.Nama = "Xiao";
    m.NIM = "22222";
    m.NilaiTugas = 87.4;
    m.NilaiUTS = 88.9;
    m.NilaiUAS = 81.9;
    S.Top++;
    S.dataMahasiswa[S.Top] = m;

    m.Nama = "Kazuha";
    m.NIM = "33333";
    m.NilaiTugas = 92.3;
    m.NilaiUTS = 88.8;
    m.NilaiUAS = 82.4;
    S.Top++;
    S.dataMahasiswa[S.Top] = m;

    m.Nama = "Wanderer";
    m.NIM = "44444";
    m.NilaiTugas = 95.5;
    m.NilaiUTS = 85.5;
    m.NilaiUAS = 90.5;
    S.Top++;
    S.dataMahasiswa[S.Top] = m;

    m.Nama = "Lynette";
    m.NIM = "55555";
    m.NilaiTugas = 77.7;
    m.NilaiUTS = 65.4;
    m.NilaiUAS = 79.9;
    S.Top++;
    S.dataMahasiswa[S.Top] = m;

    m.Nama = "Chasca";
    m.NIM = "66666";
    m.NilaiTugas = 99.9;
    m.NilaiUTS = 93.6;
    m.NilaiUAS = 87.3;
    S.Top++;
    S.dataMahasiswa[S.Top] = m;

    cout << "\n=== STACK AWAL ===\n";
    View(S);

    cout << "\nPop 1x...\n";
    Pop(S);

    cout << "\n=== STACK SETELAH POP ===\n";
    View(S);

    Mahasiswa upd;
    upd.Nama = "Heizou";
    upd.NIM = "77777";
    upd.NilaiTugas = 99.9;
    upd.NilaiUTS = 88.8;
    upd.NilaiUAS = 77.7;

    cout << "\nUpdate posisi ke-3...\n";
    Update(S, 3);

    S.dataMahasiswa[2] = upd;

    cout << "\n=== STACK SETELAH UPDATE ===\n";
    View(S);

    cout << "\n=== SEARCH NILAI AKHIR 85.5 - 95.5 ===\n";
    SearchNilaiAkhir(S, 85.5, 95.5);

    cout << "\n=== NILAI AKHIR TERBESAR ===\n";
    MaxNilaiAkhir(S);

    return 0;
}
