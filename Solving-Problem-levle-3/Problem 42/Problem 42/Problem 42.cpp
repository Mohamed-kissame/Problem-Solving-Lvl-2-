#include <iostream>
#include <string>

using namespace std;

string ReaplaceWordInString(string s1, string StringToReplace, string ReplaceTo) {

	short pos = s1.find(StringToReplace);

	for (short i = 0; i < s1.length(); i++) {

		if (pos != std::string::npos) {

			s1 = s1.replace(pos, StringToReplace.length(),ReplaceTo);

			pos = s1.find(StringToReplace);
		}
	}

	return s1;
}

int main() {

	string S1 = "Welcom to Maroc , Maroc is a Nice country";
	string StringToReplace = "Maroc";
	string ReplaceTo = "USA";

	cout << "\nOrginal String\n" << S1;
	cout << "\n\nString After Replace:";
	cout << "\n" << ReaplaceWordInString(S1, StringToReplace, ReplaceTo);

	system("pause>0");
}