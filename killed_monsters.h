#ifndef KILLED_MONSTERS_H
#define KILLED_MONSTERS_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class KilledMonsters {
private:
    static const int MAX_MONSTERS = 100;
    string killed_monsters[MAX_MONSTERS];
    int count;

public:
    KilledMonsters();
    void addMonster(const string& monster);
    void printKilledMonsters() const;
    void saveToFile() const;
    void loadFromFile();
};

KilledMonsters::KilledMonsters() : count(0) {}

void KilledMonsters::addMonster(const string& monster) {
    if (count < MAX_MONSTERS) {
        killed_monsters[count++] = monster;
    } else {
        cout << "Monster list is full!" << endl;
    }
}

void KilledMonsters::printKilledMonsters() const {
    for (int i = 0; i < count; ++i) {
        cout << killed_monsters[i] << endl;
    }
}

void KilledMonsters::saveToFile() const {
    ofstream outFile("monsters.txt");
    if (outFile.is_open()) {
        outFile << count << endl;
        for (int i = 0; i < count; ++i) {
            outFile << killed_monsters[i] << endl;
        }
        outFile.close();
    } else {
        cout << "Unable to open file for writing: monsters.txt" << endl;
    }
}

void KilledMonsters::loadFromFile() {
    ifstream inFile("monsters.txt");
    if (inFile.is_open()) {
        inFile >> count;
        inFile.ignore(); // To ignore the newline character after count
        for (int i = 0; i < count; ++i) {
            getline(inFile, killed_monsters[i]);
        }
        inFile.close();
    } else {
        cout << "Unable to open file for reading: monsters.txt" << endl;
    }
}

#endif // KILLED_MONSTERS_H
