#include "stdafx.h"
#include <map>
#include <boost/crc.hpp>
#include <string>
#include <time.h>
#include <iostream>
using namespace std;

//SIZE = 62
const string alphanumerics = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
int main() {
	string s(100, 'a');
	map<unsigned int, string> check;
	boost::crc_32_type crc;
	srand(time(NULL));
	while (true) {
		for (int i = 0; i < 100; i++) {
			s[i] = alphanumerics[rand() % alphanumerics.size()];
		}
		crc.process_bytes(s.data(), s.length());
		unsigned int crc_checksum = crc.checksum();
		if (check.count(crc_checksum)) {
			cout << "COLLISION :" << check[crc_checksum] << endl << s << endl << hex << crc_checksum << endl;
			break;
		}
		check[crc_checksum] = s;
		crc.reset();
	}
	return 0;
}