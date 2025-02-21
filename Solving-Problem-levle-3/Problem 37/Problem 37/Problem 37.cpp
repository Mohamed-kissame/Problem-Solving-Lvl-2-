#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadAstring(){

	string s1;
	cout << "Please Enter Your String ?\n";
	getline(cin, s1);
	return s1;
}

vector <string> SplitString(string s1, string Delim) {

	short pos = 0;
	string sWord = "";
	vector <string> vAdd;

	while ((pos = s1.find(Delim)) != std::string::npos) {

		sWord = s1.substr(0, pos);

		if (sWord != "") {

			vAdd.push_back(sWord);
		}

		s1.erase(0, pos + Delim.length());
	}

	if (s1 != "") {

		vAdd.push_back(s1);
	}

	return vAdd;
	
}

void PrintVectorElement(vector <string>& vElement) {

	cout << "\nTokens = " << vElement.size() << endl;

	for (string& sWord : vElement) {

		cout << sWord << endl;
	}
}

int main() {

	vector <string> vString;

	vString = SplitString(ReadAstring(), " ");

	PrintVectorElement(vString);

	system("pause>0");

	return 0;
}