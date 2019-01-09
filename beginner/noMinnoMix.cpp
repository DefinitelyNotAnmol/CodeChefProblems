#include <iostream>
using namespace std;

void productOfSequence(int* sequence, int N, int K);

int main() {
	int testCases;
	cin >> testCases;

	for (int testNo = 1; testNo <= testCases; testNo++)	{
		int N, K;
		cin >> N >> K;
		int* sequence = new int[N];
		for (int element = 0; element < N; element++) 
			cin >> sequence[element];

		productOfSequence(sequence, N, K);
	}
}

void productOfSequence(int* sequence, int N, int K) {
	
}