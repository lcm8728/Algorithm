#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

#define MAX 500000

using namespace std;

char str[MAX];
int sfx[MAX];
int g[MAX + 1];
int ng[MAX + 1];
int cnt[257];
int order[257];
int n, t;

// compare by group
bool cmp(int &a, int &b) {
	if (g[a] == g[b]) {
		return g[a + t] < g[b + t];
	}
	else {
		return g[a] < g[b];
	}
}

void getSFX() {
	// initialize
	for (int i = 0; i < n; ++i) {
		sfx[i] = i;
		g[i] = str[i];
	}

	for (t = 1; t < n; t <<= 1) {
		// counting sort
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; ++i) cnt[g[min(i + t, n)] + 1]++;
		for (int i = 1; i < 257; ++i) cnt[i] += cnt[i - 1];
		for (int i = 0; i < n; ++i) order[cnt[g[min(i + t, n)]]++] = i;

		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; ++i) cnt[g[i] + 1]++;
		for (int i = 1; i < 257; ++i) cnt[i] += cnt[i - 1];
		for (int i = 0; i < n; ++i) sfx[cnt[g[order[i]]]++] = order[i];
		

		// assign new group
		ng[sfx[0]] = 1;
		ng[n] = 0;
		for (int i = 1; i < n; ++i) {
			if (cmp(sfx[i - 1], sfx[i]))
				ng[sfx[i]] = ng[sfx[i - 1]] + 1;
			else
				ng[sfx[i]] = ng[sfx[i - 1]];
		}


		// copy assigned group
		for (int i = 0; i < n; ++i)
			g[i] = ng[i];
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> str;
	n = strlen(str);

	getSFX();
	for (int i = 0; i < n; ++i) {
		cout << sfx[i] + 1 << " ";
	}
	cout << "\n";


	return 0;
}
