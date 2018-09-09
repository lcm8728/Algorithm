#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define MAX 401

// source = 1
// sink = 2
#define S 1
#define T 2

using namespace std;

vector<int> adj[MAX];
int c[MAX][MAX], f[MAX][MAX], parent[MAX];
int n, p;

int edmond_karp() {
	int cnt = 0;

	while (1) {
		memset(parent, -1, sizeof(parent));

		queue<int> que;
		que.push(S);
		while (!que.empty()) {
			int x = que.front();
			que.pop();

			for (auto y : adj[x]) {
				if (parent[y] == -1 && c[x][y] - f[x][y] > 0) {
					que.push(y);
					parent[y] = x;
				}
			}
		}

		if (parent[T] == -1) return cnt;

		for (int i = T; i != S; i = parent[i]) {
			f[parent[i]][i]++;
			f[i][parent[i]]--;
		}

		cnt++;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));

	cin >> n >> p;

	for (int i = 0; i < p; ++i) {
		int from, to;
		cin >> from >> to;

		// set capacity from "from" to "to"
		c[from][to] = 1; 
		c[to][from] = 1;

		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	cout << edmond_karp();

	return 0;
}
