#include <iostream>
#include <string>

using namespace std;

class trie {
private:
	trie *next[26];
	bool finish;
public:
	trie() {
		for (int i = 0; i < 26; ++i) next[i] = NULL;
		finish = false;
	}

	void insert(string s) {
		trie *curr = this;
		for (int i = 0; i < s.length(); ++i) {
			if (curr->next[s[i] - 'a'] == NULL)
				curr->next[s[i] - 'a'] = new trie;
			curr = curr->next[s[i] - 'a'];
		}
		
		curr->finish = true;
	}

	bool search(string s) {
		trie *curr = this;
		for (int i = 0; i < s.length(); ++i) {
			if (curr->next[s[i] - 'a'] == NULL) return false;
			curr = curr->next[s[i] - 'a'];
		}

		return curr->finish;
	}
};

int main() {
	trie tmp;
	
	while (1) {
		// insert string
		string s;
		cin >> s;
		if (s == "-1") break;
		tmp.insert(s);
	}

	while (1) {
		// search string
		string s;
		cin >> s;
		if (s == "-1") break;

		cout << "Searching \"" << s << "\"... : ";
		if (tmp.search(s)) cout << "yes";
		else cout << "no";
		cout << "\n";
	}



	return 0;
}
