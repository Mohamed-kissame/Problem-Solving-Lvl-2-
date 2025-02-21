#include <iostream>
#include <string>

using namespace std;

struct stClien {

	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

stClien ReadInfoClient() {

	stClien Clien;

	cout << "Please Enter Client Data :\n\n";

	cout << "Enter Account Number ? ";
	getline(cin, Clien.AccountNumber);
	
	cout << "Enter PinCode ? ";
	getline(cin,Clien.PinCode);

	cout << "Enter Name ? ";
	cin.ignore(1, '\n');
	getline(cin, Clien.Name);

	cout << "Enter Phone ? ";
	getline(cin, Clien.Phone);

	cout << "Enter AccountBalance ? ";
	cin >> Clien.AccountBalance;

	return Clien;

}

string ConvertDataToLine(stClien Clien, string seperator) {

	string stClientRecord = "";

   stClientRecord = Clien.AccountNumber + seperator
		+= Clien.PinCode + seperator
		+= Clien.Name + seperator
		+= Clien.Phone + seperator
		+= to_string(Clien.AccountBalance);

	return stClientRecord;
}

int main() {

	stClien Clien = ReadInfoClient();

	cout << "\n\nClien Record for Saving is : \n"
		<< ConvertDataToLine(Clien, "#//#");

	system("pause>0");

	return 0;
}