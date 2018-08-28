#include <iostream>
#include <string>
#include <vector>

#define MAX 500000

using namespace std;

int pi[MAX] = { 0, };
string s;
string pattern;
vector<int> ans; 

void getpi() {
	int n = pattern.length();

	for (int i = 1, j = 0; i < n; ++i) {
		while (j > 0 && pattern[i] != pattern[j]) j = pi[j - 1];
		if (pattern[i] == pattern[j]) pi[i] = ++j;
	}
}

void kmp() {
	int n = s.length();
	int m = pattern.length();

	for (int i = 0, j = 0; i < n; ++i) {
		while (j > 0 && s[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (s[i] == pattern[j]) ++j;

		if (j == m) {
			ans.push_back(i - j + 1);
			j = pi[j - 1];
		}
	}
}

int main() {
	s = "abcabcabccabdabca";
	pattern = "abca";

	getpi();
	kmp();

	for (auto it = ans.begin(); it != ans.end(); ++it) {
		cout << *it << " ";
	}

	return 0;
}
