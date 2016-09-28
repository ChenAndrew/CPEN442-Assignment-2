#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

char grid[5][5];
const string alphabet = "abcdefghiklmnopqrstuvwxyz";

void build_grid(string &key) {
	bn 
}

void generate_combos(int n, int k, vector<string> &keys) {
	char key[26];
	for (int i = 0; i < k; i++) key[i] = i;
	while (key[k - 1] < n) {
		string s;
		for (int i = 0; i < k; i++)
			s += alphabet[key[i]];
		keys.push_back(s);

		int t = k - 1;
		while (t != 0 && key[t] == n - k + t) t--;
		key[t]++;
		for (int i = t + 1; i < k; i++) key[i] = key[i - 1] + 1;
	}
}

int main() {
	// i = keysize
	for (int i = 1; i < 26; i++) {
		vector<string> keys;
		generate_combos(25, i, keys);
		for (auto key : keys) {
			do {
				build_grid(key);
				cout << key << endl;
			} while (next_permutation(key.begin(), key.end()));
		}
	}
}