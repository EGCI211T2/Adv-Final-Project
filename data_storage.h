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
    int health; // Add health
    int level;  // Add level

    PlayerData(const char* n, int s, int r, int h, int l) {
        strncpy(name, n, 50);
        score = s;
        rounds = r;
        health = h;
        level = l;
    }

    PlayerData() {
        strncpy(name, "", 50);
        score = 0;
        rounds = 0;
        health = 100; // Default health
        level = 1;    // Default level
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

        cout << "Enter player name: ";
        cin.ignore(); // To clear the newline character left in the buffer
        cin.getline(name, 50);

        player = PlayerData(name, 0, 0, 100, 1); // Set initial score to 0, health to 100, and level to 1
    }

    void displayPlayerData() {
        cout << "Player Name: " << player.name << "\n";
        cout << "Score: " << player.score << "\n";
        cout << "Rounds Played: " << player.rounds << "\n";
        cout << "Health: " << player.health << "\n";
        cout << "Level: " << player.level << "\n";
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