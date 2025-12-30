# <h1 align="center">  Graph  </h1>
<p align="center">Akhdan Ziyad</p>

## Dasar Teori
Graph merupakan himpunan tidak kosong dari node (vertec) dan garis penghubung (edge). Contoh sederhana tentang graph, yaitu antara Tempat Kost Anda dengan Common Lab. Tempat Kost Anda dan Common Lab merupakan node (vertec). Jalan yang menghubungkan tempat Kost dan Common Lab merupakan garis penghubung antara keduanya (edge).
## Guided 

### 1. [MLL]

## Unguided 


Graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode InsertNode(Graph &G, infoGraph x);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

void ResetVisited(Graph &G);
void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif
```
Graph.cpp
```
#include "graph.h"
#include <queue>

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode InsertNode(Graph &G, infoGraph x) {
    adrNode P = new ElmNode;
    P->info = x;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = G.first;
    G.first = P;
    return P;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = new ElmEdge;
    E1->node = N2;
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = new ElmEdge;
    E2->node = N1;
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void ResetVisited(Graph &G) {
    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N == NULL || N->visited == 1) return;

    cout << N->info << " ";
    N->visited = 1;

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        PrintDFS(G, E->node);
        E = E->next;
    }
}

void PrintBFS(Graph G, adrNode N) {
    queue<adrNode> Q;
    N->visited = 1;
    Q.push(N);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();
        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
}


```
main.cpp
```
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    adrNode A = InsertNode(G, 'A');
    adrNode B = InsertNode(G, 'B');
    adrNode C = InsertNode(G, 'C');
    adrNode D = InsertNode(G, 'D');
    adrNode E = InsertNode(G, 'E');
    adrNode F = InsertNode(G, 'F');
    adrNode Gg = InsertNode(G, 'G');
    adrNode H = InsertNode(G, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gg);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gg, H);

    PrintInfoGraph(G);

    cout << "\nDFS dari A: ";
    ResetVisited(G);
    PrintDFS(G, A);

    cout << "\n\nBFS dari A: ";
    ResetVisited(G);
    PrintBFS(G, A);

    return 0;
}


```

#### Output:
<img width="171" height="119" alt="image" src="https://github.com/user-attachments/assets/68507cb7-1af5-4f61-bc96-f58ead019580" />



Soal ini menekankan pemahaman ADT Graph tidak berarah dalam merepresentasikan hubungan antar simpul menggunakan struktur adjacency list. Implementasi operasi penambahan node, penghubungan edge, serta penelusuran DFS dan BFS menunjukkan keterkaitan antar node melalui pointer edge yang memungkinkan penelusuran graph secara sistematis. Penggunaan atribut visited berperan penting dalam menjaga konsistensi proses traversal, mencegah kunjungan berulang, serta memastikan efisiensi dan ketepatan dalam menjelajahi seluruh simpul yang terhubung.

#### Full code Screenshot:
<img width="262" height="372" alt="image" src="https://github.com/user-attachments/assets/07d23317-dbd0-4c99-bbd5-d440251f1ccb" />
<img width="288" height="431" alt="image" src="https://github.com/user-attachments/assets/c989bda0-437b-4fd6-bd9c-f5c27a1a56f0" />
<img width="251" height="406" alt="image" src="https://github.com/user-attachments/assets/f76ff1fb-153d-4e19-b63a-24b575d85c6a" />
<img width="253" height="395" alt="image" src="https://github.com/user-attachments/assets/1bd63334-8a79-4e2c-9917-e7a4077ad20a" />


## Kesimpulan
Praktikum ini bertujuan untuk memahami mekanisme kerja ADT Graph tidak berarah menggunakan representasi adjacency list, khususnya pada proses penambahan simpul (node), penghubungan antar simpul (edge), serta penelusuran graph menggunakan algoritma Depth First Search (DFS) dan Breadth First Search (BFS). Melalui praktikum ini, mahasiswa dapat memahami cara kerja traversal graph secara terstruktur, sistematis, dan efisien dengan memanfaatkan penanda visited untuk menghindari kunjungan berulang pada simpul yang sama.
## Referensi
Petani Kode. (n.d.). Struktur Data Graph.






