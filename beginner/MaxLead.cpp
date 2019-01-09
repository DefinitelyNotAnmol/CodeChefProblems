#include <iostream>
using namespace std;

int mod(int x, int y);

int main() {
	int rounds;
	cin >> rounds;

	int maxLead = 0;
	int curLead;
	int play1, play2;
	int points1 = 0, points2 = 0;
	int winner;

	for (int i = 0; i < rounds; i++) {
		cin >> play1 >> play2;

		points1 += play1;
		points2 += play2;

		curLead = mod(points1, points2);

		if (curLead > maxLead) {
			maxLead = curLead;
			winner = points1 > points2 ? 1 : 2;
		}
	}

	cout << winner << " " << maxLead;
}

int mod(int x, int y) {
	return (x > y ? x - y : y - x);
}