#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H

#include <iostream>
#include <fstream>

using namespace std;

class CombatData {
public:
    int round;
    int monster1Hp;
    int monster2Hp;
    int monster1Lvl;
    int monster2Lvl;

    
    CombatData() : round(0), monster1Hp(0), monster2Hp(0), monster1Lvl(0), monster2Lvl(0) {}

    
    CombatData(int r, int m1Hp, int m2Hp, int m1Lvl, int m2Lvl) 
        : round(r), monster1Hp(m1Hp), monster2Hp(m2Hp), monster1Lvl(m1Lvl), monster2Lvl(m2Lvl) {}
};

void sortCombatLog(CombatData* combatLog, int size) {
    for (int i = 1; i < size; i++) {
        CombatData key = combatLog[i];
        int j = i - 1;
        while (j >= 0 && (combatLog[j].monster1Lvl + combatLog[j].monster2Lvl) < (key.monster1Lvl + key.monster2Lvl)) {
            combatLog[j + 1] = combatLog[j];
            j--;
        }
        combatLog[j + 1] = key;
    }
}

void saveCombatLog(const CombatData* combatLog, int size) {
    ofstream outFile("combat_log.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < size; i++) {
            outFile << "Round " << combatLog[i].round << ": MonsterA HP: " << combatLog[i].monster1Hp << ", Level: " << combatLog[i].monster1Lvl 
                    << " | MonsterB HP: " << combatLog[i].monster2Hp << ", Level: " << combatLog[i].monster2Lvl << endl;
        }
        outFile.close();
    } else {
        cerr << "Unable to open file for writing!" << endl;
    }
}

CombatData* loadCombatLog(int &size) {
    ifstream inFile("combat_log.txt");
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

    CombatData* combatLog = new CombatData[size];
    inFile.clear();
    inFile.seekg(0, ios::beg);

    int index = 0;
    while (inFile >> combatLog[index].round >> combatLog[index].monster1Hp >> combatLog[index].monster2Hp >> combatLog[index].monster1Lvl >> combatLog[index].monster2Lvl) {
        index++;
    }

    inFile.close();
    return combatLog;
}

#endif 
