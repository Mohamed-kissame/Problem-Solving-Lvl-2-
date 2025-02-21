#include <iostream>
#include <cctype>
#include <string>

using namespace std;

char ReadACharacter() {

	char Letter;

	cout << "Please Enter a Character ?\n";
	cin >> Letter;

	return Letter;
}

char Invertcase(char Letter) {

	return isupper(Letter) ? tolower(Letter) : toupper(Letter);
}

void PrintInvertCase() {

	char Letter = ReadACharacter();

	Letter = Invertcase(Letter);
	cout << "\nChar After Inverting Case:\n";
	cout << Letter << endl;
}

int main() {

	PrintInvertCase();

	return 0;
}
