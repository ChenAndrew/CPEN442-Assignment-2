#include <string>
#include <iostream>
#include <set>
#include <map>
#include <utility>

using namespace std;
typedef pair<int, char> pic;
typedef pair<int, string> pis;

int len;
const string input = "HXUBNNYMKDRQDWHDSMDNBNXKDNDXKBXVBODLCXKDQHLSDDWNXKDNXYWOEVDSXKDEUDWDOLXXKDEBMZYHWDOKBFHXNLCKDWLHNVOLXXKDHWNHSDUNFDMBVDUHWEXKDHWSDWTDNXYWSDOXLNXDDJOLXXKDHWNDSNDNFDMBVDNKBWQDSDOOLXXKDEGWDUBJDWXMLVVBNXDBOEMLVVBQWLVQXBSOODCXHSDTDWEDVDWGDSMEOLXLCVLWODMBHJHSMLJSMLVVBXKDFLEUKLKBODRKHFHXDONYMKMLLJSDNNBSOOBWHSGLSXKDOBELCKHNCBXKDWNODBXKMLVVBVBSENXLWHDNBWDXLJOBCXDWKDWDBMKDOVBSKLLOOLXKDUBNSBXYWBJJEBVBSLCMLSNHODWBFJDGDSHYNMLVVBNBENLSDUKLASDUKHV";

map<char, char> replace_map;
void replace_mappings() {
	replace_map['D'] = 'E';
	replace_map['X'] = 'T';
	replace_map['B'] = 'A';
	replace_map['L'] = 'O';
	replace_map['N'] = 'S';
	replace_map['K'] = 'H';
	replace_map['W'] = 'R';
	replace_map['S'] = 'N';
	replace_map['O'] = 'D';
	replace_map['V'] = 'M';
	replace_map['H'] = 'I';
	replace_map['M'] = 'C';
	replace_map['E'] = 'Y';
	replace_map['U'] = 'W';
	replace_map['J'] = 'L';
	replace_map['C'] = 'F';
	replace_map['Y'] = 'U';
	replace_map['F'] = 'B';
	replace_map['Q'] = 'P';
	replace_map['G'] = 'G';
	replace_map['T'] = 'V';
	replace_map['R'] = 'X';
	replace_map['Z'] = 'Q';
	replace_map['A'] = 'K';
	replace_map['I'] = 'J';
	replace_map['P'] = 'Z';
}

string replace() {
	string out;
	for (int i = 0; i < input.size(); i++) {
		out += replace_map[input[i]];
	}
	return out;
}

set<pis> calculate_word_frequencies(int sz, string &input) {
	map<string, int> msi;
	for (int i = 0; i < len - sz + 1; i++) {
		msi[input.substr(i, sz)]++;
	}
	set<pis> res;
	for (auto c : msi) {
		res.insert(pis(c.second, c.first));
	}
	return res;
}

void print_frequencies(int n, string & replaced_string) {
	set<pis> spis = calculate_word_frequencies(n, replaced_string);
	cout << endl << n <<" Letter frequencies:" << endl;
	int j = 0;
	for (auto i = spis.rbegin(); j < 10; i++, j++) {
		auto c = *i;
		cout << c.second << "," << c.first << endl;
	}
}

int main() {
	len = input.size();
	map<char, int> mci;
	for (int i = 0; i < len; i++) {
		mci[input[i]]++;
	}
	set<pic> spic;
	for (auto c : mci) {
		spic.insert(pic(c.second, c.first));
	}
	for(auto i = spic.rbegin(); i != spic.rend(); i++){
		auto c = *i;
		cout << c.second << "," << c.first << endl;
	}
	replace_mappings();
	string replaced_string = replace();
	print_frequencies(2, replaced_string);
	print_frequencies(3, replaced_string);
	print_frequencies(4, replaced_string);
	print_frequencies(5, replaced_string);
	print_frequencies(6, replaced_string);

	cout << endl << replaced_string << endl;
 	return 0;
}