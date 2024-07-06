#ifndef KILLED_MONSTERS_H
#define KILLED_MONSTERS_H

#include <iostream>
#include <cstring>

using namespace std;

struct KilledMonster {
    char name[50];
    int count;

    KilledMonster(const char* n, int c) {
        strncpy(name, n, 50);
        count = c;
    }

    KilledMonster() {
        strncpy(name, "", 50);
        count = 0;
    }
};

class Node {
private:
    KilledMonster value;
    Node *nextPtr;
public:
    Node(KilledMonster v) : value(v), nextPtr(nullptr) {}
    void setNext(Node* next) { nextPtr = next; }
    Node* getNext() const { return nextPtr; }
    KilledMonster getValue() const { return value; }
};

typedef Node* NodePtr;

class KilledMonsters {
    NodePtr top;
    int size;
public:
    void addKilledMonster(const char*, int);
    int getTotalKills() const;
    void displayKilledMonsters() const;
    KilledMonsters();
    ~KilledMonsters();
    bool isEmpty() const;
};

void KilledMonsters::addKilledMonster(const char* name, int count) {
    NodePtr new_node = new Node(KilledMonster(name, count));
    if (new_node) {
        new_node->setNext(top);
        top = new_node;
        ++size;
    } else {
        cout << "No more memory left" << endl;
    }
}

int KilledMonsters::getTotalKills() const {
    int totalKills = 0;
    NodePtr current = top;
    while (current != nullptr) {
        totalKills += current->getValue().count;
        current = current->getNext();
    }
    return totalKills;
}

void KilledMonsters::displayKilledMonsters() const {
    cout << "Killed Monsters:\n";
    NodePtr current = top;
    while (current != nullptr) {
        cout << current->getValue().name << ": " << current->getValue().count << "\n";
        current = current->getNext();
    }
}

KilledMonsters::KilledMonsters() : top(nullptr), size(0) {}

KilledMonsters::~KilledMonsters() {
    cout << "Clearing the killed monsters list" << endl;
    while (size > 0) {
        NodePtr temp = top;
        top = top->getNext();
        delete temp;
        --size;
    }
}

bool KilledMonsters::isEmpty() const {
    return top == nullptr;
}

#endif // KILLED_MONSTERS_H
