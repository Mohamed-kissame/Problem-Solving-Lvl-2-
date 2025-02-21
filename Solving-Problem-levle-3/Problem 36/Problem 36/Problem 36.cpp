#include <iostream>
#include <string>

using namespace std;

string ReadAString() {

	string s1;

	cout << "Plesae Enter Your String ?\n";
	getline(cin, s1);

	return s1;
}

short CountWord(string s1) {

	short Counter = 0;
	short Pos = 0;

	string space = " ";
	string  sWord ;

	while ((Pos = s1.find(space)) != std::string::npos) {

		sWord = s1.substr(0, Pos);

		if (sWord != "") {

			Counter++;
		}

		s1.erase(0, Pos + space.length());
	}

	if (s1 != "") {

		Counter++;
	}
	
	return Counter;


}

int main() {

	string s1 = ReadAString();

	cout << "\nThe number of words in tour string is : " << CountWord(s1) << endl;
}