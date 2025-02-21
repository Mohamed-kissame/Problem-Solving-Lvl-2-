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

bool isVowel(char Letter) {

	Letter = tolower(Letter);

	return (Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u');
}

short CountVowelsLetters(string S1) {

	short CountVowels = 0;

	for (short i = 0; i < S1.length();i++) {

		if (isVowel(S1[i])) {

			CountVowels++;
		}
	}

	return CountVowels;
}

int main() {

	string S1 = ReadAString();
	

	cout << "\nNumber of vowels is : " << CountVowelsLetters(S1) <<endl;

	system("pause>0");

	return 0;
}