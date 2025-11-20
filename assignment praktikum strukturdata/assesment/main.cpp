#include <iostream>
#include "SLLInventory.h"

using namespace std;

int main() {
    List L;
    createList(L);

    Product p1 = {"Pulpen", "A001", 20, 2500.0f, 0.0f};
    Product p2 = {"Buku Tulis", "A002", 15, 5000.0f, 10.0f};
    Product p3 = {"Penghapus", "A003", 30, 1500.0f, 0.0f};

    insertLast(L, p1);
    insertLast(L, p2);
    insertLast(L, p3);

    cout << "Initial list:\n";
    viewList(L);

    Product deleted;
    deleteFirst(L, deleted);
    cout << "\nAfter deleteFirst (removed: " << deleted.Nama << "):\n";
    viewList(L);

    Product newP = {"Stabilo", "A010", 40, 9000.0f, 5.0f};
    updateAtPosition(L, 2, newP);   
    cout << "\nAfter update at position 2:\n";
    viewList(L);

    float min = 2000.0f;
    float max = 7000.0f;

    cout << "\nSearch for HargaAkhir in [" << min << ", " << max << "]:\n";
    searchByFinalPriceRange(L, min, max);

    return 0;
}
