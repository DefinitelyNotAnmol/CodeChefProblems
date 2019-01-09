#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return (a < b) ? false : true;
}

int main() {
	int N;
	cin >> N;

	int* containers = new int[N];
	for (int i = 0; i < N; i++)
		containers[i] = 0;

	int days;
	cin >> days;
	for (int i = 0; i < days; i++) {
		int l, u;
		cin >> l >> u;
		for (int j = l-1; j <= u-1; j++)
			containers[j]++;
	}

	sort(containers, containers+N, compare);

	int Q;
	cin >> Q;
	std::vector<int> v;
	for (int i = 0; i < Q; i++) {
		int query;
		cin >> query;
		int j = 0; 
		int count = 0;
		while (j < N and containers[j] >= query) {
			count++;
			j++;
		}

		v.push_back(count);
	}

	for (int i : v)
		cout << i << endl;
}
