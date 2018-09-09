#include <iostream>
#include <vector>
#include <string.h>

#define MAX 1000

using namespace std;

vector<int> adj[MAX];
int visited[MAX];
int matched[MAX];
int n, m, visitCnt;

bool dfs(int i) {
	if (visited[i] == visitCnt) return false;

	visited[i] = visitCnt;
	for (auto j : adj[i]) {
		if (!matched[j] || dfs(matched[j])) {
			matched[j] = i;
			return true;
		}
	}

	return false;
}

int bipartite_matching() {
	int cnt = 0;
	visitCnt = 0;
	for (int i = 1; i <= n; ++i) {
		// visitCnt for veryfing each round
		++visitCnt;
		cnt += dfs(i);
	}

	return cnt;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	memset(visited, 0, sizeof(visited));
	memset(matched, 0, sizeof(matched));

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		// number of edges from "i"
		int p;
		cin >> p;
		for (int j = 0; j < p; ++j) {
			// add edge from "i" to "k"
			int k;
			cin >> k;
			adj[i].push_back(k);
		}
	}

	cout << bipartite_matching();

	return 0;
}
