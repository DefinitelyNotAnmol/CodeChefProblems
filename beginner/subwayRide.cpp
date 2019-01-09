#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

class graph {
	map<int, list<pair<int, int> > > adjList;
public:
	void addEdge(int u, int v, int color, bool bidir=true) {
		adjList[u].push_back(make_pair(v, color));
		adjList[v].push_back(make_pair(u, color));
	}

	void bfs(T src);
	int bfs_shortest(T src, T dest);
	void dfshelper(T node, std::map<T, bool> &visited);
	void dfs(T src);
	void dfs_forest();
	int cost(int u, int v);
};

int main() {
	graph g;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g.addEdge(u, v, w);
	}

	int Q;
	for (int i = 0; i < Q; i++) {
		int u, v;
		cin >> u >> v;
		cout << g.cost(u, v) << endl;
	}
}

int graph::cost(int u, int v) {
	queue<int> q;
	map<int, int> distance;
	map<int, int> parent;

	for (auto i : adjList) 
		distance[i.first] = INT_MAX;

	q.push(u);
	distance[u] = 0;
	parent[u] = u;

	while (!q.empty()) {
		T node = q.front();
		q.pop();

		for (auto neighbours : adjList[node]) {
			if (distance[neighbours] == INT_MAX) {
				q.push(neighbours);
				distance[neighbours] = distance[node] + 1;
				parent[neighbours] = node;
			}
		}

		if (distance[v] != INT_MAX)
			break;
	}

	return distance[v];	//rather than printing returning the shortest distance
}

void graph::dfs_forest() {
	//prints all the connected components
	std::map<T, bool> visited;
	for (auto i : adjList) {
		T key = i.first;
		if (!visited[key]) {
			dfshelper(key, visited);
		}

		cout << endl;
	}
}

void graph::dfs(T src) {
	//prints only one connect component of which src is defined
	std::map<T, bool> visited;
	dfshelper(src, visited);
}

void graph::dfshelper(T node, std::map<T, bool> &visited) {
	visited[node] = true;
	cout << node << " ";
	for (auto neighbours : adjList[node]) {
		if (!visited[neighbours]) 
			dfshelper(neighbours, visited);
	}
}

int graph::bfs_shortest(T src, T dest) {
	queue<T> q;
	map<T, int> distance;
	map<T, T> parent;

	for (auto i : adjList) 
		distance[i.first] = INT_MAX;

	q.push(src);
	distance[src] = 0;
	parent[src] = src;

	while (!q.empty()) {
		T node = q.front();
		// cout << node << " ";
		q.pop();

		for (auto neighbours : adjList[node]) {
			if (distance[neighbours] == INT_MAX) {
				q.push(neighbours);
				distance[neighbours] = distance[node] + 1;
				parent[neighbours] = node;
			}
		}

		if (distance[dest] != INT_MAX)
			break;
	}

	// cout << "\nDistance of " << dest << " from " << src 
	// 	 << " is " << distance[dest] << endl;

	// for (auto i : adjList) {
	// 	T node = i.first;
	// 	cout << "Distance of " << node << " from " << src
	// 		 << " is " << distance[node] << endl;
	// }

	//snakes and ladder
	T temp = dest;
	while (temp != src) {
		cout << temp << ", ";
		temp = parent[temp];
	}

	cout << src << endl;
	return distance[dest];	//rather than printing returning the shortest distance
}

void bfs(T src) {
	queue<T> q;
	map<T, bool> visited;
	q.push(src);
	visited[src] = true;

	while (!q.empty()) {
		T node = q.front();
		cout << node << " ";
		q.pop();
		for (auto neighbours :  adjList[node]) {
			if (!visited[neighbours]) {
				q.push(neighbours);
				visited[neighbours] = true;
			}
		}
	}
}

void print() {
	for (auto i : adjList) {
		cout << i.first << " = ";
		for (auto j : i.second) 
			cout << j << ", ";
		cout << endl;
	}
}