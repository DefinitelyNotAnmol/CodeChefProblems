#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <list>
// #include <algorithm> //propoably not needed
using namespace std;

class Shops {
	unordered_map<int, list<int> > shops;
	bool isSame(const list<int>& stock1, const list<int>& stock2);
public:
	void addShop(const int& shopNo, const int& noOfItems);
	void query1(const int& shopNo, const int& noOfItems);
	void query2(const int& startingShopNo, const int& endingShopNo, const int& noOfItems);
	// void printShops();
};

int main() {
	// {string name;
	// 	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//this above function cin.ignore function should be used before using getline()
		//& after using cin because after using cin '\n' is left in the input buffer 
		//due to which getline immediately processes the newline and save a emtpy string
		//making an illusion that it skipped the getline()
	// 	std::getline(std::cin, name);} //cin.ignore() & getline() stuff
	Shops shops;
	int noOfShops;
	int noOfQueries;
	int noOfItems;
	int input;

	// cin >> noOfShops;
	// cin >> noOfQueries;
	scanf("%d", &noOfShops);
	scanf("%d", &noOfQueries);

	for (int shopNo = 1; shopNo <= noOfShops; shopNo++) {
		// cin >> noOfItems;
		scanf("%d", &noOfItems);
		shops.addShop(shopNo, noOfItems);
	}

	for (int queryNo = 1; queryNo <= noOfQueries; queryNo++) {
		int queryType;
		scanf("%d", &queryType);
		// cin >> queryType;

		if (queryType == 1) {
			int shopNo;
			// cin >> shopNo;
			// cin >> noOfItems;
			scanf("%d", &shopNo);
			scanf("%d", &noOfItems);
			shops.query1(shopNo, noOfItems);
		}

		else if (queryType == 2) {
			int L, R;
			// cin >> L >> R;
			// cin >> noOfItems;
			scanf("%d%d", &L, &R);
			scanf("%d", &noOfItems);
			shops.query2(L, R, noOfItems);
		}
	}
}

bool Shops::isSame(const list<int>& stock1, const list<int>& stock2) {
	for (int s1 : stock1) {
		for (int s2 : stock2) {
			if (s1 == s2)
				return false;
		}
	}

	return true;
}

void Shops::addShop(const int& shopNo, const int& noOfItems) {
	int input;
	for (int itemNo = 1; itemNo <= noOfItems; itemNo++) {
		// cin >> input;
		scanf("%d", &input);
		shops[shopNo].emplace_back(input);
	}
}

void Shops::query1(const int& shopNo, const int& noOfItems) {
	shops[shopNo].clear();
	int input;
	for (int itemNo = 1; itemNo <= noOfItems; itemNo++) {
		// cin >> input;
		scanf("%d", &input);
		shops[shopNo].emplace_back(input);
	}
}

void Shops::query2(const int& startingShopNo, const int& endingShopNo, const int& noOfItems) {
	int count = 0;
	int input;
	list<int> newStock;
	for (int itemNo = 1; itemNo <= noOfItems; itemNo++) {
		// cin >> input;
		scanf("%d", &input);
		newStock.emplace_back(input);
	}

	for (int shopNo = startingShopNo; shopNo <= endingShopNo; shopNo++) {
		if (isSame(shops[shopNo], newStock))
			count++;
	}

	// cout << count << endl;
	printf("%d\n", count);
}

// void Shops::printShops() {
// 	for (pair<int, list<int> > shop : shops) {
// 		cout << "Shop No " << shop.first << ":\t";
// 		for (int stock : shop.second) {
// 			cout << stock << ", ";
// 		}

// 		cout << endl;
// 	}
// }