#include <iostream>
#include <string>

using namespace std;

string ReadAString() {

	string S1;

	cout << "Please Enter Your String ? \n";
	getline(cin, S1);

	return S1;
}

string UpperAllLetterOfString(string s1) {

	for (short i = 0; i < s1.length(); i++) {

		s1[i] = toupper(s1[i]);
	}

	return s1;
}

string LowerAllLetterOfString(string s1) {

	for (short i = 0; i < s1.length(); i++) {

		s1[i] = tolower(s1[i]);
	}

	return s1;
}

void PrintUpperLowerAllLetterString() {

	string s1 = ReadAString();

	cout << "\nString after Upper:\n";
	s1 = UpperAllLetterOfString(s1);
	cout << s1 << endl;

	cout << "\nString after Lowwer:\n";
	s1 = LowerAllLetterOfString(s1);
	cout << s1 << endl;
}

int main() {

	PrintUpperLowerAllLetterString();

	system("pause>0");

	return 0;
}