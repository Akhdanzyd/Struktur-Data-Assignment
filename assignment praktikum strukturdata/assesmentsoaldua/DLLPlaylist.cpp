#include <iostream>
#include "DLLPlaylist.h"

using namespace std;

static float getPopularityScore(const Song &S) {
    return 0.8f * S.PlayCount + 20.0f * S.Rating;
}


bool isEmpty(const List &L) {
    return (L.head == NULL && L.tail == NULL);
}

void createList(List &L) {
    L.head = NULL;
    L.tail = NULL;
}

address allocate(const Song &S) {
    address P = new Node;
    P->info = S;
    P->prev = NULL;
    P->next = NULL;
    return P;
}

void deallocate(address P) {
    delete P;
}

void insertFirst(List &L, const Song &S) {
    address P = allocate(S);
    if (isEmpty(L)) {
        L.head = P;
        L.tail = P;
    } else {
        P->next = L.head;
        L.head->prev = P;
        L.head = P;
    }
}

void insertLast(List &L, const Song &S) {
    address P = allocate(S);
    if (isEmpty(L)) {
        L.head = P;
        L.tail = P;
    } else {
        P->prev = L.tail;
        L.tail->next = P;
        L.tail = P;
    }
}

void insertAfter(List &L, address Q, const Song &S) {
    if (Q == NULL) return;

    address P = allocate(S);
    P->next = Q->next;
    P->prev = Q;

    if (Q->next != NULL)
        Q->next->prev = P;
    else
        L.tail = P;

    Q->next = P;
}

void insertBefore(List &L, address Q, const Song &S) {
    if (Q == NULL) return;

    if (Q == L.head) {
        insertFirst(L, S);
        return;
    }

    address P = allocate(S);
    P->next = Q;
    P->prev = Q->prev;
    Q->prev->next = P;
    Q->prev = P;
}

void deleteFirst(List &L, Song &S) {
    if (isEmpty(L)) return;

    address P = L.head;
    S = P->info;

    if (L.head == L.tail) {
        L.head = NULL;
        L.tail = NULL;
    } else {
        L.head = P->next;
        L.head->prev = NULL;
    }

    deallocate(P);
}

void deleteLast(List &L, Song &S) {
    if (isEmpty(L)) return;

    address P = L.tail;
    S = P->info;

    if (L.head == L.tail) {
        L.head = NULL;
        L.tail = NULL;
    } else {
        L.tail = P->prev;
        L.tail->next = NULL;
    }

    deallocate(P);
}

void deleteAfter(List &L, address Q, Song &S) {
    if (Q == NULL || Q->next == NULL) return;

    address P = Q->next;
    S = P->info;

    Q->next = P->next;
    if (P->next != NULL)
        P->next->prev = Q;
    else
        L.tail = Q;

    deallocate(P);
}

void deleteBefore(List &L, address Q, Song &S) {
    if (Q == NULL || Q->prev == NULL) return;

    address P = Q->prev;
    S = P->info;

    if (P == L.head) {
        L.head = Q;
        Q->prev = NULL;
    } else {
        P->prev->next = Q;
        Q->prev = P->prev;
    }

    deallocate(P);
}

void updateAtPosition(List &L, int posisi, const Song &S) {
    if (isEmpty(L) || posisi <= 0) return;

    address P = L.head;
    int idx = 1;

    while (P != NULL && idx < posisi) {
        P = P->next;
        idx++;
    }

    if (P != NULL) {
        P->info = S;
    }
}

void updateBefore(List &L, address Q, const Song &S) {
    if (Q == NULL || Q->prev == NULL) return;

    address P = Q->prev;
    P->info = S;
}


void viewList(const List &L) {
    if (isEmpty(L)) {
        cout << "List kosong.\n";
        return;
    }

    address P = L.head;
    int pos = 1;

    cout << "\n=== PLAYLIST ===\n";
    while (P != NULL) {
        float score = getPopularityScore(P->info);

        cout << pos << ". "
             << P->info.Title << " | "
             << P->info.Artist << " | "
             << P->info.DurationSec << "s | "
             << "Play: " << P->info.PlayCount << " | "
             << "Rating: " << P->info.Rating << " | "
             << "Score: " << score << "\n";

        P = P->next;
        pos++;
    }
}

void searchByPopularityRange(const List &L, float minScore, float maxScore) {
    if (isEmpty(L)) {
        cout << "List kosong.\n";
        return;
    }

    address P = L.head;
    int pos = 1;
    bool found = false;

    cout << "\n=== SEARCH RESULT (Score "
         << minScore << " - " << maxScore << ") ===\n";

    while (P != NULL) {
        float score = getPopularityScore(P->info);

        if (score >= minScore && score <= maxScore) {
            cout << pos << ". "
                 << P->info.Title << " | "
                 << P->info.Artist << " | "
                 << "Score: " << score << "\n";
            found = true;
        }

        P = P->next;
        pos++;
    }

    if (!found)
        cout << "Tidak ada lagu dalam rentang.\n";
}
