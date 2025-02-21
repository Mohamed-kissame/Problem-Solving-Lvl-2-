#include <iostream>
#include <string>

using namespace std;

string ReadAString() {

	string S1;

	cout << "Please Enter Your String?\n";
	getline(cin, S1);

	return S1;
}

void PrintEachWordOfString(string s1) {


	string delim = " ";
	short pos = 0;
	string sWords;

	cout << "\nYour String Words are:\n";

	while ((pos = s1.find(delim)) != std::string::npos) {

		sWords = s1.substr(0, pos);

		if (sWords != "") {

			cout << sWords << endl;
		}

		s1.erase(0, pos + delim.length());
	}
	
	if (s1 != "") {

		cout << s1 << endl;
	}
	
}

int main() {

	PrintEachWordOfString(ReadAString());

	system("pause>0");
}