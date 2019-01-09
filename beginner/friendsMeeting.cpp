#include <iostream>
#include <climits>
#include <cmath>
#include <map>
using namespace std;

bool isPrime(int number);
int smallestPrime(int* sequence, int N);

int main() {
	map<int, pair<int, int*> > tests;

	int testCases;
	cin >> testCases;
	for (int testNo = 1; testNo <= testCases; testNo++) {
		int N;
		cin >> N;
		int* sequence = new int[N];

		for (int i = 0; i < N; i++)
			cin >> sequence[i];
		tests[testNo] = make_pair(N, sequence);
	}

	for (int testNo = 1; testNo <= testCases; testNo++) {
		pair<int, int*> testCase = tests[testNo];
		cout << smallestPrime(testCase.second, testCase.first) << endl;
	}
}

bool isPrime(int number) {
	int sqroot = sqrt(number);
	for (int i = 2; i <= sqroot; i++) {
		if (number % i == 0)
			return false;
	}

	return true;
}

int smallestPrime(int* sequence, int N) {
	int min = INT_MAX;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			int ij = sequence[i] * sequence[j];
			if(isPrime(ij) && ij < min)
				min = ij;
		}
	}
	if (min == INT_MAX)
		return -1;
	return min;
}