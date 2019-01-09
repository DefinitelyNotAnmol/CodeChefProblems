#include <iostream>
using namespace std;

int main() {
	int n, k;
	int input;
	int count = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++)	{
		cin >> input;
		if (input % k == 0)
			count++;
	}

	cout << count;
}