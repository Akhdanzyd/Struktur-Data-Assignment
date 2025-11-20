#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <string>
using std::string;

const int MAX = 6;


struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};


struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;  
};


bool isEmpty(StackMahasiswa &S);
bool isFull(StackMahasiswa &S);

void createStack(StackMahasiswa &S);
void Push(StackMahasiswa &S);
void Pop(StackMahasiswa &S);

void Update(StackMahasiswa &S, int posisi);
void View(StackMahasiswa &S);

void SearchNilaiAkhir(StackMahasiswa &S, float minAkhir, float maxAkhir);
void MaxNilaiAkhir(StackMahasiswa &S);

#endif