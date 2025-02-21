#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stClient {

	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance = 0;
};

vector <string> SplitString(string s1, string Delim) {

	vector <string> vString;
	short pos = 0;
	string sWord;

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

stClient ConvertLineToRecord(string s1) {

	stClient Clien;
	vector <string> vString = SplitString(s1, "#//#");

	Clien.AccountNumber = vString.at(0);
	Clien.PinCode = vString.at(1);
	Clien.Name = vString.at(2);
	Clien.Phone = vString.at(3);
	Clien.AccountBalance = stod(vString.at(4));

	return Clien;
}

void PrintClientRecord(stClient Clien) {

	cout << "\n\nThe following is the extracted client record :\n\n";

	cout << "Account Number: " << Clien.AccountNumber << endl;
	cout << "Pin Code      : " << Clien.PinCode << endl;
	cout << "Name          : " << Clien.Name << endl;
	cout << "Phone         : " << Clien.Phone << endl;
	cout << "Account Balance: " << Clien.AccountBalance << endl;

}

int main() {


	string Line = "A150#//#1234#//#Mohamed kissame#//#0675739888#//#5270.00000";

	cout << "Line Record is:\n";
	cout << Line;

	stClient Client = ConvertLineToRecord(Line);

	PrintClientRecord(Client);
}

