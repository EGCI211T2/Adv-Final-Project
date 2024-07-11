#include <iostream>
#include "check.h"
#include "data_storage.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include "combat.h"
#include <chrono>
#include "stack.h"
#include <thread>
#include "history.h"
using namespace std;
void displayMenu() {
    cout <<"  ________                                .___ .__                                            _____        __    .__                   ___________                               ____            "<<endl;
    cout <<" /  _____/   __ __  _____    _______    __| _/ |__| _____      ____     ______       ____   _/ ____\\     _/  |_  |  |__     ____       \\_   _____/   ____     ____   _______    / ___\\   ___.__."<<endl;
    cout <<"/   \\  ___  |  |  \\ \\__  \\   \\_  __ \\  / __ |  |  | \\__  \\    /    \\   /  ___/      /  _ \\ \\   __\\      \\    __\\ |  |  \\  _/ __ \\       |    __)_   /    \\  _/ __ \\  \\_  __ \\  / /_/  > <   |  |"<<endl;
    cout <<"\\    \\_\\  \\ |  |  /  / __ \\_  |  | \\/ / /_/ |  |  |  / __ \\_ |   |  \\  \\___ \\      (  <_> )  |  |         |  |   |   Y  \\ \\  ___/       |        \\ |   |  \\ \\  ___/   |  | \\/  \\___  /   \\___  |"<<endl;
    cout <<" \\______  / |____/  (____  /  |__|    \\____ |  |__| (____  / |___|  / /____  >      \\____/   |__|         |__|   |___|  /  \\___  >     /_______  / |___|  /  \\___  >  |__|    /_____/    / ____|"<<endl;
    cout <<"        \\/               \\/                \\/            \\/       \\/       \\/                                         \\/       \\/              \\/       \\/       \\/                      \\/     "<<endl;
    cout << "press x to continue" << endl;
}

void characterMenu(LL x) {
    system("clear");
    cout << " _______________________________ \n";
    cout << "|                               |\n";
    cout << "|          1.Play               |\n";
    cout << "|          2.Exit               |\n";
    cout << "|_______________________________|\n";
    shigh(x);
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
    srand(time(NULL));
    Stack s;
     LL h;
    char option;
    char chr;
    int no,round=0,c,result;
    char* name1 = new char[50],j;
    const char* mon[100] = {"Gorgath", "Zoltar", "Draknor", "Morthog", "Blazebane", "Thundersnout", "Venomclaw", "Shadowfang", "Grimscale", "Bonecrusher", "Frostbite", "Ironhide", "Scalebeard", "Bloodfang", "Wraithhorn", "Diremaw", "Bramblebeast", "Nightstalker", "Dreadnought", "Stormcaller", "Voidreaver", "Deathshade", "Pyroclasm", "Ravager", "Lichlord", "Carnifex", "Ghoulbane", "Netherfiend", "Warbringer", "Doomclaw", "Basilisk", "Hellhound", "Plaguemaw", "Corpsegrinder", "Nightmarer", "Firefang", "Darkseer", "Warlock", "Cryptkeeper", "Charnel", "Abyssal", "Skullduggery", "Harbinger", "Deathbringer", "Maleficent", "Bloodlust", "Dracolich", "Wyrmkin", "Titanclaw", "Venomspike", "Spiteful", "Miasma", "Phantasm", "Direwolf", "Hellfire", "Thunderclap", "Ashenfang", "Razorclaw", "Doomshade", "Grimreaper", "Stormwrath", "Bonegnasher", "Darkbane", "Wraithwalker", "Venomlord", "Skulldrinker", "Bloodreaver", "Shadowstalker", "Frostclaw", "Ironfist", "Scalethorn", "Bloodscream", "Wraithscream", "Direfang", "Brambleclaw", "Nightshade", "Dreadclaw", "Stormfury", "Voidwalker", "Deathhowl", "Pyrofang", "Ravager", "Lichbane", "Carnage", "Ghoulclaw", "Netherlord", "Warhowl", "Doomgaze", "Basiliskfang", "Hellclaw", "Plaguebringer", "Corpseclaw", "Nightmare", "Firemaw", "Darkclaw", "Warlock", "Cryptlord", "Charred", "Abysswalker", "Skullcrusher"};

    DataStorage dataStorage;

    bool continueGame = true;

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
            characterMenu(h);
            no = numin();
            switch (no) {
                case 1:
                {
                    clear();
                    cout << "Enter player name: ";
                    cin >> name1;
                    monster A(name1);
                    do{
                        round++;
                        j=rand()%100;
                        int hp=(rand()%3+4)*round+10,atk=(rand()%3+2)*round/2,def=(rand()%3+2)*round/2,spd=(rand()%3+1)*round;
                        monster B(mon[j],hp,atk,def,10,spd);
                        A.upgrade();
                        result=A.battle(A, B,round-1);
                        switch (result){
                            case 0:
                            cout<<"You lose"<<endl;
                            sleep(2);
                            break;
                            case 1:
                            cout<<"You win"<<endl;
                            s.push(mon[j]);
                            break;
                        }
                        if(result==1){
                        do{
                            c;
                            cout << "Do you want to continue? 1.y 2.n: ";
                            c=numin();
                            
                        }while(c<1||c>2);
                        }

                    }while(c==1&&result==1);
                }
                            if(result==1){
                            cout<<"You have save the energy for "<<round<<" times."<<endl;
                            sleep(2);
                            cout<<"You have eliminated these monsters."<<endl;
                            sleep(2);
                            for(int i=1;i<=round;i++)
                            {
                                cout<<i<<".";
                                s.pop();
                                sleep(1);
                            }
                            vhigh(name1,round);
                            }
                            else{
                            cout<<"You have save the energy for "<<round-1<<" times."<<endl;
                            sleep(2);
                            cout<<"You have eliminated these monsters."<<endl;
                            sleep(2);
                            for(int i=1;i<round;i++)
                            {
                                cout<<i<<".";
                                s.pop();
                                sleep(1);
                            }
                            vhigh(name1,round-1);
                            }
                    break;
                case 2:
                    cout << "Leaving the game" << endl;
                    continueGame = false;
                    break;
                default:
                    cout << "Invalid option. Please select again." << endl;
            }
        } while (no < 1 || no > 2);

       /*if (!continueGame) break;

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
        }*/
    

    delete[] name1;

    return 0;
}