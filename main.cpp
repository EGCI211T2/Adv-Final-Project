#include <iostream>
#include "check.h"
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
void exit() {
    cout << "Quiting the game...\n";
    cout << "Good bye!\n";
}
// #7 intro
void intro() {
    cout << "Long time ago...\n";
}
// #7 loading
void loading() {
    cout << "Loading....\n";
}
// #8 new_character_selection
void New() {
    cout << " \n";
    cout <<"Character: \n";
    cout <<"slot 1" << endl;
    cout <<"slot 2" << endl;
    cout <<"slot 3" << endl;
    cout <<"Select Character: "<< endl;
}

void Delete() {
    cout << " \n";
    cout <<"Character: \n";
    cout <<"slot 1" << endl;
    cout <<"slot 2" << endl;
    cout <<"slot 3" << endl;
    cout <<"Select Character: "<< endl;
}

void Continue() {
    cout << " \n";
    cout <<"Character: \n";
    cout <<"slot 1" << endl;
    cout <<"slot 2" << endl;
    cout <<"slot 3" << endl;
    cout <<"Select Character: "<< endl;
}




int main() {
    int option;
    char chr;
    do{
        displayMenu();
        cin>>option; // Get user input without echoing to the console
        switch(option) {
            case 1:
                pagebreak();
                intro();
                break;
            case 2:
                exit();
                break;
            default:
                cout << "Invalid option! Please try again.\n";

        } 
            } while(option<1||option>6);

    cout<<"Press x to continue."<<endl;
    do{
        cin>>chr;
        switch(chr){
            case 'x':
            pagebreak();
            loading();
            break;
            default:
                cout<< "Invalid character! Please try again.\n";
        }
    }while(chr!='x');

    do{
        characterMenu();
        cin>>option; // Get user input without echoing to the console
        switch(option) {
            case 1:
                New();
                break;
            case 2:
                Continue();
                break;
            case 3:
                Delete();
                break;
            default:
                cout << "Invalid option! Please try again.\n";

        } 
            } while(option<1||option>6);



    return 0;
}