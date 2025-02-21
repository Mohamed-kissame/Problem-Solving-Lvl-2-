#include <iostream>
#include <vector>
#include <string>

using namespace std;

string ReadAString() {

	string s1;

	cout << "Please Enter Your String? \n";
	getline(cin, s1);

	return s1;
}

vector <string> SplitString(string s1,string Delim) {

	vector <string> vString;

	short pos = 0;

	string sWord = "";

	while ((pos = s1.find(Delim)) != std::string::npos) {

		sWord = s1.substr(0, pos);

		if (sWord != "") {

			vString.push_back(sWord);
		}

		s1.erase(0, pos + Delim.length());
	 }

	if (s1 != "") {

		vString.push_back(s1);
	}

	return vString;
}

string ReverseWordsInString(string s1) {

	vector <string> vString;

	string S2 = "";

	vString = SplitString(s1, " ");

	vector <string>::iterator iter = vString.end();

	while (iter != vString.begin()) {

		--iter;

		S2 += *iter + " ";
	}

	S2 = S2.substr(0,S2.length()-1);

	return S2;

}

int main() {

	string s1 = ReadAString();

	cout << "\n\nString after reversing words:";
	cout << "\n" << ReverseWordsInString(s1);

	system("pause>0");
}