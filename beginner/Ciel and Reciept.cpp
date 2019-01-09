#include <iostream>
using namespace std;

int Menu(int money) {
	int MaxMenu = 2048;

	int count = 0;
	int menu = 0;

	while (MaxMenu > 0) {
		if (menu + MaxMenu <= money) {
			menu += MaxMenu;
			count++;
			if (menu == money)
				return count;
		}

		else {
			MaxMenu /= 2;
		}
	}
}

int main() {
	int testCases;
	cin >> testCases;

	for (int i = 0; i < testCases; i++)	 {
		int money;
		cin >> money;

		cout << Menu(money) << endl;
	}
}