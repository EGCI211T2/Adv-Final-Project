#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct PlayerScore {
    char name[50];
    int score;
    int rounds;

    PlayerScore(const char* n, int s, int r) {
        strncpy(name, n, 50);
        score = s;
        rounds = r;
    }

    PlayerScore() {
        strncpy(name, "", 50);
        score = 0;
        rounds = 0;
    }
};

class HighScore {
    PlayerScore players[10];
    int playerCount;
    const char* filename = "highscores.txt";

    void loadFromFile() {
        ifstream infile(filename);
        playerCount = 0;
        if (!infile) return;
        while (infile >> players[playerCount].name >> players[playerCount].score >> players[playerCount].rounds) {
            playerCount++;
            if (playerCount >= 10) break;
        }
    }

    void saveToFile() {
        ofstream outfile(filename);
        for (int i = 0; i < playerCount; ++i) {
            outfile << players[i].name << " " << players[i].score << " " << players[i].rounds << "\n";
        }
    }

    void sortPlayers() {
        for (int i = 0; i < playerCount - 1; ++i) {
            for (int j = i + 1; j < playerCount; ++j) {
                if (players[j].score > players[i].score) {
                    PlayerScore temp = players[i];
                    players[i] = players[j];
                    players[j] = temp;
                }
            }
        }
    }

public:
    HighScore() {
        loadFromFile();
    }

    void addPlayerScore(const char* name, int score, int rounds) {
        if (playerCount < 10) {
            players[playerCount++] = PlayerScore(name, score, rounds);
        } else if (score > players[playerCount - 1].score) {
            players[playerCount - 1] = PlayerScore(name, score, rounds);
        }
        sortPlayers();
        saveToFile();
    }

    void displayLeaderboard() {
        cout << "Leaderboard\n";
        for (int i = 0; i < playerCount; ++i) {
            cout << players[i].name << " " << players[i].score << " " << players[i].rounds << "\n";
        }
    }
};

#endif // HIGHSCORE_H
