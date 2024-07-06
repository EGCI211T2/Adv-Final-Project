#include <iostream>
#include "check.h"
#include "data_storage.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include "combat.h"
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
    char option;
    char chr;
    int no;
    char * name1 = new char[50];
    char* mon[100] = {"Gorgath", "Zoltar", "Draknor", "Morthog", "Blazebane", "Thundersnout", "Venomclaw", "Shadowfang", "Grimscale", "Bonecrusher", "Frostbite", "Ironhide", "Scalebeard", "Bloodfang", "Wraithhorn", "Diremaw", "Bramblebeast", "Nightstalker", "Dreadnought", "Stormcaller", "Voidreaver", "Deathshade", "Pyroclasm", "Ravager", "Lichlord", "Carnifex", "Ghoulbane", "Netherfiend", "Warbringer", "Doomclaw", "Basilisk", "Hellhound", "Plaguemaw", "Corpsegrinder", "Nightmarer", "Firefang", "Darkseer", "Warlock", "Cryptkeeper", "Charnel", "Abyssal", "Skullduggery", "Harbinger", "Deathbringer", "Maleficent", "Bloodlust", "Dracolich", "Wyrmkin", "Titanclaw", "Venomspike", "Spiteful", "Miasma", "Phantasm", "Direwolf", "Hellfire", "Thunderclap", "Ashenfang", "Razorclaw", "Doomshade", "Grimreaper", "Stormwrath", "Bonegnasher", "Darkbane", "Wraithwalker", "Venomlord", "Skulldrinker", "Bloodreaver", "Shadowstalker", "Frostclaw", "Ironfist", "Scalethorn", "Bloodscream", "Wraithscream", "Direfang", "Brambleclaw", "Nightshade", "Dreadclaw", "Stormfury", "Voidwalker", "Deathhowl", "Pyrofang", "Ravager", "Lichbane", "Carnage", "Ghoulclaw", "Netherlord", "Warhowl", "Doomgaze", "Basiliskfang", "Hellclaw", "Plaguebringer", "Corpseclaw", "Nightmare", "Firemaw", "Darkclaw", "Warlock", "Cryptlord", "Charred", "Abysswalker", "Skullcrusher"};

    DataStorage dataStorage;

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
    } while (option!='x');

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
    do{
        no = numin();
        switch (no) {
            case 1:
                clear();
                cout<<"Enter player name: ";
                cin>>name1;
                cout<<name1;
                //dataStorage.createNewCharacter();
                //dataStorage.displayPlayerData();
                break;
            case 2:
                cout << "Leaving the game" << endl;
                // Add logic to continue the game
                break;
            default:
                cout << "Invalid option. Please select again." << endl;
        }
    } while(no<1||no>2);

    monster A(name1);
    monster B(mon[1]);
    A.upgrade();A.battle(A,B);

    return 0;
}