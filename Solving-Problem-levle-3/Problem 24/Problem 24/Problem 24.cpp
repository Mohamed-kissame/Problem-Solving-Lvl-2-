#include <cctype>
#include <string>
#include <iostream>

using namespace std;

string ReadAstring() {

	string s1;

	cout << "Please Enter Your String ?" << endl;
	getline(cin, s1);

	return s1;
}

string UppercaseFirstLetterinThestring(string s1) {

	
	bool isFirstLetter = true;

	for (short i = 0; i < s1.length(); i++) {

		if (s1[i] != ' ' && isFirstLetter) {

			s1[i] = toupper(s1[i]);

			
		}

		isFirstLetter = (s1[i] == ' ') ? true : false;

	}

	return s1;
}

int main() {

	
	string S1 = ReadAstring();

	cout << "\nString After conversion:\n";
	S1 = UppercaseFirstLetterinThestring(S1);

	cout << S1 << endl;

	return 0;
}