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

class KilledMonsters {
private:
    static const int MAX_MONSTERS = 999;
    KilledMonster monsters[MAX_MONSTERS];
    int monsterCount;

public:
    KilledMonsters() : monsterCount(0) {}

    void addMonster(const char* name, int count) {
        if (monsterCount < MAX_MONSTERS) {
            monsters[monsterCount++] = KilledMonster(name, count);
        } else {
            cerr << "Maximum number of killed monsters reached!" << endl;
        }
    }

    int getTotalKills() const {
        int totalKills = 0;
        for (int i = 0; i < monsterCount; ++i) {
            totalKills += monsters[i].count;
        }
        return totalKills;
    }

    void displayKilledMonsters() const {
        cout << "Killed Monsters:\n";
        for (int i = 0; i < monsterCount; ++i) {
            cout << monsters[i].name << ": " << monsters[i].count << "\n";
        }
    }
};

#endif // KILLED_MONSTERS_H
