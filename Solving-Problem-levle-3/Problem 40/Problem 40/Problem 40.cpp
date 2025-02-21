#include <iostream>
#include <vector>
#include <string>

using namespace std;

string JoinString(vector < string> vString , string Delim) {

	string S1 = "";

	for (string& s : vString) {

		S1 = S1 + s + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}

string JoinString(string arr[], short Lenght, string Delim) {

	string S1 = "";

	for (short i = 0; i < Lenght; i++) {

		S1 = S1 + arr[i] + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}

int main() {

	vector <string> vString = { "Mohamed","Kissame" };

	string arr[] = { "Mohamed","Kissame" };

	cout << "Vector After join: \n";
	cout << JoinString(vString, " ");

	cout << "\n\nArray After join: \n";
	cout << JoinString(arr,2, " ");

	system("pause>0");

}
