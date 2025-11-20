#include <iostream>
#include <iomanip>
#include "SLLInventory.h"

using namespace std;

bool isEmpty(const List &L) {
    return L.head == NULL;
}

void createList(List &L) {
    L.head = NULL;
}

address allocate(const Product &P) {
    address node = new Node;
    node->info = P;
    node->next = NULL;
    return node;
}

void deallocate(address addr) {
    delete addr;
}

void insertFirst(List &L, const Product &P) {
    address node = allocate(P);
    node->next = L.head;
    L.head = node;
}

void insertLast(List &L, const Product &P) {
    if (isEmpty(L)) {
        insertFirst(L, P);
        return;
    }
    address cur = L.head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = allocate(P);
}

void insertAfter(List &, address Q, const Product &P) {
    if (Q == NULL) return;
    address node = allocate(P);
    node->next = Q->next;
    Q->next = node;
}

void deleteFirst(List &L, Product &P) {
    if (isEmpty(L)) return;
    address temp = L.head;
    P = temp->info;
    L.head = temp->next;
    deallocate(temp);
}

void deleteLast(List &L, Product &P) {
    if (isEmpty(L)) return;

    if (L.head->next == NULL) {
        deleteFirst(L, P);
        return;
    }

    address prev = NULL;
    address cur = L.head;

    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }

    P = cur->info;
    prev->next = NULL;
    deallocate(cur);
}

void deleteAfter(List &, address Q, Product &P) {
    if (Q == NULL || Q->next == NULL) return;

    address temp = Q->next;
    P = temp->info;
    Q->next = temp->next;
    deallocate(temp);
}

static float computeFinalPrice(const Product &p) {
    return p.HargaSatuan * (1.0f - p.DiskonPersen / 100.0f);
}

void updateAtPosition(List &L, int posisi, const Product &P) {
    if (posisi < 1) return;

    address cur = L.head;
    int idx = 1;

    while (cur != NULL && idx < posisi) {
        cur = cur->next;
        idx++;
    }

    if (cur == NULL) {
        cout << "Position " << posisi << " not found.\n";
        return;
    }

    cur->info = P;
}

void viewList(const List &L) {
    if (isEmpty(L)) {
        cout << "List is empty.\n";
        return;
    }

    cout << left << setw(4) << "No."
         << setw(15) << "Nama"
         << setw(8)  << "SKU"
         << setw(8)  << "Jumlah"
         << setw(15) << "HargaSatuan"
         << setw(15) << "Diskon(%)"
         << setw(15) << "HargaAkhir" << "\n";

    address cur = L.head;
    int idx = 1;

    while (cur != NULL) {
        float hargaAkhir = computeFinalPrice(cur->info);

        cout << left << setw(4) << idx
             << setw(15) << cur->info.Nama
             << setw(8)  << cur->info.SKU
             << setw(8)  << cur->info.Jumlah
             << setw(15) << fixed << setprecision(2) << cur->info.HargaSatuan
             << setw(15) << cur->info.DiskonPersen
             << setw(15) << fixed << setprecision(2) << hargaAkhir
             << "\n";

        idx++;
        cur = cur->next;
    }
}

void searchByFinalPriceRange(const List &L, float minPrice, float maxPrice) {
    if (isEmpty(L)) {
        cout << "List is empty.\n";
        return;
    }

    cout << "Search results for HargaAkhir in [" 
         << minPrice << ", " << maxPrice << "]:\n";

    address cur = L.head;
    int idx = 1;
    bool found = false;

    while (cur != NULL) {
        float hargaAkhir = computeFinalPrice(cur->info);

        if (hargaAkhir >= minPrice && hargaAkhir <= maxPrice) {
            found = true;
            cout << "Position " << idx << ": "
                 << cur->info.Nama << " (SKU " << cur->info.SKU
                 << ") - HargaAkhir = " 
                 << fixed << setprecision(2) << hargaAkhir << "\n";
        }

        idx++;
        cur = cur->next;
    }

    if (!found) {
        cout << "No products found in the given price range.\n";
    }
}
