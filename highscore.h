#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "data_storage.h"

using namespace std;

#define MAX_PLAYERS 100

// Structure to hold player information
struct Player {
    char name[50];
    int score;
    int rounds;

    Player(const char* n, int s, int r) {
        strncpy(name, n, 50);
        score = s;
        rounds = r;
    }

    Player() {
        strncpy(name, "", 50);
        score = 0;
        rounds = 0;
    }
};

// Class to handle the highscore operations
class Highscore {
private:
    Player players[MAX_PLAYERS];
    int playerCount;
    const char* filename = "highscore.txt";

    // Method to save the highscore to a file
    void saveToFile() {
        ofstream file(filename);
        if (file.is_open()) {
            file << "Leaderboard\n";
            sortPlayers();
            for (int i = 0; i < playerCount; ++i) {
                file << players[i].name << " " << players[i].score << " " << players[i].rounds << "\n";
            }
            file.close();
        } else {
            cerr << "Unable to open file for writing: " << filename << endl;
        }
    }

    // Method to sort players by score in descending order
    void sortPlayers() {
        for (int i = 0; i < playerCount - 1; ++i) {
            for (int j = i + 1; j < playerCount; ++j) {
                if (players[i].score < players[j].score) {
                    Player temp = players[i];
                    players[i] = players[j];
                    players[j] = temp;
                }
            }
        }
    }

public:
    Highscore() : playerCount(0) {}

    // Method to add a player to the highscore list
    void addPlayer(const PlayerData& playerData) {
        if (playerCount < MAX_PLAYERS) {
            players[playerCount++] = Player(playerData.name, playerData.score, playerData.rounds);
            saveToFile();
        } else {
            cerr << "Maximum number of players reached!" << endl;
        }
    }

    // Method to display the leaderboard in the console
    void displayLeaderboard() {
        sortPlayers();
        cout << "Leaderboard\n";
        for (int i = 0; i < playerCount; ++i) {
            cout << players[i].name << " " << players[i].score << " " << players[i].rounds << "\n";
        }
    }
};

#endif // HIGHSCORE_H
