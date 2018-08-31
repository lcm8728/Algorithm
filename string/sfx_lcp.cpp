#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

#define MAX 500000

using namespace std;

vector<int> getsfxarr(const char* str) {
	int n = strlen(str);
	int lim = max(n + 1, 257);
	vector<int> sfx(n, 0);
	vector<int> grp(n + 1, 0);
	vector<int> tmp_grp(n + 1, 0);
	vector<int> order(n, 0);
	vector<int> cnt;
	

	for (int i = 0; i < n; ++i) {
		sfx[i] = i;
		// group by first character of suffix
		grp[i] = str[i] - 'a' + 1;
	}

	for (int t = 1; t < n; t <<= 1) {
		// count sort
		cnt.clear();
		cnt.resize(lim, 0);
		for (int i = 0; i < n; ++i) cnt[grp[min(i + t, n)] + 1]++;
		for (int i = 1; i < lim; ++i) cnt[i] += cnt[i - 1];
		for (int i = 0; i < n; ++i) order[cnt[grp[min(i + t, n)]]++] = i;

		cnt.clear();
		cnt.resize(lim, 0);
		for (int i = 0; i < n; ++i) cnt[grp[i] + 1]++;
		for (int i = 1; i < lim; ++i) cnt[i] += cnt[i - 1];
		for (int i = 0; i < n; ++i) sfx[cnt[grp[order[i]]]++] = order[i];


		// make new group
		tmp_grp[sfx[0]] = 1;
		for (int i = 1; i < n; ++i) {
			if (grp[sfx[i - 1]] < grp[sfx[i]] ||
			   (grp[sfx[i - 1]] == grp[sfx[i]] && grp[sfx[i - 1] + t] < grp[sfx[i] + t]))
				tmp_grp[sfx[i]] = tmp_grp[sfx[i - 1]] + 1;
			else
				tmp_grp[sfx[i]] = tmp_grp[sfx[i - 1]];
		}

		grp = tmp_grp;
	}

	return sfx;
}

vector<int> getLCP(vector<int> &sfx, const char* str) {
	int n = sfx.size();
	vector<int> prevsfx(n, -1);
	vector<int> tmp(n);
	vector<int> lcp(n);

	for (int i = 1; i < n; ++i) prevsfx[sfx[i]] = sfx[i - 1];
	// get lcp by string index
	for (int i = 0, cnt = 0; i < n; ++i) {
		if (prevsfx[i] == -1) tmp[i] = -1;
		else {
			while (str[i + cnt] == str[prevsfx[i] + cnt]) cnt++;
			tmp[i] = cnt;
			cnt = max(cnt - 1, 0);
		}
	}
	for (int i = 0; i < n; ++i) lcp[i] = tmp[sfx[i]];

	return lcp;
}

int main() {
	char str[MAX];
	cin >> str;

	vector<int> sfx = getsfxarr(str);
	cout << "Suffix array of \'" << str << "\' :\n";
	for (auto it : sfx) cout << it << " ";
	cout << "\n";

	vector<int> lcp = getLCP(sfx, str);
	cout << "LCP of \'" << str << "\' :\n";
	for (auto it : lcp) cout << it << " ";
	cout << "\n";

	return 0;
}
