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
    int health;

    PlayerData(const char* n, int s, int r, int h) {
        strncpy(name, n, 50);
        name[49] = '\0';  // Ensure null-termination
        score = s;
        rounds = r;
        health = h;
    }

    PlayerData() {
        name[0] = '\0';  // Ensure empty string is null-terminated
        score = 0;
        rounds = 0;
        health = 100;
    }
};

class DataStorage {
    PlayerData player;
    KilledMonsters killedMonsters;

public:
    DataStorage() = default;

    void createNewCharacter() {
        char name[50];
        cout << "Enter player name: ";
        cin.ignore();  // To clear the newline character left in the buffer
        cin.getline(name, 50);
        player = PlayerData(name, 0, 0, 100);  // Set initial score to 0, health to 100
    }

    void displayPlayerData() const {
        cout << "Player Name: " << player.name << "\n";
        cout << "Score: " << player.score << "\n";
        cout << "Rounds Played: " << player.rounds << "\n";
        cout << "Health: " << player.health << "\n";
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

    void addScore(int points) {
        player.score += points;
    }
};

#endif // DATA_STORAGE_H
