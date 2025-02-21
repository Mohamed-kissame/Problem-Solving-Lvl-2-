#include <cctype>
#include <string>
#include <iostream>

using namespace std;

string ReadAString() {

	string s1;

	cout << "Please Enter Your String ? " << endl;
	getline(cin, s1);

	return s1;
}

string LowerLetterofString(string s1) {

	bool isFirstLetter = true;

	for (short i = 0; i < s1.length(); i++) {

		if (s1[i] != ' ' && isFirstLetter) {

			s1[i] = tolower(s1[i]);
		}

		isFirstLetter = ( s1[i] == ' ' ? true : false);
	}

	return s1;
}

void PrintLowerLetterOfString() {

	string s1 = ReadAString();

	cout << "\nString after conversion:\n";

	s1 = LowerLetterofString(s1);

	cout << s1 << endl;
}

int main() {

	PrintLowerLetterOfString();

	system("pause>0");

	return 0;
}