#include <iostream>
#include <string>

using namespace std;

string ReadAstring() {

	string Words;

	cout << "Please Enter Your String ?" << endl;
	getline(cin, Words);

	return Words;
}

void PrintFirstLetterofEachWord(string s1) {

	bool isFirstLetter = true;

	cout << "\nFirst Letter of the string:\n";

	for (int i = 0; i < s1.length(); i++) {

		if (s1[i] != ' ' && isFirstLetter) {

			cout << s1[i] << endl;
		}

		isFirstLetter = (s1[i] == ' ' ? true : false);

	}
}

int main() {

	PrintFirstLetterofEachWord(ReadAstring());


	cout << "\nPress Enter to exit...";

	cin.get();

	return 0;
}