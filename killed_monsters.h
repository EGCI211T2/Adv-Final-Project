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
        name[49] = '\0';  // Ensure null-termination
        count = c;
    }

    KilledMonster() {
        name[0] = '\0';  // Ensure empty string is null-terminated
        count = 0;
    }
};

class KilledMonsters {
    KilledMonster* monsters;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        KilledMonster* newMonsters = new KilledMonster[capacity];
        for (int i = 0; i < size; ++i) {
            newMonsters[i] = monsters[i];
        }
        delete[] monsters;
        monsters = newMonsters;
    }

public:
    KilledMonsters() : size(0), capacity(10) {
        monsters = new KilledMonster[capacity];
    }

    ~KilledMonsters() {
        delete[] monsters;
    }

    void addMonster(const char* name, int count) {
        if (size == capacity) {
            resize();
        }
        monsters[size++] = KilledMonster(name, count);
    }

    void displayKilledMonsters() const {
        cout << "Killed Monsters:\n";
        for (int i = 0; i < size; ++i) {
            cout << monsters[i].name << ": " << monsters[i].count << "\n";
        }
    }

    int getTotalKills() const {
        int totalKills = 0;
        for (int i = 0; i < size; ++i) {
            totalKills += monsters[i].count;
        }
        return totalKills;
    }
};

#endif // KILLED_MONSTERS_H
