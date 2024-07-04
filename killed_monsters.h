#ifndef KILLED_MONSTERS_H
#define KILLED_MONSTERS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class KilledMonsterData {
public:
    string name;
    int hp;
    int atk;
    int def;
    int sta;
    int spd;
    int lvl;

    
    KilledMonsterData() : name(""), hp(0), atk(0), def(0), sta(0), spd(0), lvl(0) {}

    
    KilledMonsterData(string n, int h, int a, int d, int s, int sp, int l) 
        : name(n), hp(h), atk(a), def(d), sta(s), spd(sp), lvl(l) {}
};

void saveKilledMonsters(const KilledMonsterData* killedMonsters, int size) {
    ofstream outFile("killed_monsters.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < size; i++) {
            outFile << killedMonsters[i].name << " "
                    << killedMonsters[i].hp << " "
                    << killedMonsters[i].atk << " "
                    << killedMonsters[i].def << " "
                    << killedMonsters[i].sta << " "
                    << killedMonsters[i].spd << " "
                    << killedMonsters[i].lvl << endl;
        }
        outFile.close();
    } else {
        cerr << "Unable to open file for writing!" << endl;
    }
}

KilledMonsterData* loadKilledMonsters(int &size) {
    ifstream inFile("killed_monsters.txt");
    if (!inFile.is_open()) {
        cerr << "Unable to open file for reading!" << endl;
        size = 0;
        return nullptr;
    }

    size = 0;
    string line;
    while (getline(inFile, line)) {
        size++;
    }

    KilledMonsterData* killedMonsters = new KilledMonsterData[size];
    inFile.clear();
    inFile.seekg(0, ios::beg);

    int index = 0;
    while (inFile >> killedMonsters[index].name 
                  >> killedMonsters[index].hp 
                  >> killedMonsters[index].atk 
                  >> killedMonsters[index].def 
                  >> killedMonsters[index].sta 
                  >> killedMonsters[index].spd 
                  >> killedMonsters[index].lvl) {
        index++;
    }

    inFile.close();
    return killedMonsters;
}

void displayKilledMonsters(const KilledMonsterData* killedMonsters, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Name: " << killedMonsters[i].name
             << ", HP: " << killedMonsters[i].hp
             << ", ATK: " << killedMonsters[i].atk
             << ", DEF: " << killedMonsters[i].def
             << ", STA: " << killedMonsters[i].sta
             << ", SPD: " << killedMonsters[i].spd
             << ", LVL: " << killedMonsters[i].lvl << endl;
    }
}

#endif 
