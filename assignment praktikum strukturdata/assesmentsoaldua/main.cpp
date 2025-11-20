#include <iostream>
#include "DLLPlaylist.h"

using namespace std;

int main() {
    List L;
    createList(L);

 
    Song A, B, C, temp;

    A.Title = "Senja di Kota";
    A.Artist = "Nona Band";
    A.DurationSec = 210;
    A.PlayCount = 150;
    A.Rating = 4.2;

    B.Title = "Langkahmu";
    B.Artist = "Delta";
    B.DurationSec = 185;
    B.PlayCount = 320;
    B.Rating = 4.8;

    C.Title = "Hujan Minggu";
    C.Artist = "Arka";
    C.DurationSec = 240;
    C.PlayCount = 90;
    C.Rating = 3.9;

    insertLast(L, A);
    insertLast(L, B);
    insertLast(L, C);

    cout << "\n== LIST SETELAH INSERT 3 LAGU ==\n";
    viewList(L);


    deleteLast(L, temp);

    cout << "\n== LIST SETELAH deleteLast ==\n";
    viewList(L);


    Song U;
    U.Title = "Pelita";
    U.Artist = "Luna";
    U.DurationSec = 200;
    U.PlayCount = 260;
    U.Rating = 4.5;

    updateAtPosition(L, 2, U);

    cout << "\n== LIST SETELAH UPDATE POSISI 2 ==\n";
    viewList(L);

    Song D;
    D.Title = "Senandung";
    D.Artist = "Mira";
    D.DurationSec = 175;
    D.PlayCount = 120;
    D.Rating = 4.0;

    address P = L.head;
    int idx = 1;
    while (P != NULL && idx < 2) {
        P = P->next;
        idx++;
    }

    insertBefore(L, P, D);

    cout << "\n== LIST SETELAH insertBefore POSISI 2 ==\n";
    viewList(L);

    Song UB;
    UB.Title = "Bintang Malam";
    UB.Artist = "Kirana";
    UB.DurationSec = 190;
    UB.PlayCount = 200;
    UB.Rating = 4.7;

    P = L.head;
    idx = 1;
    while (P != NULL && idx < 2) {
        P = P->next;
        idx++;
    }

    updateBefore(L, P, UB);

    cout << "\n== LIST SETELAH updateBefore POSISI 2 ==\n";
    viewList(L);

    P = L.head;
    idx = 1;
    while (P != NULL && idx < 3) {
        P = P->next;
        idx++;
    }

    deleteBefore(L, P, temp);

    cout << "\n== LIST SETELAH deleteBefore POSISI 3 ==\n";
    viewList(L);

    cout << "\n== SEARCH PopularityScore 150.0 - 300.0 ==\n";
    searchByPopularityRange(L, 150.0f, 300.0f);

    return 0;
}
