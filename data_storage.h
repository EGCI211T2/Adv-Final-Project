#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H

#include <iostream>
#include <cstring>
#include "killed_monsters.h"

using namespace std;

struct PlayerData {
    char name[50];
    int score;
    int rounds;

    PlayerData(const char* n, int s, int r) {
        strncpy(name, n, 50);
        score = s;
        rounds = r;
    }

    PlayerData() {
        strncpy(name, "", 50);
        score = 0;
        rounds = 0;
    }
};

class DataStorage {
private:
    PlayerData player;
    KilledMonsters killedMonsters;

public:
    DataStorage() {}

    void createNewCharacter() {
        char name[50];
        int score;

        cout << "Enter player name: ";
        cin.getline(name, 50);
        cout << "Enter initial score: ";
        cin >> score;
        cin.ignore(); // To clear the newline character left in the buffer

        player = PlayerData(name, score, 0);
    }

    void displayPlayerData() {
        cout << "Player Name: " << player.name << "\n";
        cout << "Score: " << player.score << "\n";
        cout << "Rounds Played: " << player.rounds << "\n";
    }

    void updateRoundsBasedOnKills() {
        player.rounds = killedMonsters.getTotalKills();
    }

    const PlayerData& getPlayerData() const {
        return player;
    }

    KilledMonsters& getKilledMonsters() {
        return killedMonsters;
    }
};

#endif // DATA_STORAGE_H
