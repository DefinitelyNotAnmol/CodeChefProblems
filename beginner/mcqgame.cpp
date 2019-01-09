#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void addAnswer(int N, int K, vector<long long int>& answer, int index);

int main() {
	int testCases;
	cin >> testCases;

	std::vector<long long int> answer;
	answer.resize(testCases);

	for (int testNo = 1; testNo <= testCases; testNo++) {
		int N, K;
		cin >> N >> K;
		addAnswer(N, K, answer, testNo);
	}

	for (auto ans : answer)
		cout << ans % (long long int)(pow(10, 9) + 7) << "\n";
}

void addAnswer(int N, int K, vector<long long int>& answer, int index) {
	long long int ans = 0;
	long long int power = 1;
	for (int i = 1; i <= N; i++) {
		power = power * K;
		ans += power;
	}

	answer[index-1] = ans;
}