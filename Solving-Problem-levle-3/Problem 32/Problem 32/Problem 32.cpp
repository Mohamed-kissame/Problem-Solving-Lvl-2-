#include <iostream>
#include <cctype>
#include <string>

using namespace std;

char ReadAChar() {

	char Letter;

	cout << "Please Enter a Character ? \n";
	cin >> Letter;

	return Letter;
}

bool IsAVowelLetter(char Letter) {

	Letter = tolower(Letter);

	return (Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u');
}

int main() {

	char Letter = ReadAChar();

	if (IsAVowelLetter(Letter)) {

		cout << "\nYes Letter \'" << Letter << "\' is vowel";
	}
	else {

		cout << "\nLetter \'" << Letter << "\' is NOT a vowel";

	}

	system("pause>0");

	return 0;
}