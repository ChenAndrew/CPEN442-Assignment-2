#include "stdafx.h"
#include <map>
#include <boost/crc.hpp>
#include <string>
#include <time.h>
#include <iostream>
using namespace std;

//SIZE = 62
const string alphanumerics = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
string student_number = "b737731d82db7a2edf220f2185a346cc";
int values[6] = { 0 };

void increment() {
	for (int i = 5; i >= 0; i--) {
		if (values[i] != alphanumerics.size() - 1) {
			values[i]++;
			for (int j = i + 1; j < 6; j++) {
				values[j] = 0;
			}
			break;
		}
	}
}

int main() {
	string s(6, 'a');
	boost::crc_32_type crc;
	crc.process_bytes(student_number.data(), student_number.length());
	unsigned int student_number_checksum = crc.checksum();
	crc.reset();

	//random seed
	srand(time(NULL));
	while (true) {

		for (int i = 0; i < 6; i++) {
			s[i] = alphanumerics[values[i]];
		}
		crc.process_bytes(s.data(), s.length());
		unsigned int crc_checksum = crc.checksum();
		if (crc_checksum == student_number_checksum) {
			cout << "COLLISION :" << student_number << endl << s << endl << hex << crc_checksum << endl;
			break;
		}
		crc.reset();
		increment();
	}
	return 0;
}