#include <string>
#include <iostream>

using namespace std;

string TrimLeft(string s1) {


	for (short i = 0; i < s1.length();i++) {
        
		if (s1[i] != ' ') {

			return s1.substr(i, s1.length() - i);
		}
	}

	return "";
}

string trimRight(string s1) {

	for (short i = s1.length()-1; i >= 0;i--) {

		if (s1[i] != ' ') {

			return s1.substr(0, s1.length() + i);
		}
	}

	return "";
}

string Trim(string s1) {

	return TrimLeft(trimRight(s1));
}

int main() {

	string S1 = "      Mohamed kissame ";
	cout << "\nString      = " << S1;
	cout << "\n\nTrim left  = " << TrimLeft(S1);
	cout << "\nTrim Right  = " << trimRight(S1);
	cout << "\nTrim        = " << Trim(S1);

	system("pause>0");

	return 0;

}