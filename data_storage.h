#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class PlayerData {
public:
    string playerName;
    int playerScore;

    PlayerData() : playerName(""), playerScore(0) {}
    PlayerData(string name, int score) : playerName(name), playerScore(score) {}

    void print() const {
        cout << "Player Name: " << playerName << ", Player Score: " << playerScore << endl;
    }
};

class DataStorage {
private:
    static const int MAX_CAPACITY = 50; // Define maximum capacity
    PlayerData players[MAX_CAPACITY];
    int size;
    string playerName; // Add player name to uniquely identify their data file

public:
    DataStorage(const string& player) : size(0), playerName(player) {}

    void addPlayer(const PlayerData& player) {
        if (size < MAX_CAPACITY) {
            players[size++] = player;
        } else {
            cerr << "DataStorage is full!" << endl;
        }
    }

    void saveToFile() {
        ofstream outFile(playerName + "_player_info.txt");
        if (outFile.is_open()) {
            for (int i = 0; i < size; i++) {
                outFile << players[i].playerName << " " << players[i].playerScore << endl;
            }
            outFile.close();
        } else {
            cerr << "Unable to open file for writing!" << endl;
        }
    }

    void loadFromFile() {
        ifstream inFile(playerName + "_player_info.txt");
        if (inFile.is_open()) {
            size = 0;
            while (!inFile.eof() && size < MAX_CAPACITY) {
                PlayerData player;
                inFile >> player.playerName >> player.playerScore;
                if (inFile.fail()) {
                    break;
                }
                addPlayer(player);
            }
            inFile.close();
        } else {
            cerr << "Unable to open file for reading!" << endl;
        }
    }

    void display() const {
        for (int i = 0; i < size; i++) {
            players[i].print();
        }
    }
};

#endif // DATA_STORAGE_H
