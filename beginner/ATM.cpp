#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int withdraw;
	double balance;
	cin >> withdraw >> balance;

	double maybe = (double)(withdraw + 0.50);

	if (withdraw % 5 != 0 || maybe > balance) {
		cout << setprecision(2) << fixed;
		cout << balance;
	}

	else {
		cout << setprecision(2) << fixed;
		cout << balance - maybe;
	}
}