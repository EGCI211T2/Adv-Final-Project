#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H

#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include "killed_monsters.h"

using namespace std;

class PlayerStats {
public:
    int level;
    int exp;
    int hp;
    int attack;

    PlayerStats(int lvl = 1, int xp = 0, int health = 100, int atk = 10);
};

PlayerStats::PlayerStats(int lvl, int xp, int health, int atk)
    : level(lvl), exp(xp), hp(health), attack(atk) {}

class DataStorage {
private:
    static const int MAX_PLAYERS = 10;
    string player_names[MAX_PLAYERS];
    PlayerStats player_stats[MAX_PLAYERS];
    int player_count;

public:
    DataStorage();
    void addPlayer(const string& name, const PlayerStats& stats);
    void printPlayersInfo() const;
    void saveToFile() const;
    void loadFromFile();
    bool loadPlayerProfile(const string& name, PlayerStats& stats, KilledMonsters& killedMonsters);
};

DataStorage::DataStorage() : player_count(0) {}

void DataStorage::addPlayer(const string& name, const PlayerStats& stats) {
    if (player_count < MAX_PLAYERS) {
        player_names[player_count] = name;
        player_stats[player_count] = stats;
        player_count++;
    } else {
        cout << "Player list is full!" << endl;
    }
}

void DataStorage::printPlayersInfo() const {
    for (int i = 0; i < player_count; ++i) {
        cout << "Player Name: " << player_names[i] << endl;
        cout << "Level: " << player_stats[i].level << endl;
        cout << "Experience: " << player_stats[i].exp << endl;
        cout << "HP: " << player_stats[i].hp << endl;
        cout << "Attack: " << player_stats[i].attack << endl;
        cout << endl;
    }
}

void DataStorage::saveToFile() const {
    ofstream outFile("player.txt");
    if (outFile.is_open()) {
        outFile << player_count << endl;
        for (int i = 0; i < player_count; ++i) {
            outFile << player_names[i] << endl;
            outFile << player_stats[i].level << endl;
            outFile << player_stats[i].exp << endl;
            outFile << player_stats[i].hp << endl;
            outFile << player_stats[i].attack << endl;
        }
        outFile.close();
    } else {
        cout << "Unable to open file for writing: player.txt" << endl;
    }
}

void DataStorage::loadFromFile() {
    ifstream inFile("player.txt");
    if (inFile.is_open()) {
        inFile >> player_count;
        inFile.ignore(); // To ignore the newline character after player_count
        for (int i = 0; i < player_count; ++i) {
            getline(inFile, player_names[i]);
            inFile >> player_stats[i].level;
            inFile >> player_stats[i].exp;
            inFile >> player_stats[i].hp;
            inFile >> player_stats[i].attack;
            inFile.ignore(); // To ignore the newline character after stats
        }
        inFile.close();
    } else {
        cout << "Unable to open file for reading: player.txt" << endl;
    }
}

bool DataStorage::loadPlayerProfile(const string& name, PlayerStats& stats, KilledMonsters& killedMonsters) {
    ifstream inFile("player.txt");
    if (inFile.is_open()) {
        int count;
        inFile >> count;
        inFile.ignore(); // To ignore the newline character after count

        for (int i = 0; i < count; ++i) {
            string player_name;
            getline(inFile, player_name);

            if (player_name == name) {
                player_names[player_count] = player_name;
                inFile >> stats.level;
                inFile >> stats.exp;
                inFile >> stats.hp;
                inFile >> stats.attack;
                inFile.ignore(); // To ignore the newline character after stats

                player_stats[player_count] = stats;
                player_count++;
                
                // Load the corresponding killed monsters
                killedMonsters.loadFromFile();
                
                inFile.close();
                return true;
            } else {
                // Skip this player's stats
                inFile.ignore(numeric_limits<streamsize>::max(), '\n');
                inFile.ignore(numeric_limits<streamsize>::max(), '\n');
                inFile.ignore(numeric_limits<streamsize>::max(), '\n');
                inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        inFile.close();
    }
    return false;
}

#endif // DATA_STORAGE_H
