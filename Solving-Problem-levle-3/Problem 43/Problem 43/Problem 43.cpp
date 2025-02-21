#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <string> SplitString(string s1, string Delim) {

	vector <string> vString;

	short pos = 0;

	string sWord ;

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

string JoinString(vector<string> vString, string Delim) {

	string S2 = "";

	for (string& s : vString) {

		S2 = S2 + s + Delim;
	}

	return S2.substr(0, S2.length() - Delim.length());
}

string LowerAllString(string s1) {

	for (short i = 0; i < s1.length(); i++) {

		s1[i] = tolower(s1[i]);
	}

	return s1;
}

string ReplaceWordInString(string s1, string StringToReplace, string sReplaceTo, bool MatchCase = true) {

	vector <string> vString = SplitString(s1, " ");

	for (string& s : vString) {

		if (MatchCase) {

			if (s == StringToReplace) {

				s = sReplaceTo;
			}
		}
		else
		{
			if (LowerAllString(s) == LowerAllString(StringToReplace)) {

				s = sReplaceTo;
			}
		}
	}

	return JoinString(vString, " ");
}

int main() {


		string S1 = "Welcome to Maroc , Maroc is a nice country";
		string StringToReplace = "maroc";
		string ReplaceTo = "USA";

		cout << "\nOriginal String:\n" << S1;
		cout << "\n\nReplace with match case: ";
		cout << "\n" << ReplaceWordInString(S1,
			StringToReplace, ReplaceTo);

		cout << "\n\nReplace with dont match case: ";
		cout << "\n" << ReplaceWordInString(S1,
			StringToReplace, ReplaceTo, false);

		system("pause>0");
}