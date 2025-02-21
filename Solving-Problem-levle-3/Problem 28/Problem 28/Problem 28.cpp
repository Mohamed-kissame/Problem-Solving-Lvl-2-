#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadAString() {

	string s1;

	cout << "Please Enter Your String ?\n";
	getline(cin, s1);

	return s1;
}

char InvertChar(char ch1) {

	return isupper(ch1) ? tolower(ch1) : toupper(ch1);
}

string InvertCharOfString(string s1) {

	for (short i = 0; i < s1.length(); i++) {

		s1[i] = InvertChar(s1[i]);
	}

	return s1;
}

void PrintInvertdCharOfString() {

	string s1 = ReadAString();

	s1 = InvertCharOfString(s1);
	cout << "\nString After Inverting All Letters Case:\n";
	cout << s1 << endl;
}

int main() {

	PrintInvertdCharOfString();

	system("pause>0");

	return 0;
}
