#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string ReadAString() {

	string S1;

	cout << "Please Enter Your String?\n";
	getline(cin, S1);

	return S1;
}

bool IsVowel(char Letter) {

	Letter = tolower(Letter);

	return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));
}

void PrintAllVowelLetter(string S1) {

	cout << "\nVowels in string are : ";

	for (short i = 0; i < S1.length(); i++) {

		if (IsVowel(S1[i])) 

			cout << S1[i] << "   ";
		
	}

}

int main() {

	string S1 = ReadAString();

	PrintAllVowelLetter(S1);

	return 0;
}