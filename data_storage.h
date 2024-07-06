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

class KilledMonsterNode {
public:
    KilledMonsterData data;
    KilledMonsterNode* next;

    KilledMonsterNode(KilledMonsterData m) : data(m), next(nullptr) {}
};

class KilledMonsters {
private:
    KilledMonsterNode* head;
    string playerName;

    void clearList() {
        while (head) {
            KilledMonsterNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

public:
    KilledMonsters(const string& player) : head(nullptr), playerName(player) {}

    ~KilledMonsters() {
        clearList();
    }

    void addMonster(const KilledMonsterData& monster) {
        KilledMonsterNode* newNode = new KilledMonsterNode(monster);
        newNode->next = head;
        head = newNode;
    }

    void saveToFile() {
        ofstream outFile(playerName + "_monsters_archive.txt", ios::app);
        if (outFile.is_open()) {
            KilledMonsterNode* current = head;
            while (current) {
                outFile << current->data.name << " "
                        << current->data.hp << " "
                        << current->data.atk << " "
                        << current->data.def << " "
                        << current->data.sta << " "
                        << current->data.spd << " "
                        << current->data.lvl << endl;
                current = current->next;
            }
            outFile.close();
        } else {
            cerr << "Unable to open file for writing!" << endl;
        }
    }

    void loadFromFile() {
        clearList();
        ifstream inFile(playerName + "_monsters_archive.txt");
        if (inFile.is_open()) {
            while (!inFile.eof()) {
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
        KilledMonsterNode* current = head;
        while (current) {
            current->data.print();
            current = current->next;
        }
    }

    void clearNodes() {
        saveToFile();
        clearList();
    }
};

#endif // KILLED_MONSTERS_H
