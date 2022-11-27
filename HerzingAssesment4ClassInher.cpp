#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class Weapon {
    public:
        string wepType = "";
        double damage;
        double speed;
        string rareity[3] = { "Common ", "Rare ", "Epic " };
        string prefix[4] = { "Great ", "Somber ", "Old ", "Glimering " };
        string suffix[4] = { "Iron ", "Steel ", "Bronze ", "Mythral " };
        string nameOf;

        void genName() {
            nameOf = rareity[rand() % 3] + prefix[rand() % 4] + suffix[rand() % 4] + wepType;
        }
};

class Axe : public Weapon {
    public:
        string wepType = "Axe";
        void genStats() {
            damage = rand() % 13 + 3;
            speed = (rand() % 25 + 75)/100.0;
        }
        void genName() {
            nameOf = rareity[rand() % 3] + prefix[rand() % 4] + suffix[rand() % 4] + wepType;
        }
};

class Dagger : public Weapon {
    public:
        string wepType = "Dagger";
        void genStats() {
            damage = rand() % 5 + 3;
            speed = (rand() % 30 + 100) / 100.0;
        }
        void genName() {
            nameOf = rareity[rand() % 3] + prefix[rand() % 4] + suffix[rand() % 4] + wepType;
        }
};

class Sword : public Weapon {
    public:
        string wepType = "Sword";
        void genStats() {
            damage = rand() % 9 + 3;
            speed = (rand() % 20 + 90) / 100.0;
        }
        void genName() {
            nameOf = rareity[rand() % 3] + prefix[rand() % 4] + suffix[rand() % 4] + wepType;
        }
};



int main() {
    srand(time(0));
    cout << "Hello, welcome to wepon maximizer!\n" << endl;
    cout << "Try to juge which wepon has the hightest DPS" << endl;
    cout << "Your current weapon is: ";
    auto_ptr<Axe> weaponCurrentAxe(new Axe);
    auto_ptr<Dagger> weaponCurrentDagger(new Dagger);
    auto_ptr<Sword> weaponCurrentSword(new Sword);
    weaponCurrentSword.get()->genName();
    weaponCurrentSword.get()->genStats();
    cout << weaponCurrentSword.get()->nameOf << endl;
    cout << "current stats are Damage: ";
    cout << weaponCurrentSword.get()->damage << " Speed: " << weaponCurrentSword.get()->speed;
    auto_ptr<Axe> weaponAxe(new Axe);
    auto_ptr<Dagger> weaponDagger(new Dagger);
    auto_ptr<Sword> weaponSword(new Sword);
    cout << "\ncurrent DPS: ";
    cout << weaponSword.get()->damage * weaponSword.get()->speed;
    int selection;
    while (true) {
        int newWeponSelection = rand() % 3;
        if(newWeponSelection == 0) {
            weaponAxe.get()->genName();
            weaponAxe.get()->genStats();
        }
        else if (newWeponSelection == 1) {
            weaponDagger.get()->genName();
            weaponDagger.get()->genStats();
        }
        else if (newWeponSelection == 2) {
            weaponSword.get()->genName();
            weaponSword.get()->genStats();
        }
        switch (newWeponSelection) {
        case 0:
            cout << "\nNew Weapon Name is: ";
            cout << weaponAxe.get()->nameOf;
            cout << "\nNew weapon stats are Damage: ";
            cout << weaponAxe.get()->damage << " Speed: " << weaponAxe.get()->speed;
            cout << "\nWould you like to equip 1=yes 2=no: ";
            cin >> selection;
            if (selection == 1) {
                weaponCurrentAxe = weaponAxe;
                cout << "\ncurrent DPS: ";
                cout<< weaponCurrentAxe.get()->damage * weaponCurrentAxe.get()->speed;
            }
        case 1:
            cout << "\nNew Weapon Name is: ";
            cout << weaponDagger.get()->nameOf;
            cout << "\nNew weapon stats are Damage: ";
            cout << weaponDagger.get()->damage << " Speed: " << weaponDagger.get()->speed;
            cout << "\nWould you like to equip 1=yes 2=no: ";
            cin >> selection;
            if (selection == 1) {
                weaponCurrentDagger = weaponDagger;
                cout << "\ncurrent DPS: ";
                cout << weaponCurrentDagger.get()->damage * weaponCurrentDagger.get()->speed;
            }
        case 2:
            cout << "\nNew Weapon Name is: ";
            cout << weaponSword.get()->nameOf;
            cout << "\nNew weapon stats are Damage: ";
            cout << weaponSword.get()->damage << " Speed: " << weaponSword.get()->speed;
            cout << "\nWould you like to equip 1=yes 2=no: ";
            cin >> selection;
            if (selection == 1) {
                weaponCurrentSword = weaponSword;
                cout << "\ncurrent DPS: ";
                cout << weaponCurrentSword.get()->damage * weaponCurrentSword.get()->speed;
            }

        }
        
    }
}
