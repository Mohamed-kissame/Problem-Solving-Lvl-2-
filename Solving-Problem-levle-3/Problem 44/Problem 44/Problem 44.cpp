#include <iostream>
#include <string>

using namespace std;

string RemovePunctuation(string s1) {

	for (short i = 0; i < s1.length(); i++) {

		if (ispunct(s1[i])) {

			s1.erase(i,1);
		}
	}

	return s1;
}

int main() {

	string s1 = "Mohamed, kissame, yousse,";

	cout << "Orginal String :\n"
		<< s1 << endl;

	cout <<"\nPauncuations Remoed : \n" << RemovePunctuation(s1);

	system("pause>0");

}