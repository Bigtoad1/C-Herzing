#include <iostream>
#include <math.h>

using namespace std;


class PlayerSword {
    public:
        string playername;
        int phealth = 100;
        int phealthTemp = 100;
        int pdefense = 2;
        int pdamage = 10;
        int pexpPoints = 1;
        int plevel = 1;

        void spendPoints() {
            string input = "y";
            while (input != "q") {
                cout << "You have: ";
                cout << pexpPoints;
                cout << " left to spend" << endl;
                cout << "press 'q' to quit at any time" << endl;
                cout << "your health, defence and damage are: " << endl;
                cout << phealth;
                cout << " ";
                cout << pdefense;
                cout << " ";
                cout << pdamage;
                cout << endl;
                cout << "enter 'h', 'p', or 'd' to upgrade them respecivly: ";
                cin >> input;
                if (input == "h" && pexpPoints > 0) {
                    phealth += 10;
                    pexpPoints -= 1;
                }
                else if (input == "p" && pexpPoints > 0) {
                    pdefense += 2;
                    pexpPoints -= 1;
                }
                else if (input == "d" && pexpPoints > 0) {
                    pdamage += 5;
                    pexpPoints -= 1;
                }
                else {
                    cout << "nothing affected" << endl;
                }
            }
        }
};

class EnemySword {
    public:
        string ename = "";
        int ehealth = 90;
        int edefense = 1;
        int edamage = 5;
        string namePre[8] = { "Iron", "Dimond","Stone", "Wood", "Mythral" };
        string nameSuf[7] = { "Great", "Short", "", "Cursed", "Holy", "Demon" };
};

int main() {
    string input;
    cout << "Welcome to Sword Battle! press q to quit at any time" << endl;
    cout << "what is your name: ";
    cin >> input;
    PlayerSword player;
    player.playername = input;
    while (input != "q") {
        int prefix = rand() % 5;
        int sufex = rand() % 6;
        double modifyer = 1 + (rand() % player.plevel + 1) / 100.0;
        EnemySword eSword;
        eSword.ehealth = pow(eSword.ehealth, modifyer);
        eSword.edefense = pow(eSword.edefense, modifyer);
        eSword.edamage = pow(eSword.edamage, modifyer);
        eSword.ename = eSword.namePre[prefix] + " " + eSword.nameSuf[sufex] + " Sword";
        cout << "enemy sword " + eSword.ename + " health, protection, damage: " << endl;
        cout << eSword.ehealth;
        cout << " ";
        cout << eSword.edefense;
        cout << " ";
        cout << eSword.edamage;
        cout << endl;
        cout << "to enter the store type 'store', otherwise, Fight!" << endl;
        cin >> input;
        if (input == "store") {
            player.spendPoints();
        } else if (input == "q") {
            break;
        }
        while (player.phealthTemp >= 0 || eSword.ehealth >= 0) {
            eSword.ehealth -= player.pdamage - eSword.edefense;
            player.phealthTemp -= eSword.edamage - player.pdefense;
            if (eSword.ehealth <= 0) {
                cout << "Player won! ";
                cout << player.pexpPoints;
                cout << " points to spend" << endl;
                break;
            }
            else if (player.phealthTemp <= 0) {
                cout << "player Died" << endl;
                break;
            }
        }
        if (player.phealthTemp <= 0) {
            cout << "player Died" << endl;
            break;
        }
        player.phealthTemp = player.phealth;
        player.plevel += 1;
        player.pexpPoints += 1;
    }
    cout << "Thanks for Playing! you reached lvl: ";
    cout << player.plevel;
    cin >> input;
}