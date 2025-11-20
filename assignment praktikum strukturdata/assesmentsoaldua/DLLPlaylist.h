#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <string>

using std::string;

struct Song {
    string Title;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating;
};

struct Node;
typedef Node* address;


struct Node {
    Song info;
    address prev;
    address next;
};

struct List {
    address head;
    address tail;
};

bool isEmpty(const List &L);
void createList(List &L);
address allocate(const Song &S);
void deallocate(address P);

void insertFirst(List &L, const Song &S);
void insertLast(List &L, const Song &S);
void insertAfter(List &L, address Q, const Song &S);
void insertBefore(List &L, address Q, const Song &S);

void deleteFirst(List &L, Song &S);
void deleteLast(List &L, Song &S);
void deleteAfter(List &L, address Q, Song &S);
void deleteBefore(List &L, address Q, Song &S);

void updateAtPosition(List &L, int posisi, const Song &S);
void updateBefore(List &L, address Q, const Song &S);


void viewList(const List &L);
void searchByPopularityRange(const List &L, float minScore, float maxScore);

#endif 
