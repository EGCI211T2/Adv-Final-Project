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

    void print() const {
        cout << "Name: " << name << ", HP: " << hp << ", ATK: " << atk 
             << ", DEF: " << def << ", STA: " << sta << ", SPD: " << spd 
             << ", LVL: " << lvl << endl;
    }
};

class KilledMonsters {
private:
    static const int MAX_CAPACITY = 100; // Define maximum capacity
    KilledMonsterData monsters[MAX_CAPACITY];
    int size;
    string playerName; // Add player name to uniquely identify their data file

public:
    KilledMonsters(const string& player) : size(0), playerName(player) {}

    void addMonster(const KilledMonsterData& monster) {
        if (size < MAX_CAPACITY) {
            monsters[size++] = monster;
        } else {
            cerr << "KilledMonsters storage is full!" << endl;
        }
    }

    void saveToFile() {
        ofstream outFile(playerName + "_monsters_archive.txt");
        if (outFile.is_open()) {
            for (int i = 0; i < size; i++) {
                outFile << monsters[i].name << " "
                        << monsters[i].hp << " "
                        << monsters[i].atk << " "
                        << monsters[i].def << " "
                        << monsters[i].sta << " "
                        << monsters[i].spd << " "
                        << monsters[i].lvl << endl;
            }
            outFile.close();
        } else {
            cerr << "Unable to open file for writing!" << endl;
        }
    }

    void loadFromFile() {
        ifstream inFile(playerName + "_monsters_archive.txt");
        if (inFile.is_open()) {
            size = 0;
            while (!inFile.eof() && size < MAX_CAPACITY) {
                KilledMonsterData monster;
                inFile >> monster.name >> monster.hp >> monster.atk >> monster.def 
                       >> monster.sta >> monster.spd >> monster.lvl;
                if (inFile.fail()) {
                    break;
                }
                addMonster(monster);
            }
            inFile.close();
        } else {
            cerr << "Unable to open file for reading!" << endl;
        }
    }

    void display() const {
        for (int i = 0; i < size; i++) {
            monsters[i].print();
        }
    }
};

#endif // KILLED_MONSTERS_H
