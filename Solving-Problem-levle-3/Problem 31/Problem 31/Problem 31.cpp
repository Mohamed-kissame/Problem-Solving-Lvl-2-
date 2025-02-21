#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadAString() {

	string S1;

	cout << "Please Enter Your String ? \n";
	getline(cin, S1);

	return S1;
}

char ReadALetter() {

	char Letter;

	cout << "Please Enter a Character ? \n";
	cin >> Letter;

	return Letter;
}

char InvertLetter(char Letter) {

	return (isupper(Letter)) ? tolower(Letter) : toupper(Letter);
}

short CountLetter(string S1, char Letter , bool Matchcase = true) {

	short Counter = 0;

	for (short i = 0; i < S1.length();i++) {


		if (Matchcase) {

			if (S1[i] == Letter)

				Counter++;
		}
		else{

			if (tolower(S1[i]) == tolower(Letter))
				Counter++;
	    }
	}

	return Counter;
}


int main() {

	string S1 = ReadAString();

	cout << "\n";

	char Letter = ReadALetter();

	cout << "\nLetter \'" << Letter << "\' Count = " << CountLetter(S1, Letter) << endl;
	cout << "\nLetter \'" << Letter << " Or " << "\'" << InvertLetter(Letter)
		<< "\' Count = " << CountLetter(S1, Letter,false) << endl;


}