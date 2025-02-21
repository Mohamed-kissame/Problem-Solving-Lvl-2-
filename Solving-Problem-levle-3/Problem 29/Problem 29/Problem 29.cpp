#include <iostream>
#include <string>

using namespace std;

string ReadAString() {

	string s1;

	cout << "Please Enter Your String\n";
	getline(cin, s1);

	return s1;
}

short CountLengtOfString(string S1) {

	short Count = 0;

	for (short i = 0; i < S1.length(); i++) {

		Count++;
	}

	return Count;
}

short CountCapitalLetterInString(string S1) {

	short CountCapitalLetter = 0;

	for (short i = 0; i < S1.length();i++) {

		if (isupper(S1[i])) {

			CountCapitalLetter++;
		}
	}

	return CountCapitalLetter;
}

short CountSmallLetterInString(string S1) {

	short CountSmallLetter = 0;

	for (short i = 0; i < S1.length(); i++) {

		if (islower(S1[i])) {

			CountSmallLetter++;
		}
	}

	return CountSmallLetter;
}


int main() {

	string S1 = ReadAString();

	cout << "\nString Length = " << CountLengtOfString(S1) << endl;
	cout << "Capital Letters Count = " << CountCapitalLetterInString(S1) << endl;
	cout << "Small Letters Count =" << CountSmallLetterInString(S1) << endl;


	system("pause>0");

	return 0;
}