#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string ReadAString() {

	string S1;

	cout << "Please Enter Your String ? \n";
	getline(cin, S1);

	return S1;
}

char ReadChar() {

	char ch1;

	cout << "Please Enter a Character ? \n";
	cin >> ch1;

	return ch1;
}

short CountLetter(string S1, char ch1) {

	short CountLetter = 0;

	for (short i = 0; i < S1.length();i++) {

		if (S1[i] == ch1) {

			CountLetter++;
		}
	}

	return CountLetter;
}

int main() {

	string S1 = ReadAString();

	cout << "\n";

	char Letter = ReadChar();

	cout << "\nLetter \'" << Letter << "\' Count = " << CountLetter(S1, Letter) << endl;

	system("pause>0");

	return 0;
}