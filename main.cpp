#include <iostream>
#include "check.h"
#include "data_storage.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include "combat.h"
#include <chrono>
#include <thread>
using namespace std;

void displayMenu() {
    cout << " _____________________________ \n";
    cout << "|                             |\n";
    cout << "|    Defender of the World    |\n";
    cout << "|_____________________________|\n";
    cout << "press x to continue" << endl;
}

void characterMenu() {
    cout << " _______________________________ \n";
    cout << "|                               |\n";
    cout << "|          1.Play               |\n";
    cout << "|          2.Exit               |\n";
    cout << "|_______________________________|\n";
    cout << " \n";
    cout << "Select option: ";
}

void startGame() {
    cout << "Starting the game...\n";
}

void information() {
    cout << "";
}

void upgrade() {
    cout << "";
}

void history() {
    cout << "";
}

void save() {
    cout << "";
}

void exitGame() {
    cout << "Quitting the game...\n";
    cout << "Good bye!\n";
}

void intro() {
    cout << "Long time ago...\n";
    cout << "Press x to continue." << endl;
}

void loading() {
    cout << "Loading";
    for (int i = 0; i < 10; ++i) {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout << endl;
}

void clear() {
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\033[2J\033[1;1H";
#endif
}

bool askToContinue() {
    char choice;
    cout << "Do you want to continue? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() {
    char option;
    char chr;
    int no;
    char* name1 = new char[50];
    const char* mon[100] = {"Gorgath", "Zoltar", "Draknor", "Morthog", "Blazebane", "Thundersnout", "Venomclaw", "Shadowfang", "Grimscale", "Bonecrusher", "Frostbite", "Ironhide", "Scalebeard", "Bloodfang", "Wraithhorn", "Diremaw", "Bramblebeast", "Nightstalker", "Dreadnought", "Stormcaller", "Voidreaver", "Deathshade", "Pyroclasm", "Ravager", "Lichlord", "Carnifex", "Ghoulbane", "Netherfiend", "Warbringer", "Doomclaw", "Basilisk", "Hellhound", "Plaguemaw", "Corpsegrinder", "Nightmarer", "Firefang", "Darkseer", "Warlock", "Cryptkeeper", "Charnel", "Abyssal", "Skullduggery", "Harbinger", "Deathbringer", "Maleficent", "Bloodlust", "Dracolich", "Wyrmkin", "Titanclaw", "Venomspike", "Spiteful", "Miasma", "Phantasm", "Direwolf", "Hellfire", "Thunderclap", "Ashenfang", "Razorclaw", "Doomshade", "Grimreaper", "Stormwrath", "Bonegnasher", "Darkbane", "Wraithwalker", "Venomlord", "Skulldrinker", "Bloodreaver", "Shadowstalker", "Frostclaw", "Ironfist", "Scalethorn", "Bloodscream", "Wraithscream", "Direfang", "Brambleclaw", "Nightshade", "Dreadclaw", "Stormfury", "Voidwalker", "Deathhowl", "Pyrofang", "Ravager", "Lichbane", "Carnage", "Ghoulclaw", "Netherlord", "Warhowl", "Doomgaze", "Basiliskfang", "Hellclaw", "Plaguebringer", "Corpseclaw", "Nightmare", "Firemaw", "Darkclaw", "Warlock", "Cryptlord", "Charred", "Abysswalker", "Skullcrusher"};

    DataStorage dataStorage;

    bool continueGame = true;

    while (continueGame) {
        displayMenu();
        do {
            cin >> option;
            switch (option) {
                case 'x':
                    clear();
                    intro();
                    break;
                default:
                    cout << "Invalid option! Please try again.\n";
            }
        } while (option != 'x');

        do {
            cin >> chr;
            switch (chr) {
                case 'x':
                    clear();
                    loading();
                    break;
                default:
                    cout << "Invalid character! Please try again.\n";
            }
        } while (chr != 'x');

        do {
            characterMenu();
            no = numin();
            switch (no) {
                case 1:
                    clear();
                    cout << "Enter player name: ";
                    cin >> name1;
                    cout << name1 << endl;
                    //dataStorage.createNewCharacter();
                    //dataStorage.displayPlayerData();
                    break;
                case 2:
                    cout << "Leaving the game" << endl;
                    continueGame = false;
                    break;
                default:
                    cout << "Invalid option. Please select again." << endl;
            }
        } while (no < 1 || no > 2);

        if (!continueGame) break;

        while (continueGame) {
            monster A(name1);
            monster B(mon[1]);
            A.upgrade();
            A.battle(A, B);

            if (!askToContinue()) {
                continueGame = false;
                exitGame();
            } else {
                clear();
                // Optionally add any other logic for what happens after a battle here
            }
        }
    }

    delete[] name1;

    return 0;
}
