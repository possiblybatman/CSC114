#include <iostream>
#include <string>
using namespace std;

int main() {
    string choice;

    while(true) {
        cout << "Welcome to the Gaggle of Idiots the JRPG!" << endl;
        cout << "Type 'end' to end the game." << endl;
        cout << endl;
        cout << "You wake up in the tavern to the sound of a brawl." << endl;
        cin >>  choice;
        if (choice == "end") {
            break;
        }
    }
    cout << "Game Over" << endl;
    return 0;
}

