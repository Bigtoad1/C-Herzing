#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int two_d[5][5];
	memset(two_d, 0, sizeof(two_d));
	for (int i = 5 - 1; i >= 0; i--) {
		cout << "\n";
		for (int j = 5 - 1; j >= 0; j--) { cout << two_d[i][j]; cout << " "; }
	}
	int user_value;
	while (true) {
		cout << "enter value to be randomly put into array";
		cin >> user_value;
		two_d[rand() % 5][rand() % 5] = user_value;
		for (int i = 5 - 1; i >= 0; i--) {
			cout << "\n";
			for (int j = 5 - 1; j >= 0; j--) { cout << two_d[i][j]; cout << " "; }
		}
		cout << ' \n';
	}
}