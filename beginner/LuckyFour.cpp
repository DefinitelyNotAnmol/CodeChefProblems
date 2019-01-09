#include <iostream>
using namespace std;

int count4(int number) {
	int lastDigit;
	int count = 0;

	while (number > 0) {
		lastDigit = number % 10;
		if (lastDigit == 4)
			count++;
		number /= 10;
	}

	return count;
}

int main() {
	int numbers;
	cin >> numbers;

	for (int i = 0; i < numbers; i++) {
		int number;
		cin >> number;

		cout << count4(number) << endl;
	}
}