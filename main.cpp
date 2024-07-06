#include <iostream>
#include "check.h"
#include "data_storage.h"
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void displayMenu() {
    cout << " _____________________________ \n";
    cout << "|                             |\n";
    cout << "|    Defender of the World    |\n";
    cout << "|_____________________________|\n";
    cout << "1. Start Game\n";
    cout << "2. Quit\n";
    cout << "Select option: ";
}

void characterMenu() {
    cout << " _______________________________ \n";
    cout << "|                               |\n";
    cout << "|          1.New                |\n";
    cout << "|          2.Continue           |\n";
    cout << "|          3.Delete             |\n";
    cout << "|_______________________________|\n";
    cout << " \n";
    cout << "Select option: ";
}

// #1 start
void startGame() {
    cout << "Starting the game...\n";
}

// #2 info
void information() {
    cout << "";
    cout << "";
    cout << "";
}

// #3 upgrade
void upgrade() {
    cout << "";
}

// #4 history
void history() {
    cout << "";
}

// #5 save
void save() {
    cout << "";
}

// #6 exit
void exitGame() {
    cout << "Quitting the game...\n";
    cout << "Good bye!\n";
}

// #7 intro
void intro() {
    cout << "Long time ago...\n";
    cout << "Press x to continue." << endl;
}

// #7 loading
void loading() {
    cout << "Loading....\n";
}

// Clear screen function
void clear() {
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\033[2J\033[1;1H";
#endif
}

int main() {
    int option;
    char chr;
    DataStorage dataStorage;

    displayMenu();
    do {
        cin >> option;
        switch (option) {
            case 1:
                clear();
                intro();
                break;
            case 2:
                exitGame();
                return 0;
            default:
                cout << "Invalid option! Please try again.\n";
                cout << "Select option: ";
        }
    } while (option < 1 || option > 2);

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

    characterMenu();
    while (true) {
        cin >> option;
        switch (option) {
            case 1:
                clear();
                dataStorage.createNewCharacter();
                dataStorage.displayPlayerData();
                break;
            case 2:
                cout << "Continue option selected." << endl;
                // Add logic to continue the game
                break;
            case 3:
                cout << "Delete option selected." << endl;
                // Add logic to delete a character
                break;
            default:
                cout << "Invalid option. Please select again." << endl;
        }
    }

    return 0;
}